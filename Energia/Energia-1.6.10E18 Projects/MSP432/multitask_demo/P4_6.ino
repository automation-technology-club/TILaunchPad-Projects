#define LED 8

void setupP4_6() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loopP4_6() {
  digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(LED, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
