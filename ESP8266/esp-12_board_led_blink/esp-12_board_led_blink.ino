void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // blink first led with output
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); //Glow LED
  delay(1000); //wait for 1 second
  digitalWrite(LED_BUILTIN, LOW); //Dim  LED
  delay(1000); //waitfor 1 second  
  }
