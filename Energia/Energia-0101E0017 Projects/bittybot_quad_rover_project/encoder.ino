
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
        if ((countl <=5 || countr <=5) && isRunning == 1) {
              stop();
              moveBackward(maxspeed, 100);
              stop();
              rotateRightBack(200, 200);
              rotateLeftForward(200, 200);
              pingavg = 0;
              pingcount = 0;
              pwmL = maxspeed; //leftSetSpeed;
              pwmR = maxspeed; //rightSetSpeed
              delay(500);
        }
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
