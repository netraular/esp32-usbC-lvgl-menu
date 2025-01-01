#include <Arduino.h>
#include "screens/ScreenManager.h"
#include "screens/MainScreen/MainScreen.h"
#include "screens/SecondScreen/SecondScreen.h"

TFT_eSPI tft;
ScreenManager screenManager(tft);
MainScreen mainScreen;
SecondScreen secondScreen;

void setup() {
    Serial.begin(115200);
    Serial.println("Inicializando el sistema...");

    screenManager.init();
    screenManager.setScreen(&mainScreen);

    Serial.println("Setup completado.");
}

void loop() {
    screenManager.update();
}