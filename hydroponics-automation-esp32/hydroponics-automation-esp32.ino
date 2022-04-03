
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLUcUfLW6K"
#define BLYNK_DEVICE_NAME "Hydroponics automation"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG
 
// Uncomment your board, or configure a custom board in Settings.h
#define USE_WROVER_BOARD
//#define USE_TTGO_T

#include "BlynkEdgent.h"

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
