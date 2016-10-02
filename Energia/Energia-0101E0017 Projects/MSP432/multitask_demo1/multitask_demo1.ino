
int count = 0;
const char message[12] = "Hello World";
int ping1;
int ping2;
int ping3;
int maximumRange = 200;
int minimumRange = 0;
long duration, distance;
long duration2, distance2;
long duration3, distance3;
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
#define BCKLIT 20
 
// Include application, user and local libraries
#include "LCD_5110.h"

// Variables
LCD_5110 myScreen(CS,CLK,Din,DC,RST,BCKLIT,PUSH2);
boolean	backlight = false;


void setup()
{
  Serial.begin(9600);
   //myScreen.begin();
    //myScreen.setFont(0);
    //myScreen.setBacklight(backlight);
   // myScreen.text(0, 0, "Hello!");
    
    delay(1000);
}

void loop()
{
  
}
