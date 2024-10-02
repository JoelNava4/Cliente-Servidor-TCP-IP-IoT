#include <WiFiManager.h>
#include <LEDManager.h>

const char* WIFI_SSID = "jota";
const char* WIFI_PASS = "joelnava4";
const char* SERVER_ADDRESS = "192.168.227.228";
const int SERVER_PORT = 80;

const int LED_PINS[] = { 14, 12, 5, 4, 2};
const int LED_COUNT = sizeof(LED_PINS) / sizeof(LED_PINS[0]);

WiFiManager wifiManager(WIFI_SSID, WIFI_PASS);
LEDManager ledManager(LED_PINS, LED_COUNT);

void setup() {
  Serial.begin(115200);
  wifiManager.connect();
}

void loop() {
  delay(300);
  
  ledManager.turnOffAll();

  WiFiClient client;
  Serial.print("Connecting to server: ");
  Serial.println(SERVER_ADDRESS);

  if (!client.connect(SERVER_ADDRESS, SERVER_PORT)) {
    Serial.println("Connection failed");
    return;
  }

  client.println("GET");

  unsigned long previousMillis = millis();
  while (!client.available() && millis() - previousMillis < 1000);

  if (client.available() > 0) {
    String line = client.readStringUntil('\n');
    int distance = line.toInt();
    Serial.println("Distance received from server: " + String(distance));

    ledManager.setLEDsBasedOnDistance(distance);
  } else {
    Serial.println("Server timeout.");
  }

  Serial.println("Closing connection.");
  client.stop();
}
