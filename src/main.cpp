#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>

void init_wifi() {
  const char* ssid     = "Begun";
  const char* password = "epyfnmepyfnm";
  const char* progress = "|/-\\";

  Serial.println();
  WiFi.begin(ssid, password);

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.printf("Connecting to Wi-Fi: %c\r", progress[i%4]);
    delay(75);
    i++;
  }

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void init_ota() {
  ArduinoOTA.onStart([]() {});

  ArduinoOTA.onEnd([]() {
    Serial.println("\n");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Updating: %u%%\r", (progress / (total / 100)));
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });

  ArduinoOTA.begin();
}

void setup() {
  Serial.begin(9600);
  init_wifi();
  init_ota();
}

void loop() {
  ArduinoOTA.handle();
}
