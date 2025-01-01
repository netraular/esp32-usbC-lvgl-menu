#include <Arduino.h>
#include "screens/ScreenManager.h"
#include "screens/MainScreen/MainScreen.h"
#include "screens/SecondScreen/SecondScreen.h"
ScreenManager screenManager;
MainScreen mainScreen;
SecondScreen secondScreen;

// Variable para la pequeña pausa
const uint32_t FRAME_INTERVAL = 1000 / 30;

// Instancia de la pantalla TFT
TFT_eSPI tft = TFT_eSPI();

// Buffer para LVGL
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[TFT_WIDTH * 10]; // Buffer para LVGL (10 líneas)

// Tiempo de debounce para los botones
unsigned long last_debounce_time = 0;
const unsigned long debounce_delay = 200;


// Función de flush para LVGL (envía los datos a la pantalla)
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp); // Indica que el flush ha terminado
}

// Función para inicializar LVGL
void lvgl_init() {
    tft.begin();
    tft.fillScreen(TFT_BLACK);
    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, TFT_WIDTH * 10);

    // Configurar la pantalla en LVGL
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = TFT_WIDTH;
    disp_drv.ver_res = TFT_HEIGHT;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
}

void create_gui() {
    // Crear un contenedor principal
    lv_obj_t *cont = lv_obj_create(lv_scr_act());
    lv_obj_set_size(cont, TFT_WIDTH, TFT_HEIGHT);
    lv_obj_align(cont, LV_ALIGN_CENTER, 0, 0);
    
    lv_obj_t* label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Main Screen");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    Serial.println("MainScreen cargada.");
}
void setup() {
    Serial.begin(115200);
    Serial.println("Inicializando el sistema...");

    // Inicializar la pantalla TFT y LVGL
    lvgl_init();
    
    create_gui();

    Serial.println("Setup completado.");
}
void loop() {
    // Actualizar el ScreenManager (LVGL y la pantalla activa) con una pequeña pausa
    static uint32_t last_frame_time = millis(); // Tiempo del último fotograma
    uint32_t current_time = millis();
    uint32_t elapsed_time = current_time - last_frame_time; // Tiempo transcurrido desde el último fotograma

    // Actualizar cada fotograma (30 FPS)
    if (elapsed_time >= FRAME_INTERVAL) {
        last_frame_time = current_time; // Reiniciar el tiempo del último fotograma

        // Actualizar LVGL con el tiempo transcurrido
        lv_tick_inc(elapsed_time);
        lv_timer_handler(); // Manejar las tareas de LVGL
    }
}