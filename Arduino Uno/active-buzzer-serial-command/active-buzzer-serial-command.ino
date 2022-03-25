int pin = 0;
String msg="Enter any number between 1 to 10";
int num=0;
int dt=1000;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pin, LOW);
  
Serial.println(msg);
while(Serial.available()==0){}
num=Serial.parseInt();
for(num=0;num<=10;num++){
  digitalWrite(pin, HIGH);
  delay(dt);
  digitalWrite(pin, LOW);
  delay(dt);
}

}
