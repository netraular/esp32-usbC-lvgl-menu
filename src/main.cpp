#include <Arduino.h>
#include "config.h"
#include "screens/ScreenManager.h"
#include "screens/MainScreen/MainScreen.h"
#include "screens/SecondScreen/SecondScreen.h"

TFT_eSPI tft;
ScreenManager screenManager(tft);
MainScreen mainScreen;
SecondScreen secondScreen;

// Intervalo de tiempo para 30 FPS (en milisegundos)
const uint32_t FRAME_INTERVAL = 1000 / 30;

void setup() {
    Serial.begin(115200);
    Serial.println("Inicializando el sistema...");

    // Configurar pines
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(BUTTON1_PIN, INPUT_PULLUP); // Usar resistencia pull-up interna
    pinMode(BUTTON2_PIN, INPUT_PULLUP); // Usar resistencia pull-up interna
    pinMode(BUTTON3_PIN, INPUT_PULLUP); // Usar resistencia pull-up interna

    // Registrar pantallas en ScreenManager
    screenManager.addScreen("MainScreen", &mainScreen);
    screenManager.addScreen("SecondScreen", &secondScreen);

    // Inicializar LVGL y cargar la pantalla principal
    screenManager.init();
    screenManager.setScreen("MainScreen");

    Serial.println("Setup completado.");
}

void loop() {
    static uint32_t last_frame_time = millis(); // Tiempo del último fotograma
    uint32_t current_time = millis();
    uint32_t elapsed_time = current_time - last_frame_time; // Tiempo transcurrido desde el último fotograma

    // Actualizar cada fotograma (30 FPS)
    if (elapsed_time >= FRAME_INTERVAL) {
        last_frame_time = current_time; // Reiniciar el tiempo del último fotograma

        // Actualizar LVGL con el tiempo transcurrido
        lv_tick_inc(elapsed_time);

        // Actualizar el ScreenManager (LVGL y la pantalla activa)
        screenManager.update();
    }

    // Leer el estado de los botones con debounce
    screenManager.handleButtons();
}