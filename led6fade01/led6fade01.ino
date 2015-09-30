int ledPins[] = { 3, 5, 6, 9, 10, 11 };
int pinCount = 6;
int ledFade[6];
int i;
int prevTime;
int interval = 500;
int fadeSpeed = 5;
int prevFadeTime;
void setup() {
  /*
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
  */
  Serial.begin(9600);
  Serial.println();
  Serial.println("Begin");
}

void loop() {

  int currentTime = millis();
  if (currentTime - prevTime >= interval) {
    ledFade[i] = 255;
    i++;
    if (i == 6) {
      i = 0;
    }
    prevTime = currentTime;
    Serial.println(currentTime);
    for (int n = 0; n < pinCount; n++) {
      Serial.print(n + 1);
      Serial.print("\t");
      Serial.println(ledFade[n]);
    }
  }

  if (currentTime - prevFadeTime >= fadeSpeed) {
    for (int n = 0; n < pinCount; n++) {
      if (ledFade[n] >= 1) {
        ledFade[n] = ledFade[n]-1;
      }
    }
    prevFadeTime = currentTime;
  }

    // display section:
    for (int n = 0; n < pinCount; n++) {
      analogWrite(ledPins[n], ledFade[n]);
    }
 
}

