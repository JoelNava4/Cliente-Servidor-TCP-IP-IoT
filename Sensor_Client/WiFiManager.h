#ifndef WIFIMANAGER_H
#define WIFIMANAGER_H

#include <WiFi.h>

class WiFiManager {
  const char* SSID;
  const char* PASSWORD;

public:
  WiFiManager(const char* WIFi_SSID, const char* WIFI_PASSWORD);
  void connect();
};

#endif // WIFIMANAGER_H
