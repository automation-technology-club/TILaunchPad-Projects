/* Based on the RSLK Encoder Motors example sketech
   This makes a small square, I know there is a better way to get
   the turning degree. For now it's a cheat using the same method
   to figure distance, and reducing the distance needed. turning both
   wheels in the opposite direction.

  LeRoy Miller, Aug 31, 2024.
*/
  
#include "SimpleRSLK.h"

#define UART_SERIAL     Serial


/* Diameter of Romi wheels in inches 
 *  2.7559055" = 7.0 cm (International System of Units) 
 */
const float wheelDiameter = 2.7559055; 

/* Number of encoder (rising) pulses every time the wheel turns completely */
const int cntPerRevolution = 360;

const int wheelSpeed = 15; // Default raw pwm speed for motor.

uint16_t totalCount = 0;        // Total amount of encoder pulses received
    uint16_t leftCount, rightCount;

float distanceTraveled(float wheel_diam, uint16_t cnt_per_rev, uint8_t current_cnt)
{
    float temp = (wheel_diam * PI * current_cnt) / cnt_per_rev;
    return temp;
}

uint32_t countForDistance(float wheel_diam, uint16_t cnt_per_rev, uint32_t distance)
{
    float temp = (wheel_diam * PI) / cnt_per_rev;
    temp = distance / temp;
    return int(temp);
}

void setup() {
   UART_SERIAL.begin(115200);

    setupRSLK();
    /* Left button on Launchpad */
    setupWaitBtn(LP_LEFT_BTN);
    /* Red led in rgb led */
    setupLed(RED_LED);
}

void loop() {

    /* Wait until button is pressed to start robot */
    String btnMsg = "\nPush left button on Launchpad to start demo.\n";
    UART_SERIAL.println(btnMsg);
    waitBtnPressed(LP_LEFT_BTN, RED_LED);

delay(2000);

forwardLeg();
turnLeft90();
forwardLeg();
turnLeft90();
forwardLeg();
turnLeft90();
forwardLeg();
}

void forwardLeg() { 
//drive forward one leg of square
  resetLeftEncoderCnt();
  resetRightEncoderCnt();
  setMotorDirection(BOTH_MOTORS, MOTOR_DIR_FORWARD);
  enableMotor(BOTH_MOTORS);
  setMotorSpeed(BOTH_MOTORS, wheelSpeed);

goToTarget(6);
disableMotor(BOTH_MOTORS);

}

void turnLeft90() {
//Turn left 90% there has to be a better way to do this.
  resetLeftEncoderCnt();
  resetRightEncoderCnt();
  setMotorDirection(RIGHT_MOTOR, MOTOR_DIR_FORWARD);
  setMotorDirection(LEFT_MOTOR, MOTOR_DIR_BACKWARD);
  enableMotor(BOTH_MOTORS);
  setMotorSpeed(BOTH_MOTORS, wheelSpeed);

  goToTarget(4);
  disableMotor(BOTH_MOTORS);

}


void goToTarget(int inchesToTravel) {

  uint16_t totalCount = 0;        // Total amount of encoder pulses received
  uint16_t leftCount, rightCount;
  uint16_t target = countForDistance(wheelDiameter, cntPerRevolution, inchesToTravel);
    
  while (totalCount < target) {
        leftCount = getEncoderLeftCnt();
        rightCount = getEncoderRightCnt();
        totalCount = (leftCount + rightCount) / 2;
        UART_SERIAL.print("\t"); UART_SERIAL.print(leftCount);
        UART_SERIAL.print("\t"); UART_SERIAL.println(rightCount);
    }
}
