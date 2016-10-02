#define LED 36
int brightness5 = 24;    // how bright the LED is
int fadeAmount5 = 8;    // how many points to fade the LED by

void setupFade5()  { 
  // declare pin 14 to be an output:
  pinMode(LED, OUTPUT);
} 

void loopFade5()  { 
  // set the brightness of pin 9:
  analogWrite(LED, brightness5);    

  // change the brightness for next time through the loop:
  brightness5 = brightness5 + fadeAmount5;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness5 <= 0 || brightness5 >= 255) {
    fadeAmount5 = -fadeAmount5 ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(50);                            
}

