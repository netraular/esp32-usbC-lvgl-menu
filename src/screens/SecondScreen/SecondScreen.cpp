#include <Arduino.h>
#include "SecondScreen.h"

void SecondScreen::load() {
    lv_obj_t* label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Second Screen");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    Serial.println("SecondScreen cargada.");
}

void SecondScreen::update() {
    // Lógica de actualización de la segunda pantalla
}

void SecondScreen::handleButtonPress(int button) {
    // Lógica para manejar los botones en la segunda pantalla
}