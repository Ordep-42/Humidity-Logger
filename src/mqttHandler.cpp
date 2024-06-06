#include "mqttHandler.h"

PubSubClient mqttClient(wifiClient);

const char* mqttServer = "io.adafruit.com";
const int mqttPort = 1883;
const unsigned int mqttTimeout = 10 * 1000;
const char* clientID = "ESP32-HumidityLogger";

void setupMqtt() {
    pinMode(2, OUTPUT);
    unsigned int attempts = 0;

    Serial.println(F("Starting MQTT"));
    mqttClient.setServer(mqttServer, mqttPort);

    safeMqttConnection();
}

void safeMqttConnection() {
    pinMode(2, OUTPUT);
    unsigned int attempts = 0;

    while(!connectMqtt() && attempts < 3) {
        digitalWrite(2, HIGH);
        Serial.print(F("Failed to connect to MQTT, trying again in "));
        Serial.print(mqttTimeout / 1000);
        Serial.println(F(" seconds"));
        delay(mqttTimeout);
        digitalWrite(2, LOW);
        attempts++;

        if (attempts == 3) {
            Serial.println(F("Failed to connect to MQTT after 3 attempts. Restarting."));
            ESP.restart();
        }
    }
}

int connectMqtt() {
    Serial.print(F("Connecting to MQTT server: "));
    Serial.println(mqttServer);

    unsigned long start = millis();

    while(!mqttClient.connected() && millis() - start < mqttTimeout) {
        Serial.print(F("Status: "));
        Serial.println(mqttClient.state());
        if (mqttClient.connect(clientID, AdafruitIoUser, AdafruitIoKey)) {
            Serial.println(F("Connected to MQTT"));
            return 1;
        } else {
            Serial.print(F("Failed to connect to MQTT, rc="));
            Serial.println(mqttClient.state());
            return 0;
        }
        delay(100);
    }
    return 0;
}

void handleMqttConnection() {
    if (!mqttClient.connected()) {
        safeMqttConnection();
    }
    mqttClient.loop();
}

void publishMqtt(float temp, float humidity) {
    if (!mqttClient.connected()) {
        safeMqttConnection();
    }
    while(temp < 1 || humidity < 1) {
        Serial.println(F("Invalid data, skipping MQTT publish"));
        digitalWrite(2, HIGH);
        return;
    }
    mqttClient.publish(AdafruitIoUser "/feeds/humidlog.temperatura", String(temp).c_str());
    mqttClient.publish(AdafruitIoUser "/feeds/humidlog.umidade", String(humidity).c_str());
    Serial.println(F("Data published to Adafruit IO"));
    digitalWrite(2, LOW);
}
