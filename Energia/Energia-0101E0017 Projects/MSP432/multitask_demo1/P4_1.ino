#define LED 5

void setupP4_1() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loopP4_1() {
  digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1200);               // wait for a second
  digitalWrite(LED, HIGH);    // turn the LED off by making the voltage LOW
  delay(1200);               // wait for a second
}
