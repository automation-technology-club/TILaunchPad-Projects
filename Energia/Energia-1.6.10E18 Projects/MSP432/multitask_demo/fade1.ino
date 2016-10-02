
#define LED 40
int brightness1 = 0;    // how bright the LED is
int fadeAmount1 = 5;    // how many points to fade the LED by

void setupFade1()  { 
  // declare pin 14 to be an output:
  pinMode(LED, OUTPUT);
} 

void loopFade1()  { 
  // set the brightness of pin 9:
  analogWrite(LED, brightness1);    

  // change the brightness for next time through the loop:
  brightness1 = brightness1 + fadeAmount1;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness1 == 0 || brightness1 == 255) {
    fadeAmount1 = -fadeAmount1 ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}

