#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _BL = 0,
  _NV,
  _FN
};

enum custom_keycodes {
  KC_DBL0 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap _BL: (Base Layer) Default Layer
 * ,-------------------.
 * | NV | /  | *  |-/FN|
 * |----|----|----|----|
 * | 7  | 8  | 9  |    |
 * |----|----|----| +  |
 * | 4  | 5  | 6  |    |
 * |----|----|----|----|
 * | 1  | 2  | 3  |    |
 * |----|----|----| En |
 * | 0  | 00 | .  |    |
 * `-------------------'
 */
  [_BL] = LAYOUT(
    TG(_NV),  KC_PSLS,  KC_PAST,   LT(_FN, KC_PMNS), \
    KC_P7,    KC_P8,    KC_P9,              \
    KC_P4,    KC_P5,    KC_P6,     KC_PPLS, \
    KC_P1,    KC_P2,    KC_P3,              \
    KC_P0,    KC_DBL0,  KC_PDOT,   KC_PENT
  ),

/* Keymap _NV: Navigation layer
 * ,-------------------.
 * |INS |HOME|PGUP|    |
 * |----|----|----|----|
 * |DEL |END |PGDN|    |
 * |----|----|----|    |
 * |    |    |    |    |
 * |----|----|----|----|
 * |    | UP |    |    |
 * |----|----|----|    |
 * |LEFT|DOWN|RIGH|    |
 * `-------------------'
 */
  [_NV] = LAYOUT(
    KC_INS,   KC_HOME,  KC_PGUP,   TG(_NV), \
    KC_DEL,   KC_END,   KC_PGDN,            \
    XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX, \
    XXXXXXX,  KC_UP,    XXXXXXX,            \
    KC_LEFT,  KC_DOWN,  KC_RGHT,   XXXXXXX
  ),

/* Keymap _FN: RGB Function Layer
 * ,-------------------.
 * |RMOD|RGBP|RTOG| FN |
 * |----|----|----|----|
 * |HUD |HUI |    |    |
 * |----|----|----|    |
 * |SAD |SAI |    |    |
 * |----|----|----|----|
 * |VAD |VAS |    |    |
 * |----|----|----|    |
 * |RST |    |    |    |
 * `-------------------'
 */
  [_FN] = LAYOUT(
    RGB_MOD,  RGB_M_P,  RGB_TOG,   _______, \
    RGB_HUD,  RGB_HUI,  XXXXXXX,            \
    RGB_SAD,  RGB_SAI,  XXXXXXX,   XXXXXXX, \
    RGB_VAD,  RGB_VAI,  XXXXXXX,            \
    RESET,    XXXXXXX,  XXXXXXX,   XXXXXXX
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_DBL0:
      if (record->event.pressed) {
        SEND_STRING("00");
      } else {
        // when keycode KC_DBL0 is released
      }
      break;

  }
  return true;
};

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 270 degrees
}

void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BL:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _NV:
            oled_write_P(PSTR("NV\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(PSTR("-----"), false);
  oled_write_P(PSTR("Stats"), false);
  oled_write_P(led_usb_state & (1<<USB_LED_NUM_LOCK) ? PSTR("num:*") : PSTR("num:."), false);
  oled_write_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("cap:*") : PSTR("cap:."), false);
  oled_write_P(led_usb_state & (1<<USB_LED_SCROLL_LOCK) ? PSTR("scr:*") : PSTR("scr:."), false);

  // Host Keyboard RGB backlight status
 
  //oled_write_ln_P(PSTR(""), false);
  oled_write_P(PSTR("-----"), false);
};
void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x02, 0x86, 0xFC, 0xFC, 0xFC, 0xF8, 0xF0, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0,
0xC0, 0xC0, 0xC0, 0x40, 0x40, 0x60, 0x60, 0x60, 0x20, 0x20, 0x20, 0x30, 0x30, 0x30, 0x10, 0x10,
0x18, 0x18, 0x18, 0x08, 0x0C, 0x0C, 0x0C, 0x0E, 0x06, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00,
0x00, 0xC0, 0xE0, 0xE0, 0xF0, 0xF0, 0x78, 0x38, 0x18, 0x1C, 0x0C, 0x0C, 0x0C, 0x04, 0x04, 0x06,
0x06, 0x06, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x1F,
0x1F, 0x1E, 0x3E, 0x3E, 0x3C, 0x7C, 0x7C, 0x78, 0xF8, 0xF8, 0xF0, 0xF0, 0xF0, 0xE0, 0xE0, 0xE0,
0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x03, 0x07, 0x0F, 0x0F, 0x1F, 0x18, 0x10, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03,
0x03, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x3E, 0x3E, 0x3E, 0x7C, 0x7C, 0x7C
    };

    oled_write_P(qmk_logo, false);
}
#endif
