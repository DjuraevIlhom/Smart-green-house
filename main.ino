#include "motor_control.h"
#include "light_control.h"
#include "water_control.h"

// Время последнего вращения платформ
unsigned long lastRotationTime = 0;

void setup() {
    // Инициализация последовательного порта для отладки
    Serial.begin(9600);
    Serial.println("Starting plant care system...");
    
    // Инициализация всех подсистем
    initMotors();
    initLighting();
    initWatering();
    
    Serial.println("All systems initialized!");
}

void loop() {
    // Текущее время
    unsigned long currentTime = millis();
    
    // Обновление состояния освещения
    updateLighting();
    
    // Обновление состояния системы полива
    updateWatering();
    
    // Вращение платформ по расписанию
    if (currentTime - lastRotationTime >= ROTATION_DELAY) {
        lastRotationTime = currentTime;
        rotatePlatforms();
        
        // Вывод отладочной информации
        Serial.println("Rotating platforms...");
        Serial.print("Current light level: ");
        Serial.println(getLightLevel());
        Serial.print("Current moisture level: ");
        Serial.println(getMoistureLevel());
    }
}