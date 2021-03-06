/*******************************
           Connection:
             VCC-5V
             GND-GND
             S-Analog pin 0

 You can put the sensor on your palm,
 it may sense the humidity of your palm
 ********************************/
int pin=0;

void setup()
{
  Serial.begin(9600);// open serial port, set the baud rate to 9600 bps
  pinMode(pin,INPUT);
}
void loop()
{
  int sensorValue;
  sensorValue = analogRead(pin);   //connect Steam sensors to Analog 0
  Serial.println(sensorValue); //print the value to serial
  delay(200);
}
