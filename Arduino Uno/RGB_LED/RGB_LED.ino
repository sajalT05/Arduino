int redPin=7;
int greenPin=6;
int bluePin=5;

void setup() {
  // put your setup code here, to run once:
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(redPin, 255);
digitalWrite(greenPin, 125);
digitalWrite(bluePin, 125); 
}
