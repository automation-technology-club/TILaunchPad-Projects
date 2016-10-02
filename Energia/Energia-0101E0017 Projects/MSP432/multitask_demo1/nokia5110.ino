
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
  
    str = String(tempf);
    myScreen.text(0,1, str);
    myScreen.text(3, 1, "F");
    str = String(tempc);
    myScreen.text(5, 1, str);
    myScreen.text(8, 1, "C");
    str = String(humidity);
    myScreen.text(10, 1, str);
    myScreen.text(12, 1, "%");
    
    myScreen.text(0, 2, "Ping1: ");
    str = String(ping1);
    if (ping1 == -1) {
          myScreen.text(28,2, "OR"); } else {
              myScreen.text(28, 2, str);
              myScreen.text(31, 2, "cm"); }
              
    myScreen.text(0,3, "Ping2: ");
    str = String(ping2);
    if (ping2 == -1) {
          myScreen.text(28, 3, "OR"); } else {
              myScreen.text(28,3, str);
              myScreen.text(31,3, "cm"); }
              
    myScreen.text(0, 4, "Ping3: ");
    str = String(ping3);
    if (ping3 == -1) {
          myScreen.text(28,4, "OR"); } else {
                myScreen.text(28, 4, str);
                myScreen.text(31,4, "cm"); }
    
    delay(100);
  }
