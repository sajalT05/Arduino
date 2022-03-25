//int Buzzer = 6;        // used for Arduino
//int Fire_analog = A0;    // used for Arduino
//int Fire_digital = 7;   // used for Arduino

int Buzzer = D2;        // used for ESP8266
int Fire_analog = A0;    // used for ESP8266
int Fire_digital = D1;   // used for ESP8266

//int Buzzer = 32;        // used for ESP32
//int Fire_analog = 4;    // used for ESP32
//int Fire_digital = 2;   // used for ESP32

void setup() {
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);      
  pinMode(Fire_digital, INPUT);
}

void loop() {
  int firesensorAnalog = analogRead(Fire_analog);
  int firesensorDigital = digitalRead(Fire_digital);

  Serial.print("Fire Sensor: ");
  Serial.print(firesensorAnalog);
  Serial.print("\t");
  Serial.print("Fire Class: ");
  Serial.print(firesensorDigital);
  Serial.print("\t");
  Serial.print("\t");
  
  if (firesensorAnalog < 1000) {
    Serial.println("Fire");
    digitalWrite (Buzzer, HIGH) ; //send tone
    delay(1000);
    digitalWrite (Buzzer, LOW) ;  //no tone
  }
  else {
    Serial.println("No Fire");
  }
  delay(100);
}
