int encPin1 = 2; //Left turn of encoder to digital pin 2
int encPin2 = 3; //Right turn of encoder to digital pin 3
int SencPin = 4; //Push Encoder switch to digital pin 4
int ledPin = 13; // onboard LED for validation
int redPin = 9; // Red LED, connected to digital pin 9
int grnPin = 10; // Green LED, connected to digital pin 10
int bluPin = 11; // Blue LED, connected to digital pin 11
// Define Variables
int stateNum = 0; // current State number
int buttonState = 0; // current state of the button
int lastButtonState = 0; // previous state of the button
int redVal = 0; // Variables to store the values to send to the pins
int grnVal = 0;
int bluVal = 0;
int RGBVal = 0; //Value for RGB Blend
static boolean moving = false;
volatile int encVal = 0;
unsigned int lastEncVal = 1;
boolean enc1 = false;
boolean enc2 = false;
 
void setup()
{
//Define Inputs
pinMode(ledPin, OUTPUT);
pinMode(redPin, OUTPUT);
pinMode(grnPin, OUTPUT);
pinMode(bluPin, OUTPUT);
pinMode(encPin1, INPUT);
pinMode(encPin2, INPUT);
pinMode(SencPin, INPUT);
//Turn on resistors for encoder/switch
digitalWrite(encPin1, HIGH);
digitalWrite(encPin2, HIGH);
digitalWrite(SencPin, HIGH);
Serial.begin(9600); //Start Logging
//encoder interrupts
attachInterrupt(0, intrEncChange1, CHANGE);
attachInterrupt(1, intrEncChange2, CHANGE);
}
 
void intrEncChange1() //Read on interrupt Right turn - Fast +4
{
if(moving)
delay(1);
if(digitalRead(encPin1) == enc1)
return;
enc1 = !enc1;
if(enc1 && !enc2)
encVal += 4;
moving = false;
}
 
void intrEncChange2() //Read on interrupt Left turn - Slow -2
{
if(moving)
delay(1);
if(digitalRead(encPin2) == enc2)
return;
enc2 = !enc2;
if(enc2 && !enc1)
encVal -= 2;
moving = false;
}
 
void loop()
{
{
buttonState = digitalRead(SencPin); //Read Button state
if (buttonState != lastButtonState) //Compare to last state
{
if (buttonState == HIGH) //If button is pushed, incriment stateNum and blink onboard LED
{
stateNum++;
if (stateNum > 8) stateNum = 0; //Defines and loops Number of possible states
Serial.println("on");
Serial.print("State Number: ");
Serial.println(stateNum);
digitalWrite(ledPin, HIGH);
}
else
{
Serial.println("off");
digitalWrite(ledPin, LOW);
}
 
lastButtonState = buttonState;
} //update button state to loop
//delay(20); //Delay to avoid bounce
}
if (encVal > 255) encVal = 0; //Loop Values
if (encVal < 0) encVal = 255;
if (encVal != lastEncVal) //Compare to previous pot value
{
lastEncVal = encVal; //Update encVal to reflect new value
Serial.print("Encoder Value: ");
Serial.println(encVal);
digitalWrite(ledPin, HIGH); //Blink onboard LED
}
else
{
digitalWrite(ledPin, LOW);
//delay(100); //Delay to avoid bounce
}
 
//Begin States section
 
if (stateNum == 0) //All LEDs make white, off to brightest
{
Serial.println("0 White");
grnVal = 255 - encVal; //Common Anode LED means inverse values
bluVal = 255 - encVal;
redVal = 255 - encVal;
}
else if (stateNum == 1) //Blend Green to Blue
{
Serial.println("1 Green to Blue");
grnVal = encVal;
bluVal = 255 - encVal;
redVal = 255;
}
else if (stateNum == 2) //Blend Blue to Red
{
Serial.println("2 Blue to Red");
bluVal = encVal;
redVal = 255 - encVal;
grnVal = 255;
}
else if (stateNum == 3) //Blend Red to Green
{
Serial.println("3 Red to Green");
redVal = encVal;
grnVal = 255 - encVal;
bluVal = 255;
}
else if (stateNum == 4) //Blend RGB
{
Serial.println("4 Blend All R-G-B-R");
if (encVal < 86) // Lowest third of range (0-85)
{
RGBVal = (encVal * 3) ; // Normalize to 0-255
 
redVal = RGBVal; // Red from full to off
grnVal = 255 - RGBVal; // Green from off to full
bluVal = 255; // Blue off
}
else if (encVal < 171) // Middle third of range (86-170)
{
RGBVal = ( (encVal - 86) * 3); // Normalize to 0-255
 
redVal = 255; // Red off
grnVal = RGBVal; // Green from full to off
bluVal = 255 - RGBVal; // Blue from off to full
}
else // Upper third of range (171-255)
{
RGBVal = ( (encVal - 171) * 3); // Normalize to 0-255
 
redVal = 255 - RGBVal; // Red from off to full
grnVal = 255; // Green off
bluVal = RGBVal; // Blue from full to off
}
}
else if (stateNum == 5) //Red Dim
{
Serial.println("5 Red Dim");
redVal = 255 - encVal;
grnVal = 255;
bluVal = 255;
}
else if (stateNum == 6) //Green Dim
{
Serial.println("6 Green Dim");
redVal = 255;
grnVal = 255 - encVal;
bluVal = 255;
}
else if (stateNum == 7) //Blue Dim
{
Serial.println("7 Blue Dim");
redVal = 255;
grnVal = 255;
bluVal = 255 - encVal;
}
else if (stateNum == 8) //Purple Dim
{
Serial.println("8 Purple Dim");
redVal = 255 - encVal;
grnVal = 255;
bluVal = 255 - encVal;
}
 
//Send results to LEDs
analogWrite(redPin, redVal);
analogWrite(grnPin, grnVal);
analogWrite(bluPin, bluVal);
}
