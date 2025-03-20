#include "light_control.h"


int currentBrightness = 0;
unsigned long lastLightCheck = 0;

void initLighting() {
    pinMode(LIGHT_PIN, OUTPUT);
    pinMode(LIGHT_SENSOR_PIN, INPUT);
    
    setLightBrightness(0);
}

void updateLighting() {
    unsigned long currentTime = millis();
    
    // Проверка освещения
    if (currentTime - lastLightCheck >= LIGHT_CHECK_INTERVAL) {
        lastLightCheck = currentTime;
        
        // получаем дату датчика освещенности
        int lightLevel = getLightLevel();
        
        // Если света мало, включаем подсветку
        if (lightLevel < LIGHT_THRESHOLD) {
            // Расчет яркости обратно пропорционально освещенности
            int targetBrightness = map(lightLevel, 0, LIGHT_THRESHOLD, MAX_BRIGHTNESS, MIN_BRIGHTNESS);
            setLightBrightness(targetBrightness);
        } else {
            //выключаем подсветку
            setLightBrightness(0);
        }
    }
}

void setLightBrightness(int brightness) {
    // чекаем пределы
    brightness = constrain(brightness, 0, MAX_BRIGHTNESS);
    
    // ставим новую яркость
    if (brightness != currentBrightness) {
        currentBrightness = brightness;
        analogWrite(LIGHT_PIN, currentBrightness);
    }
}

int getLightLevel() {
    //возвращаем уровень освещенности 
    return analogRead(LIGHT_SENSOR_PIN);
}