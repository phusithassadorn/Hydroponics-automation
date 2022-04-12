// Replace/ Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLUcUfLW6K"
#define BLYNK_DEVICE_NAME "Hydroponics automation"

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#include "BlynkEdgent.h"

#include <DHT.h>
#define DHTPIN 16 //Connect Out pin to D2 in NODE MCU
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);

#define USE_WROVER_BOARD

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  digitalWrite(15,!pinValue);
}

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V1, t);
    Blynk.virtualWrite(V2, h);
    Serial.print("Temperature : ");
    Serial.print(t);
    Serial.print("    Humidity : ");
    Serial.println(h);
}

void setup()
{
  pinMode(15,OUTPUT);
  dht.begin();
  timer.setInterval(100L, sendSensor);
  Serial.begin(9600);
  BlynkEdgent.begin();
  delay(2000);
}

void loop()
{
  BlynkEdgent.run();
  timer.run();
}
