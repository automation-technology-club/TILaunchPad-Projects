/*2-Way motor control adapted from
 * http://www.instructables.com/id/Simple-2-way-motor-control-for-the-arduino/
 * for use with the TI-Launchpad MSP432, and with some small changes
 * should work with the Arduino boards
 * Adapted by LeRoy Miller, 2016
 */

//Functions:
//rotateLeftBack(speed, length)
//rotateRightBack(speed, length)
//rotateLeftForward(speed, length)
//rotateRightForward(speed, length)
//moveForward(speed, length)
//moveBackward(speed, length)
//rightForward(speed, length)
//rightBackward(speed, length)
//leftForward(speed, length)
//leftBackward(speed, length)
//stop()


void setupMotor()   {  
delay(5000); //Need delay here for everything to catch up  
 stop();
 //leftForward(70, 0);// added for testing encoders reason
 //rightForward(70,0);//added for testing encoders reason
 pwmR = 125;//70;//added for testing encoders
 pwmL = 125;//70;//added for testing encoders
}

void loopMotor()                     
{
//attempt to keep bittybot rover going straight, unless ping sensor says it's too close to an object.
//then turn to the left apx 90 degrees, and continue forward, continue forever.

isRunning = 1;
leftForward(pwmL, 0);
rightForward(pwmR, 0);
//if (ping1 > 29 && ping1 <= 39) {pwmR = pwmR-25; pwmL = pwmL-25;}
if (ping1 <= 10 && ping1 >=0) {
      stop();
      isRunning = 0;
      countl = 0;
      countr = 0;
      rotateRightBack(200, 300);
      rotateLeftForward(200, 300);
      stop();
      pingavg = 0;
      pingcount = 0;
      pwmL = maxspeed; //leftSetSpeed;
      pwmR = maxspeed; //rightSetSpeed;
      delay(500);
}
//if (pwmR > maxspeed) {pwmR = maxspeed;}
//if (pwmR < minspeed) {pwmR = minspeed;}
//rotateRightForward(pwmR, 1);
//rotateLeftForward(pwmL, 1);
}

void rotateLeftBack(int speedOfRotate, int length){
  //rotates Left motor backwards causes robot to move to the right backward
  analogWrite(leftMotorPin1, speedOfRotate); //rotates motor
  digitalWrite(leftMotorPin2, LOW);    // set the Pin motorPin2 LOW
  delay(length); //waits
  digitalWrite(leftMotorPin1, LOW);    // set the Pin motorPin1 LOW
}

void rotateRightBack(int speedOfRotate, int length){
  //rotates right motor backwards cause robot to move to the left backward
  analogWrite(rightMotorPin2, speedOfRotate); //rotates motor
  digitalWrite(rightMotorPin1, LOW);    // set the Pin motorPin1 LOW
  delay(length); //waits
  digitalWrite(rightMotorPin2, LOW);    // set the Pin motorPin2 LOW
}

void rotateLeftForward(int speedOfRotate, int length){
  //rotates Left motor forward causes robot to move to the right forward
  digitalWrite(leftMotorPin1, LOW); //rotates motor
  analogWrite(leftMotorPin2, speedOfRotate);    // set the Pin motorPin2 LOW
  delay(length); //waits
  digitalWrite(leftMotorPin2, LOW);    // set the Pin motorPin1 LOW
}

void rotateRightForward(int speedOfRotate, int length){
  //rotates right motor forward cause robot to move to the left forward
  digitalWrite(rightMotorPin2, LOW); //rotates motor
  analogWrite(rightMotorPin1, speedOfRotate);    // set the Pin motorPin1 LOW
  delay(length); //waits
  digitalWrite(rightMotorPin1, LOW);    // set the Pin motorPin2 LOW
}

void moveForward(int speedOfRotate, int length) {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
  analogWrite(leftMotorPin2, speedOfRotate);
  analogWrite(rightMotorPin1, speedOfRotate);
  delay(length);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
}

void moveBackward(int speedOfRotate, int length) {
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  analogWrite(leftMotorPin1, speedOfRotate);
  analogWrite(rightMotorPin2, speedOfRotate);
  delay(length);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}

void rightForward(int speedOfRotate, int length) {
  digitalWrite(rightMotorPin2, LOW);
  analogWrite(rightMotorPin1, speedOfRotate);
}

void rightBackward(int speedOfRotate, int length) {
  digitalWrite(rightMotorPin1, LOW);
  analogWrite(rightMotorPin2, speedOfRotate);
}

void leftForward(int speedOfRotate, int length) {
  digitalWrite(leftMotorPin1, LOW);
  analogWrite(leftMotorPin2, speedOfRotate);
}

void leftBackward(int speedOfRotate, int length) {
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(leftMotorPin1, speedOfRotate);
}

void stop() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}
