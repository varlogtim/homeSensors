#include <DFRobot_DHT11.h>  // TODO: Think about replacing this. Maintainer is inactive. Maybe that is fine though.
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>

DFRobot_DHT11 DHT;
WiFiUDP udp;

#define DHT11_PIN 13

const char *SSID = "derp";
const char *WiFiPassword = "NotThePassword";
const char *udpAddress = "192.168.1.120";
const int udpPort = 1234;


void ConnectToWifi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, WiFiPassword);
  Serial.printf("Connecting to: %s\n", SSID);

  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);

    if ((++i % 16) == 0) {
      Serial.println(" still trying to connnect");
    }
  }
  Serial.printf("Connected. IP Addr: %s\n", WiFi.localIP());
}

void setup() {
  Serial.begin(9600);
  ConnectToWifi();
}


void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  DHT.read(DHT11_PIN);

  float tempF = DHT.temperature * 1.8 + 32;

  udp.beginPacket(udpAddress, udpPort);
  udp.printf("%.1fx%d\n", tempF, DHT.humidity);
  udp.endPacket();
  Serial.printf("temp:%d, humi: %.1f\n", tempF, DHT.humidity);
}
