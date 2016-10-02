#define LED 37
int brightness4 = 0;    // how bright the LED is
int fadeAmount4 = 15;    // how many points to fade the LED by

void setupFade4()  { 
  // declare pin 14 to be an output:
  pinMode(LED, OUTPUT);
} 

void loopFade4()  { 
  // set the brightness of pin 9:
  analogWrite(LED, brightness4);    

  // change the brightness for next time through the loop:
  brightness4 = brightness4 + fadeAmount4;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness4 <= 0 || brightness4 >= 255) {
    fadeAmount4 = -fadeAmount4 ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(500);                            
}

