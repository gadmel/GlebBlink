#include <Arduino.h>
#define onboard 13

int a = 1;
void setup()
{
  pinMode(onboard, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(onboard, LOW);
  delay(3000);
  digitalWrite(onboard, HIGH);
  delay(1000);
  Serial.print("Loop completed ");
  Serial.print(a);
  Serial.println(" times.");
  ++a;
}