int touchSense(){
  long start = millis();
  long result =  cs_4_2.capacitiveSensor(30);
  return result;
}

