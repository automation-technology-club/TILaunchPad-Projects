
/* Read Wheel Encoder with out interrupts 
 * LeRoy Miller, 2016
 */

 void setupEncoder() { 
  
 } 

 void loopEncoder() { 

unsigned long currentMillis = millis();
if (digitalRead(encoder0PinA) != leftstate) {countl ++; leftstate = !leftstate; }
if (digitalRead(encoder0PinB) != rightstate) {countr ++; rightstate = !rightstate;}
   
   if (currentMillis - lastmills >= readtime || isRunning == 1) {
    Serial.print("Left: ");
    Serial.print(countl);
    Serial.print(" Right: ");
    Serial.println(countr);
    pwmR = (countl - countr)*multipler;
    lastmills = currentMillis;
    countl = 0;
    countr = 0;
       }
  } 
  
