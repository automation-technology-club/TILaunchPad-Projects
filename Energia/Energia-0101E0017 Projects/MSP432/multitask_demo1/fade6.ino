#define LED 35
int brightness6 = 253;    // how bright the LED is
int fadeAmount6 = 2;    // how many points to fade the LED by

void setupFade6()  { 
  // declare pin 14 to be an output:
  pinMode(LED, OUTPUT);
} 

void loopFade6()  { 
  // set the brightness of pin 9:
  analogWrite(LED, brightness6);    

  // change the brightness for next time through the loop:
  brightness6 = brightness6 + fadeAmount6;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness6 <= 0 || brightness6 >= 255) {
    fadeAmount6 = -fadeAmount6 ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(25);                            
}

