//int analogPin = A0; // for Arduino microcontroller
int analogPin = A0; // for ESP8266 microcontroller
//int analogPin = A4; // for ESP32 microcontroller

//int digitalPin = 7; // for Arduino microcontroller
int digitalPin = D7; // for ESP8266 microcontroller
//int digitalPin = 0; // for ESP32 microcontroller

void setup() {
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogVal = analogRead(analogPin);
  int digitalVal = digitalRead(digitalPin);
  Serial.print(analogVal);
  Serial.print("\t");
  Serial.println(digitalVal);
  delay(100);
}
