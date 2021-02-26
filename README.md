# pca-tempsensor-mqtt
Metingen van een temperatuursensor publiceren via mqtt. Dit is een project voor PC-Active 317. Er wordt gebruik gemaakt van de ESP8266 en de mqtt-broker in Home Assistant (Mosquitto).

# Extra bibliotheken
De bibliotheken OneWire en DallasTemperature zijn nodig voor het uitlezen van de waardes van de temperatuursensor. De bibliotheek PubSubClient gebruiken we om de metingen aan de mqtt-broker door te geven. Zie ook de uitleg in PC-Active 317.

# Instellingen
Zet in Settings.h de instellingen voor je wifi-netwerk en de mqtt-broker.
