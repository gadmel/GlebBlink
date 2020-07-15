#include <Arduino.h>
#define led_onboard 13
#define led_1_R 5
#define led_1_G 6
#define led_1_B 3

int a = 1;
void setup()
{
  pinMode(led_onboard, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(led_onboard, HIGH);
  delay(100);
  digitalWrite(led_onboard, LOW);
  delay(100);
  digitalWrite(led_1_R, HIGH);
  delay(1000);
  digitalWrite(led_1_R, LOW);
  digitalWrite(led_1_G, HIGH);
  delay(1000);
  digitalWrite(led_1_G, LOW);
  digitalWrite(led_1_B, HIGH);
  delay(1000);
  digitalWrite(led_1_B, LOW);
  delay(1000);
  digitalWrite(led_onboard, HIGH);
  delay(100);
  digitalWrite(led_onboard, LOW);
  delay(100);
  Serial.print("RGB-Loop completed ");
  Serial.print(a);
  Serial.println(" times.");
  ++a;
}