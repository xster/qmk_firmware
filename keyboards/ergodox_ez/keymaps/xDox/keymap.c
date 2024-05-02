#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_LEFT,                                        KC_RIGHT,       KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_RBRACKET,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_DELETE,                                      KC_BSPC,      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRACKET,
    KC_BSPC,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,      KC_QUOTE,
    KC_LSFT,      LCTL_T(KC_Z),   LALT_T(KC_X),     KC_C,           KC_V,           KC_B,           KC_ENTER,                                       LCTL(KC_GRAVE), KC_N,           KC_M,           KC_COMMA,       RALT_T(KC_DOT), RCTL_T(KC_SLASH),KC_RSFT,
    LT(1,KC_GRAVE), KC_UP,          KC_DOWN,        LT(2,KC_LEFT),        SH_T(KC_RIGHT),                                                                                                       LT(1,KC_UP),    KC_DOWN,        KC_LEFT,        KC_RIGHT,       LALT(LCTL(LGUI(LSFT(KC_L)))),
                                                                                                    LALT(LCTL(LGUI(LSFT(KC_TAB)))),KC_GRAVE,       KC_MINUS,       KC_EQUAL,
                                                                                                                    KC_BSLS,      KC_PGUP,
                                                                                    KC_SPACE,       KC_LGUI,        LCTL(KC_GRAVE), KC_PGDN,      KC_SPACE,       KC_ENTER
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    LT(2,KC_NO),    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_KP_PLUS,     KC_F12,
    KC_TRANSPARENT, LGUI(KC_R),     LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),LGUI(KC_W),     KC_GRAVE,                                                                       KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_MINUS,    KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_K),     LGUI(KC_LEFT),  LGUI(KC_RIGHT), LCTL(LSFT(KC_K)), KC_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_BSPC,      KC_1,           KC_2,           KC_3,           KC_KP_ASTERISK, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, LSFT(LGUI(KC_A)),  KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_WH_RIGHT,                                                                                                 KC_TRANSPARENT, KC_KP_0,        RALT_T(KC_KP_DOT),KC_MPRV,      KC_MNXT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_F13,         KC_F15,         KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP
  ),
  [2] = LAYOUT_ergodox_pretty(
    RESET,          LCTL(LSFT(KC_POWER)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,     KC_RIGHT,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,                                                                                                     KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(LALT(KC_AUDIO_VOL_DOWN)), LSFT(LALT(KC_AUDIO_VOL_UP))
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};


