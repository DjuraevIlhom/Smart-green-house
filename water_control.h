#ifndef WATER_CONTROL_H
#define WATER_CONTROL_H

#include <Arduino.h>

// Константы для системы полива
#define WATER_PUMP_PIN 6         // Пин для управления насосом
#define MOISTURE_SENSOR_PIN A1   // пин для датчика влажности 

// Константы для параметров полива
#define WATERING_DURATION 3000   // 3 секунды на полив
#define MOISTURE_CHECK_INTERVAL 300000  // Проверка влажности раз в 5 минут
#define MOISTURE_THRESHOLD 300   // Порог влажности для полива 

// Прототипы функций
void initWatering();
void updateWatering();
bool isWateringActive();
int getMoistureLevel();
void startWatering();
void stopWatering();
void checkAndWaterPlants();

#endif