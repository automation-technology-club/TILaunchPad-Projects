#define LED 2

void setupP6_0() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loopP6_0() {
  digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(150);               // wait for a second
  digitalWrite(LED, HIGH);    // turn the LED off by making the voltage LOW
  delay(150);               // wait for a second
}
