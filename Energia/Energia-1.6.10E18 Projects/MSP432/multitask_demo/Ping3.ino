
  
#define echoPin 30
#define triggerPin 29

void setupPing3() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loopPing3() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration3 = pulseIn(echoPin, HIGH);

  //calculate the distance (in cm) based on the speed of sound.
  distance3 = duration3/58.2;

  if (distance3 >= maximumRange || distance3 <= minimumRange) {ping3 = -1;} else {ping3 = distance3;}
  delay(50);
}

