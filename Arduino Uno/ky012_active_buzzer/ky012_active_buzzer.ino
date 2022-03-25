int buzzerPin = 10;
int j=1;
int dt=1000;
void setup ()
{
  pinMode (buzzerPin, OUTPUT);
}
void loop ()
{
  analogWrite (buzzerPin, 255);
  delay (dt);
  digitalWrite (buzzerPin, LOW);
  delay (dt);
}
