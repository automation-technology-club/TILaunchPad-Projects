#define LED 38
int brightness3 = 0;    // how bright the LED is
int fadeAmount3 = 10;    // how many points to fade the LED by

void setupFade3()  { 
  // declare pin 14 to be an output:
  pinMode(LED, OUTPUT);
} 

void loopFade3()  { 
  // set the brightness of pin 9:
  analogWrite(LED, brightness1);    

  // change the brightness for next time through the loop:
  brightness3 = brightness3 + fadeAmount3;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness3 == 0 || brightness3 == 255) {
    fadeAmount3 = -fadeAmount3 ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(300);                            
}

