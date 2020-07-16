#include <Arduino.h>
#include <GyverRGB.h>
#include <math.h> 
#define led_onboard 13
#define led_1_R 5
#define led_1_G 6
#define led_1_B 3
GRGB led_1(5, 6, 3);

int potentiometer_1 = A3;
int potentiometer_2 = A5;
int potentiometer_3 = A7;

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

void handleFadeLoop() {
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
}


void setup()
{
  // value_1 = analogRead(potentiometer_1);
  pinMode(led_1_R, OUTPUT); 
  pinMode(led_1_G, OUTPUT); 
  pinMode(led_1_B, OUTPUT); 
  pinMode(led_onboard, OUTPUT);
  Serial.begin(9600);
}

  int value_R;
  int value_G;
  int value_B;

void loop() {  
  value_R = map(analogRead(potentiometer_1), 0, 1023, 0, 255); 
  value_G = map(analogRead(potentiometer_2), 0, 1023, 0, 255); 
  value_B = map(analogRead(potentiometer_3), 0, 1023, 0, 255); 
  value_R = round(value_R /10* 4)/4;
  digitalWrite(led_1_R, value_R);
  digitalWrite(led_1_G,value_G);
  digitalWrite(led_1_B, value_B);
  Serial.print("Value of RGB is: (");
  Serial.print(value_R);
  Serial.print(", ");
  Serial.print(value_G);
  Serial.print(", ");
  Serial.println(value_B);
  Serial.print(")");
  // handleFadeLoop();
  // handleLoop();
  // countAndReportLoopCompleted();
}
