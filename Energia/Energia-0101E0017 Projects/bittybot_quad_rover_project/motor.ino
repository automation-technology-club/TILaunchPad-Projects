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
//stop()

void setupMotor()   {  
//delay(1000); //Need delay here for everything to catch up  
 
}

void loopMotor()                     
{
 // rotateLeft(250, 500);
 // rotateRight(50, 1000);
 // rotateRight(250, 1000);
 // rotateRight(200, 1000);
 // rotateLeft(255, 500);
 // rotateRight(10, 1500);
 //delay (1000);
}

 //This portion of the code needs to go in a library or be re-written
//for use with the bitty-quad bot and TI-Launch Pad MSP432

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

void stop() {
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
}