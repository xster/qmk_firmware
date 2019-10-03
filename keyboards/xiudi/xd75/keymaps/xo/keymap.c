/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// You might want to alter this to something that matches the keycap LED colors
// you installed.
#define BASE_COLOR 166, 255, 255

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_5x15(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_GRV, KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC, KC_BSLS, KC_RBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
    KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_MINS, KC_DEL, KC_EQL, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, LCTL_T(KC_Z), LALT_T(KC_X), KC_C, KC_V, KC_B, KC_GRV, KC_UP, KC_PGDN, KC_N, KC_M, KC_COMM, RALT_T(KC_DOT), RCTL_T(KC_SLSH), KC_RSFT,
    TT(1), KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, KC_ENT, KC_RGUI, KC_RALT, KC_RCTL, TT(1)),
  [1] = LAYOUT_ortho_5x15(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_P7, KC_P8, KC_P9, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
    LCTL(KC_GRV), KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PMNS, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PAST, KC_PSLS, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU,
    MO(2), KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_P0, KC_SLSH, KC_PDOT, KC_PENT, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT,
    TG(1), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ASTR, KC_PENT, KC_PENT, MO(1), KC_TRNS, KC_TRNS, TG(1)),
  [2] = LAYOUT_ortho_5x15(
    QK_BOOT, KC_SLEP, KC_WAKE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BL_DOWN, BL_UP, BL_TOGG,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_RMOD, RGB_MOD, RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, RGB_VAD, RGB_VAI, RGB_TOG)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    backlight_level(4);
  } else {
    backlight_level(6);
  }

  if (IS_MOD(keycode)) {
    if (record->event.pressed) {
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv_noeeprom(HSV_RED);
    } else {
      rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 1);
      rgblight_sethsv_noeeprom(BASE_COLOR);
    }
    rgblight_enable();
  }

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case 0:
      rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 1);
      rgblight_sethsv_noeeprom(BASE_COLOR);
      break;
    case 1:
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv_noeeprom(HSV_GREEN);
      break;
    case 2:
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv_noeeprom(HSV_PURPLE);
      break;
    }
  rgblight_enable();
  return state;
}
