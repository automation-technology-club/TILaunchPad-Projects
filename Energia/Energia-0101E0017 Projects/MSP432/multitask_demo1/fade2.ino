#define LED 39
int brightness2 = 0;    // how bright the LED is
int fadeAmount2 = 1;    // how many points to fade the LED by

void setupFade2()  { 
  // declare pin 14 to be an output:
  pinMode(LED, OUTPUT);
} 

void loopFade2()  { 
  // set the brightness of pin 9:
  analogWrite(LED, brightness1);    

  // change the brightness for next time through the loop:
  brightness2 = brightness2 + fadeAmount2;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness2 == 0 || brightness2 == 255) {
    fadeAmount2 = -fadeAmount2 ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(100);                            
}

