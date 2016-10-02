

#define LED BLUE_LED
  
// the setup routine runs once when you press reset:
void setupBlinkBlue() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loopBlinkBlue() {
  digitalWrite(LED, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1500);               // wait for a second
  digitalWrite(LED, HIGH);    // turn the LED off by making the voltage LOW
  delay(1500);               // wait for a second
}
