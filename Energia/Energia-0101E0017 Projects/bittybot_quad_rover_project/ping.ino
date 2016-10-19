/*


void setupPing1() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loopPing1() {
  int pingavg = 0;
  for (int avg=0; avg<=50; avg++) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  //calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;

  if (distance >= maximumRange || distance <= minimumRange) {pingavg = pingavg -1;} else {pingavg = pingavg + distance;}
  delay(50);
  }
  ping1 = (pingavg / 50);
  pingavg = 0;
}
*/
