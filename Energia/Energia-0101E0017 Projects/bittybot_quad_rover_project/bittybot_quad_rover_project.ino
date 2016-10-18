/* Bittybot Quad Rover using TI Launchpad MSP432
 * 
 * Copyright (C) LeRoy Miller, 2016
 *
 */
 
 //This thread should be used to setup variables and initalise devices.
 //Set Global variables here
 
 //Used for Encoder
 int val; 
 int encoder0PinA = 29; //left encoder
 int encoder0PinB = 30; //right encoder
 int countl = 0;
 int countr = 0;
 unsigned long lastmills = 0;
 int readtime = 500; //how long to count pulses from encoders
 int leftstate;
 int rightstate;
 
 //Ping Setup
 int ping1;
 int maximumRange = 200;
 int minimumRange = 0;
 long duration, distance;
 #define echoPin 32
 #define triggerPin 31

 //Nokia 5110 LCD
 // Core library - IDE-based
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
 
// Include application, user and local libraries
#include "LCD_5110.h"

// Variables
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
 
