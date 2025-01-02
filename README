# ESP32 LVGL Menu Management Project

This project demonstrates how to create a modular and scalable menu system using LVGL (Light and Versatile Graphics Library) on an ESP32 microcontroller. The project is structured using object-oriented programming (OOP) principles to ensure modularity, scalability, and maintainability.

---

## **Features**
- **Modular Screen Management**: Easily add and switch between screens using the `ScreenManager` class.
- **Button Handling**: Debounced button input for reliable event handling.
- **Buzzer Feedback**: Audible feedback for button presses and screen transitions.
- **LVGL Integration**: Leverages LVGL for creating smooth and responsive graphical interfaces.
- **TFT Display Support**: Compatible with ST7735-based TFT displays.

---

## **Hardware Requirements**
- **ESP32 Development Board**
- **ST7735 TFT Display** (128x160 pixels)
- **Buzzer**
- **3 Push Buttons**
- **Resistors** (for button pull-up/pull-down, if needed)
- **Breadboard and Jumper Wires**

---

## **Hardware Connections**

### **TFT Display Connections**
| TFT Pin    | ESP32 Pin |
| ---------- | --------- |
| SCK        | GPIO18    |
| SDA (MOSI) | GPIO23    |
| A0 (DC)    | GPIO2     |
| RESET      | GPIO14    |
| CS         | GPIO5     |
| GND        | GND       |
| VCC        | 3V3       |
| LED        | 3V3       |

### **Buzzer Connections**
| Buzzer Pin | ESP32 Pin |
|------------|-----------|
| Positive   | GPIO25    |
| Negative   | GND       |

### **Button Connections**
| Button   | ESP32 Pin |
| -------- | --------- |
| Button 1 | GPIO26    |
| Button 2 | GPIO27    |
| Button 3 | GPIO32    |

**Note**: The buttons are connected using internal pull-up resistors. When a button is pressed, the corresponding GPIO pin reads `LOW`.

---

## **Software Requirements**
- **PlatformIO**: For building and uploading the project.
- **LVGL**: Light and Versatile Graphics Library.
- **TFT_eSPI**: Library for driving the TFT display.

---

## **Project Structure**
The project is organized into the following structure:

```
src/
├── main.cpp
├── screens/
│   ├── ScreenManager.h
│   ├── ScreenManager.cpp
│   ├── Screen.h
│   ├── Screen.cpp
│   ├── MainScreen/
│   │   ├── MainScreen.h
│   │   └── MainScreen.cpp
│   ├── SecondScreen/
│   │   ├── SecondScreen.h
│   │   └── SecondScreen.cpp
```

---

## **Configuration**

### **LVGL Configuration**
The following configurations were applied in `lv_conf.h`:

```c
/*1: Enable system monitor component*/
#define LV_USE_SYSMON   1
    /*1: Show CPU usage and FPS count
     * Requires `LV_USE_SYSMON = 1`*/
    #define LV_USE_PERF_MONITOR 1

/*1: Enable grid navigation*/
#define LV_USE_GRIDNAV 1
```

### **TFT_eSPI Configuration**
The following configurations were applied in `.pio/libdeps/esp32dev/TFT_eSPI/User_Setup.h`:

```c
#define USER_SETUP_INFO "User_Setup"
#define ST7735_DRIVER
#define TFT_RGB_ORDER TFT_RGB
#define TFT_WIDTH  128
#define TFT_HEIGHT 160
#define TFT_BL   5
#define TFT_BACKLIGHT_ON HIGH
#define TFT_MISO  PIN_D6
#define TFT_MOSI  23
#define TFT_SCLK  18
#define TFT_CS    19
#define TFT_DC    21
#define TFT_RST   22
#define TOUCH_CS -1
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT
#define SPI_FREQUENCY  27000000
#define SPI_READ_FREQUENCY  20000000
#define SPI_TOUCH_FREQUENCY  2500000
```

---

## **Getting Started**

### **1. Clone the Repository**
```bash
git clone https://github.com/netraular/esp32-usbC-lvgl-menu.git
cd esp32-usbC-lvgl-menu
```

### **2. Install Dependencies**
Ensure you have PlatformIO installed. Open the project in your IDE (e.g., VSCode) and let PlatformIO install the required libraries.

### **3. Build and Upload**
Connect your ESP32 to your computer and run the following command in the terminal:
```bash
pio run --target upload
```

### **4. Monitor the Output**
To view the serial output, run:
```bash
pio device monitor
```

---

## **Code Overview**

### **`Screen.h`**
Defines the base `Screen` class with virtual methods for loading, updating, and handling button events.

### **`ScreenManager.h`**
Manages the active screen and handles button events. It also initializes LVGL and the TFT display.

### **`MainScreen.h`**
Implements the main screen logic, including UI elements and button event handling.

### **`SecondScreen.h`**
Implements the second screen logic, including UI elements and button event handling.

### **`main.cpp`**
Initializes the hardware, registers screens with the `ScreenManager`, and runs the main loop to update the screen and handle button events.

---

## **License**
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## **Acknowledgments**
- **LVGL**: For providing a powerful and versatile graphics library.
- **TFT_eSPI**: For simplifying TFT display integration.
- **PlatformIO**: For an excellent development environment for embedded systems.

---

## **Contributing**
Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

---

## **Contact**
For questions or feedback, please open an issue on the GitHub repository or contact the project maintainer.

---

Enjoy building your ESP32 LVGL menu system! 🚀