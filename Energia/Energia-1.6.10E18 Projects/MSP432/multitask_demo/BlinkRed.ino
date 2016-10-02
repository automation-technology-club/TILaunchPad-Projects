
#define LED1 78
//see pins_energia.h for more LED definitions
//#define LED GREEN_LED
  
// the setup routine runs once when you press reset:
void setupBlinkRed() {                
  // initialize the digital pin as an output.
  pinMode(LED1, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loopBlinkRed() {
  digitalWrite(LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(LED1, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second
}
