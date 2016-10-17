/*2-Way motor control adapted from
 * http://www.instructables.com/id/Simple-2-way-motor-control-for-the-arduino/
 * for use with the TI-Launchpad MSP432, and with some small changes
 * should work with the Arduino boards
 * Adapted by LeRoy Miller, 2016
 */

int leftMotorPin1 =  40; //Left Int1   
int leftMotorPin2 =  39; //Left Int2
int rightMotorPin1 = 38; //Right Int3
int rightMotorPin2 = 37; //Right Int4

// The setup() method runs once, when the sketch starts

void setup()   {                
  // initialize the digital pins as an output:
  pinMode(leftMotorPin1, OUTPUT); 
  pinMode(leftMotorPin2, OUTPUT);  
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
  
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()                     
{
  rotateLeft(250, 500);
 // rotateRight(50, 1000);
  rotateRight(250, 1000);
 // rotateRight(200, 1000);
 // rotateLeft(255, 500);
 // rotateRight(10, 1500);
delay (1000);
}

 //This portion of the code needs to go in a library or be re-written
//for use with the bitty-quad bot and TI-Launch Pad MSP432

void rotateLeft(int speedOfRotate, int length){
  //rotates Left motor backwards
  analogWrite(leftMotorPin1, speedOfRotate); //rotates motor
  digitalWrite(leftMotorPin2, LOW);    // set the Pin motorPin2 LOW
  delay(length); //waits
  digitalWrite(leftMotorPin1, LOW);    // set the Pin motorPin1 LOW
}

void rotateRight(int speedOfRotate, int length){
  //rotates right motor backwards
  analogWrite(rightMotorPin2, speedOfRotate); //rotates motor
  digitalWrite(rightMotorPin1, LOW);    // set the Pin motorPin1 LOW
  delay(length); //waits
  digitalWrite(rightMotorPin2, LOW);    // set the Pin motorPin2 LOW
}
/*
void rotateLeftFull(int length){
  digitalWrite(motorPin1, HIGH); //rotates motor
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
  delay(length); //waits
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
}

void rotateRightFull(int length){
  digitalWrite(motorPin2, HIGH); //rotates motor
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  delay(length); //waits
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
}
*/

