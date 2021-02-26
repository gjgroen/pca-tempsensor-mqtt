#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Settings.h"

// Declaraties voor temperatuursensor
const int oneWireBusPin = 4;
OneWire oneWire(oneWireBusPin);
DallasTemperature sensors(&oneWire);

// Declaraties voor wifi en mqtt
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // Initialisaties
  Serial.begin(115200);
  Serial.print("Verbinden met ");
  Serial.println(wifi_ssid);
  
  // Verbinden met wifi in standaard modus
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Melding bij verbinding met wifi
  Serial.println();
  Serial.print("WiFi verbonden, IP-adres: ");
  Serial.println(WiFi.localIP());

  // Initialisatie mqtt en temperatuursensor
  client.setServer(mqtt_server, mqtt_poort);
  sensors.begin();
}

void reconnect() {
  // Verbinden met mqtt-server
  while (!client.connected()) {
    Serial.print("Opzetten mqtt-verbinding...");
    if (client.connect(mqtt_clientid, mqtt_user, mqtt_password)) {
      Serial.println("verbonden");
    } else {
      Serial.print("mislukt, rc=");
      Serial.print(client.state());
      Serial.println(" probeer opnieuw na 5 seconden");
      delay(5000);
    }
  }
}

void loop() {
  // Verbinden met mqtt-server
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
  // Lees de temperatuurwaarde
  sensors.requestTemperatures(); 
  float tempC = sensors.getTempCByIndex(0);

  // Temperatuur converteren naar een char-array
  char tempString[8];
  dtostrf(tempC, 2, 1, tempString);
  
  // Print de temperatuur naar de seriële monitor
  Serial.print("Meetwaarde: ");
  Serial.print(tempString);
  Serial.println("ºC");

  // Temperatuur publiceren in mqtt-topic.
  client.publish(mqtt_topic, tempString);  

  // gewenste wachttijd (hier 15 seconden)
  delay(15000);
}
