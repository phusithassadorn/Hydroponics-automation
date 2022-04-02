
#define BLYNK_PRINT Serial
#define RELAY_PIN 14

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


char auth[] = "YourAuthToken";
char ssid[] = "Hassadorn_5G";
char pass[] = "0998394346";

void relaysOutput (){
   pinMode(RELAY_PIN, OUTPUT);
  }

void setup()

 
{

Serial.begin(115200);

Blynk.begin(auth, ssid, pass);
}

void loop()
{
Blynk.run();
}
