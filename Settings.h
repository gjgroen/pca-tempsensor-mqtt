// Vervang door SSID van WiFi-netwerk
#define ssid "wifissid"

// Vervang door wachtwoord van WiFi-netwerk
#define wifipassword "wifiwachtwoord"

// Vervang door ip-adres van MQTT-server (bijvoorbeeld van Home Assistant)
#define mqtt_server "ipadres"

// Vervang door poortnummer van de MQTT-server (standaard 1883)
#define mqtt_poort 1883

// Vervang door gebruikersnaam voor toegang tot MQTT-server
#define mqtt_user "mqttuser"

// Vervang door password voor hierboven opgegeven mqtt_user
#define mqtt_password "mqttwachtwoord"

// Vervang door beschrijvende client id voor aanmelden bij MQTT-server
#define mqtt_clientid "ESP8266Gebruiker"

// Geef aan in welke topic de temperatuur gepubliceerd moet worden
#define mqtt_topic "sensoren/buiten/temperatuur"
