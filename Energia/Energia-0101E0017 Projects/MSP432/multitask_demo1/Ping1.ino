#define echoPin 32
#define triggerPin 31


void setupPing1() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loopPing1() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  //calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;

  if (distance >= maximumRange || distance <= minimumRange) {ping1 = -1;} else {ping1 = distance;}
  delay(50);
}

