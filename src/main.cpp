#include <Arduino.h>
#include <GyverRGB.h>
#define led_onboard 13
#define led_1_R 5
#define led_1_G 6
#define led_1_B 3
GRGB led_1(5, 6, 3);

int a = 1;


void handleLoop()
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
}

void countAndReportLoopCompleted() {
  Serial.print("RGB-Loop completed ");
  Serial.print(a);
  Serial.println(" times.");
  digitalWrite(led_onboard, HIGH);
  delay(100);
  digitalWrite(led_onboard, LOW);
  delay(100);
  ++a;
}



void setup()
{
  pinMode(led_onboard, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led_onboard, HIGH);
  delay(100);
  digitalWrite(led_onboard, LOW);
  delay(100);
  led_1.fadeTo(RED, 5000);
  led_1.fadeTo(GREEN, 5000);
  led_1.fadeTo(BLUE, 5000);
  led_1.fadeTo(BLACK, 5000);
  digitalWrite(led_onboard, HIGH);
  delay(100);
  digitalWrite(led_onboard, LOW);
  delay(100);
  handleLoop();
  countAndReportLoopCompleted();
}
