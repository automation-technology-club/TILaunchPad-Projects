#define LED 4

void setupP3_3() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loopP3_3() {
  digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(550);               // wait for a second
  digitalWrite(LED, HIGH);    // turn the LED off by making the voltage LOW
  delay(550);               // wait for a second
}
