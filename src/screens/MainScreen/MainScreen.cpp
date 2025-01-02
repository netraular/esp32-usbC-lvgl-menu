#include <Arduino.h>
#include "config.h"
#include "MainScreen.h"
#include "../ScreenManager.h"

extern ScreenManager screenManager;

void MainScreen::load() {
    lv_obj_t* label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Main Screen");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    Serial.println("MainScreen cargada.");
}

void MainScreen::update() {
    // Lógica de actualización de la pantalla principal
}

void MainScreen::handleButtonPress(int button) {
    if (button == 1) {
        // Hacer sonar el buzzer
        tone(BUZZER_PIN, 1000, 200);
        // Cambiar a SecondScreen
        screenManager.setScreen("SecondScreen");
    }
}