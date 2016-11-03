
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
  if (countl <= 0 || countr <=0) {isStalled = 1;}    
    pwmR = (pwmL+(countl - countr)*multipler); //Left Motor is being used as Master
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
