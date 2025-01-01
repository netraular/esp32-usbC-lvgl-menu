#include "ScreenManager.h"
#include <lvgl.h>

ScreenManager::ScreenManager(TFT_eSPI& tft) : tft(tft), currentScreen(nullptr) {}

void ScreenManager::init() {
    lvgl_init();
}

void ScreenManager::setScreen(Screen* newScreen) {
    if (currentScreen != nullptr) {
        // Limpiar la pantalla actual si es necesario
    }
    currentScreen = newScreen;
    currentScreen->load();
}

void ScreenManager::update() {
    if (currentScreen != nullptr) {
        currentScreen->update();
    }
    lv_timer_handler();
}

void ScreenManager::handleButtonPress(int button) {
    if (currentScreen != nullptr) {
        currentScreen->handleButtonPress(button);
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