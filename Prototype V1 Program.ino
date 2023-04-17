const int motorA = 5;
const int motorB = 6;

void setup()
{
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
}

void loop(){
  analogWrite(motorA, 255);
  digitalWrite(motorB, LOW);
  delay(4000);
  digitalWrite(motorB, HIGH);
  delay(4000);
}



