int buzzerPin = 10;
int j=1;
int dt=100;
void setup ()
{
  pinMode (buzzerPin, OUTPUT);
}
void loop ()
{
  analogWrite (buzzerPin, 125);
  delayMicroseconds(dt);
  digitalWrite (buzzerPin, LOW);
  delayMicroseconds(dt);
}
