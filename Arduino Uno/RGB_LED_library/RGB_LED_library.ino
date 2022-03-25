#include <RGBLed.h>
int redPin=8;         // Set red LED pin to 8
int greenPin=10;       // Set green LED pin to 9
int bluePin=9;         // Set blue LED pin to 10
int bright = 255;  // Set brightness to full
int dim = 0;           // Set dimness
String msg = "Please input your color choice:"; //Message to be displayed
String prompt = "Your colour is ";
String color;    // Set up variable to hold user input


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  setColor(255, 0, 0); // Red Color
  delay(1000);
  setColor(0, 255, 0); // Green Color
  delay(1000);
  setColor(0, 0, 255); // Blue Color
  delay(1000);
  setColor(255, 255, 255); // White Color
  delay(1000);
  setColor(170, 0, 255); // Purple Color
  delay(1000);
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
