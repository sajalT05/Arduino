int pin=2;
String msg = "Enter 'red' command";
String command;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
Serial.println(msg);
while(Serial.available()==0){}
command=Serial.readString();
if(command=="red")Serial.println("Command Successfull");
digitalWrite(pin,HIGH);
}
