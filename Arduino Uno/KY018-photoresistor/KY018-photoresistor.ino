int pin=A0;
int value;
int dt=1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(pin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value=analogRead(pin);
Serial.println(value);
if(value>300){digitalWrite(6,1);digitalWrite(5,0);}
else{digitalWrite(5,1);digitalWrite(6,0);}
delay(dt);
}
