#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "Screen.h"
#include <TFT_eSPI.h>

class ScreenManager {
public:
    ScreenManager(TFT_eSPI& tft);
    void init();
    void setScreen(Screen* newScreen);
    void update();
    void handleButtonPress(int button);

private:
    TFT_eSPI& tft;
    Screen* currentScreen;
    void lvgl_init();
    void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
};

#endif