#include "SimpleRSLK.h"

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(LED_FR_PIN, OUTPUT); 
  pinMode(LED_FL_PIN, OUTPUT); 
  pinMode(LED_BR_PIN, OUTPUT); 
  pinMode(LED_BL_PIN, OUTPUT);
}

void loop() {
 digitalWrite(LED_FR_PIN, HIGH);
 delay(100);
 digitalWrite(LED_FR_PIN, LOW);
 //delay(100);
 digitalWrite(LED_BR_PIN, HIGH);
 delay(100);
 digitalWrite(LED_BR_PIN, LOW);
 //delay(100);
 
 digitalWrite(LED_BL_PIN, HIGH);
 delay(100);
 digitalWrite(LED_BL_PIN, LOW);
 //delay(100);
 digitalWrite(LED_FL_PIN, HIGH);
 delay(100);
 digitalWrite(LED_FL_PIN, LOW);
 //delay(100);

 /*digitalWrite(RED_LED, HIGH);
 delay(100);
 digitalWrite(RED_LED, LOW);
 delay(100);
 digitalWrite(GREEN_LED, HIGH);
 delay(100);
 digitalWrite(GREEN_LED, LOW);
 delay(100);
 digitalWrite(BLUE_LED, HIGH);
 delay(100);
 digitalWrite(BLUE_LED, LOW);
 delay(100);
 */
}
