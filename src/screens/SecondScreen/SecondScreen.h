#ifndef SECONDSCREEN_H
#define SECONDSCREEN_H

#include "../Screen.h"

class SecondScreen : public Screen {
public:
    void load() override;
    void update() override;
    void handleButtonPress(int button) override;
};

#endif