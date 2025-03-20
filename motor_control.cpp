#include "motor_control.h"

Servo servos[4];  //сервоприводы
int currentIndex = 0;  //индекс последовательности

void initMotors() {
    // Инициализация сервоприводов
    servos[0].attach(SERVO_1_PIN);
    servos[1].attach(SERVO_2_PIN);
    servos[2].attach(SERVO_3_PIN);
    servos[3].attach(SERVO_4_PIN);
    
    //начальная позиция
    setServoPositions(0);
}

void rotatePlatforms() {
    //меняем индекс
    currentIndex = (currentIndex + 1) % NUM_ANGLES;
    
    setServoPositions(currentIndex);
}

void setServoPositions(int index) {
    //позиции для сервоприводов  
    for (int i = 0; i < 4; i++) {
        int angleIndex = (index + i) % NUM_ANGLES;
        servos[i].write(SERVO_ANGLES[angleIndex]);
    }
}