
//see pins_energia.h for more LED definitions
#define LED GREEN_LED
  
// the setup routine runs once when you press reset:
void setupBlinkGreen() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loopBlinkGreen() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1500);               // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1500);               // wait for a second
}
