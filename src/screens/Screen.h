#ifndef SCREEN_H
#define SCREEN_H

#include <lvgl.h>

class Screen {
public:
    virtual ~Screen() {}
    virtual void load() = 0;
    virtual void update() = 0;
    virtual void handleButtonPress(int button) = 0;
};

#endif