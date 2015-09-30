int ledPins[] = { 3, 5, 6, 9, 10, 11 };
int pinCount = 6;
int ledFade[6];
int i;
int prevTime;
int interval = 500;
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
    if (ledFade[i] == 0) {
      ledFade[i] = 1;
    } else {
      ledFade[i] = 0;
    }
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

  for (int n = 0; n < pinCount; n++) {
    digitalWrite(ledPins[n], ledFade[n]);
  }
}

