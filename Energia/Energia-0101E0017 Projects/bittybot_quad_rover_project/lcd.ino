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
    if (myScreen.getButton()) {
        backlight = (backlight==0);
        myScreen.setFont(0);
        myScreen.text(0, 5, backlight ? "Light on " : "Light off");
        myScreen.setBacklight(backlight);
    }
    
    myScreen.setFont(1);
    if (k==0)   myScreen.text(0, 2, " MSP430");
    else if (k==8)   myScreen.text(0, 2, "  LM4F  ");
    
    myScreen.setFont(0);
    for (uint8_t i=0; i<14; i++) myScreen.text(i, 4, (i==k) ? "*" : " ");
    k++;
    k %= 14;
    
    delay(200);
}




