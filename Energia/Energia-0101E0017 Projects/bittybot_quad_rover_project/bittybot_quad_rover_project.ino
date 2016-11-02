/* Bittybot Quad Rover using TI Launchpad MSP432
 * 
 * Copyright (C) LeRoy Miller, 2016
 *
 */
 
 //This thread should be used to setup variables and initalise devices.
 //Set Global variables here
 
 //Used for Encoder
 int val; 
 int encoder0PinA = 29; //right encoder
 int encoder0PinB = 30; //left encoder
 int countl = 0;
 int countr = 0;
 unsigned long encoderLastMills = 0;
 int readtime = 1000; //how long to count pulses from encoders
 int leftstate;
 int rightstate;
 int rightStallSpeed = 60;  //Wheels stop moving if PWM is 50 or less - I've added 10 to this vaule for a stall safty margin
 int leftStallSpeed = 60;
 int leftMaxSpeed = 175; //Maxium PWM is 255 - This is pretty fast, so this puts a upper limit on PWM and can be adjusted as needed.  It's better to keep this vaule below 255
 int rightMaxSpeed = 175;
 
 /* For our example (and my robot) the left wheel is going to be the master, while the right wheels will be the slave.
  * what this means, is as we are moving forward or backward, we will compair what the right wheel is doing against the "master" left wheel.
  * if the right wheel has more encoder counts - it is moving too fast and needs to be slowed down,
  * if the right wheel has less encoder counts - it is moving too slow and needs to be speed up.
  *
  * We will need to be able to adjust the speed on the fly, while also keeping distances so as to not hit a wall or barrier
  * This will be done in the motor tab
  */
 
 //setup our master wheel goals, and set speeds, and multiplier
 int countGoal = 40; //a count of 40 would have the wheels rotate 360 degrees (1 full time around)
 int leftSetSpeed = leftStallSpeed+30; //Set the starting speed just above the stall speed, well start out slow this can be adjusted
 int rightSetSpeed = rightStallSpeed+30; 
 float multipler = .2; //also known as kp (should be small something between 0 and 1
 int maxspeed = 125; //70; //This is the max speed either wheel can go - for this example it's the highest PWM we want to send to the wheels
 //int minspeed = 175; //this is the same as above, only it's the slowest we can have the motors go. 
 int isRunning = 0; //this flag will tell the encoder we are moving forward or backward, not that we are turning left or right.
 int pwmL = leftSetSpeed;
 int pwmR = rightSetSpeed;

 //Ping Setup
 int ping1;
 int maximumRange = 200;
 int minimumRange = 0;
 long duration, distance;
 int pingcount = 0;
 int pingavg;
 #define echoPin 32
 #define triggerPin 31

 //Nokia 5110 LCD
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"   
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(ENERGIA) // LaunchPad, FraunchPad and StellarPad specific
#include "Energia.h"
#elif defined(CORE_TEENSY) // Teensy specific
#include "WProgram.h"
#elif defined(ARDUINO) && (ARDUINO >= 100) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#elif defined(ARDUINO) && (ARDUINO < 100) // Arduino 23 specific
#include "WProgram.h"
#else // error
#error Board not supported
#endif

#define CS 18
#define CLK 7
#define Din 15
#define DC 17
#define RST 13
#define BCKLIT 19

#include "LCD_5110.h"

LCD_5110 myScreen(CS,CLK,Din,DC,RST,BCKLIT,PUSH2);
boolean	backlight = false;
uint8_t k = 0;

//Motor variable setup

int leftMotorPin1 =  40; //Left Int1   
int leftMotorPin2 =  39; //Left Int2
int rightMotorPin1 = 38; //Right Int3
int rightMotorPin2 = 37; //Right Int4


 void setup() {
   
   Serial.begin(9600);
   //delay(500);
     //Encoder Setup
   pinMode (encoder0PinA,INPUT);
   pinMode (encoder0PinB,INPUT);
   leftstate = digitalRead(encoder0PinA);
   rightstate = digitalRead(encoder0PinB);
   
  //Nokia 5110 Init
  myScreen.begin();
  myScreen.setBacklight(backlight);
  myScreen.text(0, 0, "Hello!");
  //delay(1000);
  //myScreen.clear();
  myScreen.text(0, 5, "Light off");

  //Motor Init
  pinMode(leftMotorPin1, OUTPUT); 
  pinMode(leftMotorPin2, OUTPUT);  
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
  
 }
 
 void loop() {
   //most likely nothing should be in the loop for this thread
 }
 
