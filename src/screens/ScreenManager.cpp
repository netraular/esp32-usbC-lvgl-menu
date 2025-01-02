#include "ScreenManager.h"
#include "config.h" // Incluir config.h
#include <lvgl.h>

ScreenManager::ScreenManager(TFT_eSPI& tft) : tft(tft), currentScreen(nullptr) {
    // Inicializar los botones
    buttons[0].pin = BUTTON1_PIN;
    buttons[0].state = LOW; // Estado inicial LOW (pull-down)
    buttons[0].lastDebounceTime = 0;

    buttons[1].pin = BUTTON2_PIN;
    buttons[1].state = LOW; // Estado inicial LOW (pull-down)
    buttons[1].lastDebounceTime = 0;

    buttons[2].pin = BUTTON3_PIN;
    buttons[2].state = LOW; // Estado inicial LOW (pull-down)
    buttons[2].lastDebounceTime = 0;
}

void ScreenManager::init() {
    lvgl_init();
}

void ScreenManager::addScreen(const std::string& name, Screen* screen) {
    screens[name] = screen;
}

void ScreenManager::setScreen(const std::string& name) {
    if (screens.find(name) != screens.end()) {
        if (currentScreen != nullptr) {
            // Limpiar la pantalla actual si es necesario
            lv_obj_clean(lv_scr_act());
        }
        currentScreen = screens[name];
        currentScreen->load();
        Serial.print("Pantalla cargada: ");
        Serial.println(name.c_str());
    } else {
        Serial.println("Error: Pantalla no encontrada.");
    }
}

void ScreenManager::update() {
    if (currentScreen != nullptr) {
        currentScreen->update();
    }
    lv_timer_handler();
}

void ScreenManager::handleButtons() {
    for (int i = 0; i < 3; i++) {
        bool currentState = digitalRead(buttons[i].pin); // Leer el estado actual del botón

        // Guardar el tiempo de debounce en una variable temporal
        unsigned long debounceTime = buttons[i].lastDebounceTime;

        // Si el estado del botón ha cambiado (debido al rebote o una pulsación real)
        if (currentState != buttons[i].state) {
            buttons[i].lastDebounceTime = millis(); // Reiniciar el tiempo de debounce
        }

        // Si ha pasado el tiempo de debounce, verificar el estado del botón
        if ((millis() - debounceTime) > DEBOUNCE_DELAY) {
            // Si el estado del botón ha cambiado
            if (currentState != buttons[i].state) {
                buttons[i].state = currentState; // Actualizar el estado del botón

                // Si el botón está presionado (LOW), manejar el evento
                if (buttons[i].state == LOW) {
                    Serial.print("Botón ");
                    Serial.print(i + 1); // Los botones se numeran del 1 al 3
                    Serial.println(" presionado.");
                    if (currentScreen != nullptr) {
                        currentScreen->handleButtonPress(i + 1); // Pasar el número del botón (1, 2 o 3)
                    }
                }
            }
        }
    }
}

void ScreenManager::lvgl_init() {
    tft.begin();
    tft.fillScreen(TFT_BLACK);
    lv_init();

    static lv_disp_draw_buf_t draw_buf;
    static lv_color_t buf[TFT_WIDTH * 10];
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, TFT_WIDTH * 10);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = TFT_WIDTH;
    disp_drv.ver_res = TFT_HEIGHT;
    disp_drv.flush_cb = [](lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
        ((ScreenManager*)disp->user_data)->my_disp_flush(disp, area, color_p);
    };
    disp_drv.user_data = this;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
}

void ScreenManager::my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}