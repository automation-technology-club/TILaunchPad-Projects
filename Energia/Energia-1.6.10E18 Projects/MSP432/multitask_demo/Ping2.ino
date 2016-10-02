
#define echoPin 11
#define triggerPin 12


void setupPing2() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loopPing2() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration2 = pulseIn(echoPin, HIGH);

  //calculate the distance (in cm) based on the speed of sound.
  distance2 = duration2/58.2;

  if (distance2 >= maximumRange || distance2 <= minimumRange) {ping2 = -1;} else {ping2 = distance2;}
  delay(50);
}

