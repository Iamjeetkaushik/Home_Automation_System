#include<Servo.h>

Servo window;

int window_pin = 9;
int photores_pin = 0;
int led_pin = 8;

void setup()
{
  analogReference(DEFAULT);
  pinMode(led_pin, OUTPUT);
  window.attach(window_pin);
  Serial.begin(9600);
}


void loop()
{
  int light = analogRead(photores_pin);
  int rotate = map(light, 0, 1023, 90, 0);
  window.write(rotate);
  
  
  int brightness = map(light, 450, 1023, 0, 255);
  analogWrite(led_pin, brightness);
  
  Serial.println(analogRead(photores_Pin));
  delay(500);
}
