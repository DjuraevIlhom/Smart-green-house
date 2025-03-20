#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Servo.h>

// пины сервоприводов
#define SERVO_1_PIN 9
#define SERVO_2_PIN 10
#define SERVO_3_PIN 11
#define SERVO_4_PIN 12

// задержка
#define ROTATION_DELAY 120000  

//углы
const int NUM_ANGLES = 4;
const int SERVO_ANGLES[NUM_ANGLES] = {0, 45, 90, 180};

// Прототипы функций
void initMotors();
void rotatePlatforms();
void setServoPositions(int index);

#endif
