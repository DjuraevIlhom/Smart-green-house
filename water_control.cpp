#include "water_control.h"

// переменные для модуля полива
bool isWatering = false;
unsigned long wateringStartTime = 0;
unsigned long lastMoistureCheck = 0;

void initWatering() {
    pinMode(WATER_PUMP_PIN, OUTPUT);
    pinMode(MOISTURE_SENSOR_PIN, INPUT);
    
    // насос выключен?
    digitalWrite(WATER_PUMP_PIN, LOW);
}

void updateWatering() {
    unsigned long currentTime = millis();
    
    // нужно выключить полив?
    if (isWatering) {
        if (currentTime - wateringStartTime >= WATERING_DURATION) {
            stopWatering();
        }
    } 
    
    else if (currentTime - lastMoistureCheck >= MOISTURE_CHECK_INTERVAL) {
        lastMoistureCheck = currentTime;
        checkAndWaterPlants();
    }
}

bool isWateringActive() {
    return isWatering;
}

int getMoistureLevel() {
    // Считываем и возвращаем текущий уровень влажности почвы
    return analogRead(MOISTURE_SENSOR_PIN);
}

void startWatering() {
    if (!isWatering) {
        digitalWrite(WATER_PUMP_PIN, HIGH);
        isWatering = true;
        wateringStartTime = millis();
    }
}

void stopWatering() {
    if (isWatering) {
        digitalWrite(WATER_PUMP_PIN, LOW);
        isWatering = false;
    }
}

void checkAndWaterPlants() {
    int moistureLevel = getMoistureLevel();
    
    // запускаем полив
    if (moistureLevel < MOISTURE_THRESHOLD) {
        startWatering();
    }
}