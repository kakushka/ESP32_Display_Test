#include <lvgl.h>
w#include <ESP32_Display_Panel_Library.h>

// Настройка панели дисплея AJ003 (ST7796 + CHSC6540)
ESP32DisplayPanel panel;

// LVGL объекты
lv_obj_t *label;
bool touched = false;

void setup() {
  Serial.begin(115200);

  // Инициализация дисплейной панели
  auto panel_config = PanelConfig()
    .setLCDInterface(LCD_INTERFACE_SPI)
    .setLCDDriver(LCD_DRIVER_ST7796)
    .setTouchInterface(TOUCH_INTERFACE_I2C)
    .setTouchDriver(TOUCH_DRIVER_CHSC6540);

  panel.begin(panel_config);
  Serial.println("Panel initialized");

  // Инициализация LVGL
  lv_init();
  panel.initLVGL();

  // Создание базового экрана
  lv_obj_t *scr = lv_scr_act();
  label = lv_label_create(scr);
  lv_label_set_text(label, "Garry Lab Touch OK");
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

void loop() {
  lv_timer_handler(); // Обработка LVGL задач
  delay(5);

  // Проверка на касание
  TouchPoint tp;
  if (panel.readTouch(&tp)) {
    if (!touched) {
      touched = true;
      // При первом касании меняем цвет фона
      lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0xffcccc), LV_PART_MAIN);
      lv_label_set_text(label, "Touch Detected!");
    }
  } else {
    touched = false;
  }
}
