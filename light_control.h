#ifndef LIGHT_CONTROL_H
#define LIGHT_CONTROL_H

#include <Arduino.h>

//  пины освещения
#define LIGHT_PIN 5       // PWM пин для светодиодной ленты
#define LIGHT_SENSOR_PIN A0  // Аналоговый пин для датчика освещенности

// Константы для управления освещением
#define LIGHT_CHECK_INTERVAL 60000  // Проверка света
#define LIGHT_THRESHOLD 500     // мин освещенность для включения света

// Пределы яркости света
#define MIN_BRIGHTNESS 50   // Мин яркость 
#define MAX_BRIGHTNESS 255  // Макс яркость 

void initLighting();
void updateLighting();
void setLightBrightness(int brightness);
int getLightLevel();

#endif