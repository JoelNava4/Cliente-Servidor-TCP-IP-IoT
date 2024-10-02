#include "LEDManager.h"
#include <Arduino.h>

LEDManager::LEDManager(const int PINS[], int count) : LEDPINS(PINS), ledCount(count) {
  for (int i = 0; i < ledCount; i++) {
    pinMode(LEDPINS[i], OUTPUT);
  }
}

void LEDManager::turnOffAll() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(LEDPINS[i], LOW);
  }
}

void LEDManager::setLEDsBasedOnDistance(int distance) {
  turnOffAll(); 
  int numLEDsToLight = (distance <= 10) ? 5 :
                       (distance <= 20) ? 4 :
                       (distance <= 30) ? 3 :
                       (distance <= 40) ? 2 :
                       (distance <= 50) ? 1 : 0;
  for (int i = 0; i < numLEDsToLight; i++) {
    digitalWrite(LEDPINS[i], HIGH);
  }
}

