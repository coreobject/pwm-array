#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4, 2);
int leds[] = { 3, 5, 6, 9, 10, 11};
int pinCount = 6;
int ledFade[6];
int ledPin = 13;
int i;
int prevTime;
int interval = 500;
int fadeSpeed = 5;
int prevFadeTime;

void setup() {
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(leds[thisPin], OUTPUT);
  }
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println();
  Serial.println("Begin");
}




void loop() {
  int  total1 = touchSense();
  debug(total1);


  int currentTime = millis();
  if (currentTime - prevTime >= interval) {
    ledFade[i] = 255;
    i++;
    if (i == 6) {
      i = 0;
    }
    prevTime = currentTime;
  }

  
  fade();
  
  display();
}

