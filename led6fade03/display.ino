int fade(){
    int currentTime = millis();
   if (currentTime - prevFadeTime >= fadeSpeed) {
    for (int n = 0; n < 6; n++) {
      if (ledFade[n] >= 1) {
        ledFade[n] = ledFade[n] - 1;
      }
    }
    prevFadeTime = currentTime;
  }
}


int debug(){
    if (total1 >= 600) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

