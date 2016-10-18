
/* Read Wheel Encoder with out interrupts 
 * LeRoy Miller, 2016
 */

 void setupEncoder() { 
  
 } 

 void loopEncoder() { 

unsigned long currentMillis = millis();
if (digitalRead(encoder0PinA) != leftstate) {countl ++; leftstate = !leftstate; }
if (digitalRead(encoder0PinB) != rightstate) {countr ++; rightstate = !rightstate;}
   
   if (currentMillis - lastmills >= readtime) {
    Serial.print("Left: ");
    Serial.print(countl);
    Serial.print(" Right: ");
    Serial.println(countr);
    lastmills = currentMillis;
    countl = 0;
    countr = 0;
       }
  } 
  
