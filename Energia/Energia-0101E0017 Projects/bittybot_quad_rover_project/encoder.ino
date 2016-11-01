
/* Read Wheel Encoder with out interrupts 
 * LeRoy Miller, 2016
 */

 void setupEncoder() { 
  
 } 

 void loopEncoder() { 

unsigned long encoderCurrentMillis = millis();
if (digitalRead(encoder0PinB) != leftstate) {countl ++; leftstate = !leftstate; }
if (digitalRead(encoder0PinA) != rightstate) {countr ++; rightstate = !rightstate;}
   
   if (encoderCurrentMillis - encoderLastMills >= readtime && isRunning == 1) {
    Serial.print("Left: ");
    Serial.print(countl);
    Serial.print(" Right: ");
    Serial.println(countr);
    pwmR = (70+(countl - countr)*multipler); //need to update this for set speed - appears to go fairly straight over a distance, but does start to turn if surface is uneven.
    encoderLastMills = encoderCurrentMillis;
    countl = 0;
    countr = 0;
       }
       
    if (isRunning == 0) {
       encoderLastMills = encoderCurrentMillis;
       countl = 0;
       countr = 0;   
    } 
 } 
