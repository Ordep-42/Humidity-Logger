#include "wifiHandler.h"

const unsigned int wifiTimeout = 30 * 1000;

WiFiClient wifiClient;

void setupWifi() {
    pinMode(2, OUTPUT);
    unsigned int attempts = 0;

    Serial.println(F("Starting WiFi"));
    WiFi.mode(WIFI_STA);
    WiFi.setHostname("ESP32-HumidityLogger");
    WiFi.begin(wifiSSID, wifiPass);
    
    while (!connectWifi() && attempts < 3) {
        digitalWrite(2, HIGH);
        Serial.print(F("Failed to connect to WiFi, trying again in "));
        Serial.print(wifiTimeout / 1000);
        Serial.println(F(" seconds."));
        delay(wifiTimeout);
        digitalWrite(2, LOW);
        attempts++;
        if (attempts == 3) {
            Serial.println(F("Failed to connect to WiFi after 3 attempts. Restarting."));
            ESP.restart();
        }
    }
}

int connectWifi() {
    Serial.print(F("Connecting to WiFi network: "));
    Serial.println(wifiSSID);

    unsigned long start = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - start < wifiTimeout) {
        delay(100);
        Serial.print("Status: ");
        Serial.println(WiFi.status());
    }
    WiFi.status() == WL_CONNECTED ? Serial.println(F("Connected to WiFi")) : Serial.println(F("Failed to connect to WiFi"));
    return WiFi.status() == WL_CONNECTED ? 1 : 0;
}