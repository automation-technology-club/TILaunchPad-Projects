


void setupPing1() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loopPing1() {
  
  pingcount = pingcount + 1;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  //calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;

  /*if (distance >= maximumRange || distance <= minimumRange) {
      pingavg  = 0;
      pingcount = 0;
        } else {
            pingavg = pingavg + (distance / 2.54); }
 
  
  ping1 = (pingavg / pingcount);
 */

  ping1 = (distance /2.54); 
  //Serial.print("Ping: ");
  //Serial.println(ping1);
  delay(50);
}

