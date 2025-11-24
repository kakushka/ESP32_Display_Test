// ESP32_Display_Panel_Library.h – заголовочный файл для дисплея ESP32

#ifndef ESP32_PANEL_LIBRARY_H
#define ESP32_PANEL_LIBRARY_H

#include <Arduino.h>
#include <lvgl.h>

// Настройки экрана (можешь подправить под свою модель)
#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 480

// Функции инициализации и отрисовки (объявления)
void setupDisplay();
void loopDisplay();

#endif // ESP_PANEL_LIBRARY_H