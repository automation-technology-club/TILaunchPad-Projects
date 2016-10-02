
  // Include application, user and local libraries
//#include "LCD_5110.h"

// Variables
//LCD_5110 myScreen(CS,CLK,Din,DC,RST,BCKLIT,PUSH2);
//boolean	backlight = false;
//uint8_t k = 0;

  void setupNokia5110() {
    myScreen.begin();
  }
  
  void loopNokia5110() {
    
    myScreen.clear();
    myScreen.setFont(0);
    //myScreen.setBacklight(backlight);
    myScreen.text(0, 0, "Count: ");
    String str = String(count);
    myScreen.text(28, 0, str);
    myScreen.text(0, 2, "Ping1: ");
    str = String(ping1);
    myScreen.text(28, 2, str);
    myScreen.text(31, 2, "cm");
    myScreen.text(0,3, "Ping2: ");
    str = String(ping2);
    myScreen.text(28,3, str);
    myScreen.text(31,3, "cm");
    myScreen.text(0, 4, "Ping3: ");
    str = String(ping3);
    myScreen.text(28, 4, str);
    myScreen.text(31,4, "cm");
    
    delay(100);
  }
