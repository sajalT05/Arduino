// for Arduino microcontroller
//int analogPin = A0; 
//int digitalPin = 8;

// for ESP8266 microcontroller
int analogPin = A0; 
int digitalPin = D0;

// for ESP32 microcontroller
//int analogPin = 4; 
//int digitalPin = 2;

void setup() {
  pinMode(analogPin, INPUT); 
  pinMode(digitalPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  int analogVal = analogRead(analogPin);
  int digitalVal = digitalRead(digitalPin);
  
  Serial.print(analogVal);
  Serial.print(" - ");
  Serial.println(digitalVal);
  
  delay(100);
}
