#include <Arduino.h>
#include "MainScreen.h"

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
    // Lógica para manejar los botones en la pantalla principal
}