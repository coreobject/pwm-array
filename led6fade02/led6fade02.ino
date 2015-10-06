int ledPins[] = { 3, 5, 6, 9, 10, 11};
int pinCount = 6;
int ledFade[6];
int i;
int directionFlag;
int prevTime;
int interval = 500;
int fadeSpeed = 5;
int prevFadeTime;
void setup() {

  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }

  Serial.begin(9600);
  Serial.println();
  Serial.println("Begin");
}

void loop() {

  int currentTime = millis();
  if (currentTime - prevTime >= interval) {
    ledFade[i] = 255;
    if (directionFlag == 0) {
      i++;
      if (i == 5) {
        directionFlag = 1;
        i = 5;
      }
    } else {
      i--;
      if (i < 0) {
        directionFlag = 0;
        i = 1;
      }
    }
    prevTime = currentTime;
    /*
     Serial.println(currentTime);
     for (int n = 0; n < pinCount; n++) {
       Serial.print(n + 1);
       Serial.print("\t");
       Serial.println(ledFade[n]);
     }
      */
  }

  if (currentTime - prevFadeTime >= fadeSpeed) {
    for (int n = 0; n < 6; n++) {
      if (ledFade[n] >= 1) {
        ledFade[n] = ledFade[n] - 1;
      }
    }
    prevFadeTime = currentTime;
  }

  // display section:
  for (int n = 0; n < 6; n++) {
    /*
    Serial.print(n);
    Serial.print("\t");
    Serial.print(ledPins[n]);
    Serial.print("\t");
    Serial.println(ledFade[n]);
    */
    analogWrite(ledPins[n], ledFade[n]);
  }
  /*
  Serial.print(ledFade[0]);
        Serial.print("\t");
    Serial.print(ledFade[1]);
              Serial.print("\t");
    Serial.print(ledFade[2]);
              Serial.print("\t");
    Serial.print(ledFade[3]);
              Serial.print("\t");
    Serial.print(ledFade[4]);
              Serial.print("\t");
    Serial.println(ledFade[5]);
  */
}

