#ifndef LEDMANAGER_H
#define LEDMANAGER_H

class LEDManager {
  const int* LEDPINS; 
  int ledCount;  

public:
  LEDManager(const int PINS[], int count);
  void turnOffAll();
  void setLEDsBasedOnDistance(int distance);
};

#endif // LEDMANAGER_H

