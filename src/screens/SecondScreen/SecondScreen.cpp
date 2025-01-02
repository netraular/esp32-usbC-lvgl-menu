#include <Arduino.h>
#include "config.h"
#include "SecondScreen.h"
#include "../ScreenManager.h"

extern ScreenManager screenManager;

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
    bool button1Pressed = digitalRead(BUTTON1_PIN) == LOW;
    bool button2Pressed = digitalRead(BUTTON2_PIN) == LOW;

    if (button1Pressed && button2Pressed) {
        // Hacer sonar el buzzer de forma distinta
        tone(BUZZER_PIN, 500, 500);
        // Cambiar a MainScreen
        screenManager.setScreen("MainScreen");
    }
}