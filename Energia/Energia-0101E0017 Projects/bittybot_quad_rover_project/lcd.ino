//
//  LCD_5110_main.ino
//  Sketch
//  ----------------------------------
//  Developed with embedXcode
//
//  Project LCD BoosterPack for MSP430G2553 and StallarPad LM4F
//  Created by Rei VILO on 28/05/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//
//  Ported to LM4F120 by Bryan Schremp (bajabug@gmail.com) 11/10/2012
//
//Nokia 5110 LCD
 

// Add setup code
void setupLCD() {
    myScreen.begin();
}


// Add loop code
void loopLCD() {
    myScreen.clear();
    myScreen.setFont(0);
    //myScreen.setBacklight(backlight);
    myScreen.text(0, 0, "Count: ");
    String str = String(pingcount);
    myScreen.text(28, 0, str);
  
    str = String(ping1);
    myScreen.text(0,1, "Avg: ");
    myScreen.text(5, 1, str);
        
    myScreen.text(0, 2, "Left: ");
    str = String(countl);
    myScreen.text(28, 2, str);
                 
    myScreen.text(0,3, "Right: ");
    str = String(countr);
    myScreen.text(28,3, str);
        
    delay(100);
}




