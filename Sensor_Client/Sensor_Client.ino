#include <WiFiManager.h>
#include <UltrasonicSensor.h>

const int TRIGGER_PIN = 19;
const int ECHO_PIN = 18;
const char* WIFI_SSID = "jota";    
const char* WIFI_PASSWORD = "joelnava4";      
const char* SERVER_ADDRESS = "192.168.227.228";   
const int SERVER_PORT = 80;                 

WiFiManager wifiManager(WIFI_SSID, WIFI_PASSWORD);
UltrasonicSensor ultrasonicSensor(TRIGGER_PIN, ECHO_PIN);

void setup() {
  Serial.begin(115200);   
  wifiManager.connect();  
}

void loop() {
  long duration = ultrasonicSensor.readDistance();
  int distanceCm = 0.01723 * duration;   
  Serial.println(distanceCm);            
  delay(1000);                            

  Serial.print("Connecting to server: ");
  Serial.println(SERVER_ADDRESS);

  WiFiClient client;

  if (!client.connect(SERVER_ADDRESS, SERVER_PORT)) {
    Serial.println("Connection failed");
    return;
  }

  client.println("distance=" + String(distanceCm));

  String response = client.readStringUntil('\n');
  Serial.println(response);

  Serial.println("Closing connection.");
  client.stop();
}
