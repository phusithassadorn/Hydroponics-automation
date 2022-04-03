// Replace/ Fill-in information from your Blynk Template here

#define BLYNK_TEMPLATE_ID "TMPLUcUfLW6K"
#define BLYNK_DEVICE_NAME "Hydroponics automation"

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#include "BlynkEdgent.h"

#define USE_WROVER_BOARD

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  digitalWrite(15,pinValue);
}

void setup()
{
  pinMode(15,OUTPUT);
  Serial.begin(9600);
  BlynkEdgent.begin();
  delay(2000);
}

void loop()
{
  BlynkEdgent.run();
}
