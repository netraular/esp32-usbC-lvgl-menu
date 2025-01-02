#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Screen.h"
#include "config.h" // Incluir config.h
#include <TFT_eSPI.h>
#include <map>
#include <string>

class ScreenManager {
public:
    ScreenManager(TFT_eSPI& tft);
    void init();
    void addScreen(const std::string& name, Screen* screen);
    void setScreen(const std::string& name);
    void update();
    void handleButtons(); // Nueva función para manejar los botones

private:
    TFT_eSPI& tft;
    std::map<std::string, Screen*> screens;
    Screen* currentScreen;

    // Estructura para almacenar el estado y el tiempo de debounce de cada botón
    struct Button {
        int pin;
        bool state;
        unsigned long lastDebounceTime;
    };

    // Crear instancias para los botones
    Button buttons[3];

    void lvgl_init();
    void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
};

#endif