/* Read Wheel Encoder with out interrupts 
 * LeRoy Miller, 2016
*/


 int val; 
 int encoder0PinA = 29; //left
 int encoder0PinB = 30; //right
int countl = 0;
int countr = 0;
unsigned long lastmills = 0;
int readtime = 500;
int leftstate;
int rightstate;
 
 void setup() { 
   pinMode (encoder0PinA,INPUT);
   pinMode (encoder0PinB,INPUT);
   Serial.begin (9600);
delay(500);
leftstate = digitalRead(encoder0PinA);
rightstate = digitalRead(encoder0PinB);
  // Serial.print(digitalRead(encoder0PinA));
  // Serial.print(" ");
  // Serial.print(digitalRead(encoder0PinB));
  // while(1);
 } 

 void loop() { 

unsigned long currentMillis = millis();


if (digitalRead(encoder0PinA) != leftstate) {countl ++; leftstate = !leftstate; }
if (digitalRead(encoder0PinB) != rightstate) {countr ++; rightstate = !rightstate;}
   //delay(readtime);

   if (currentMillis - lastmills >= readtime) {
    Serial.print("Left: ");
    Serial.print(countl);
    Serial.print(" Right: ");
    Serial.println(countr);
    lastmills = currentMillis;
    countl = 0;
    countr = 0;
  //  delay(readtime);
      }
     // delay(readtime);
    } 
