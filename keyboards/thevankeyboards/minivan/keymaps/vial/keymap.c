#include "MiniVan20221213055608.h"
#include QMK_KEYBOARD_H

enum custom_keycodes {
  M_IME = SAFE_RANGE,
};

static uint8_t mod_state;
bool arrow_or_letter_key(uint16_t direction, uint16_t key, uint8_t mod_state, keyrecord_t *record) {
    static bool ctrl_registered;

    if (record->event.pressed) {
        if (mod_state & MOD_MASK_CTRL) {
            unregister_mods(MOD_MASK_CTRL);
            register_code(direction);
            ctrl_registered = true;
            set_mods(mod_state);
            return false;
        }
    } else {
        if (ctrl_registered) {
            unregister_code(direction);
            ctrl_registered = false;
            return false;
        } else {
            return true;
        }
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch(keycode) {
        case KC_H: {
                return arrow_or_letter_key(KC_LEFT, KC_H, mod_state, record);
            }
        case KC_J: {
                return arrow_or_letter_key(KC_DOWN, KC_J, mod_state, record);
            }
        case KC_K: {
                return arrow_or_letter_key(KC_UP, KC_K, mod_state, record);
            }
        case KC_L: {
                return arrow_or_letter_key(KC_RIGHT, KC_L, mod_state, record);
            }
        default:
            return true;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // [0] = LAYOUT(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC,
  //         LCTL_T(KC_ESC), KC_A, KC_R, KC_S, KC_T, KC_G, KC_K, KC_N, KC_E, KC_I, KC_O, RSFT_T(KC_ENT),
  //         OSM(MOD_LSFT), KC_X, KC_C, KC_D, KC_V, KC_Z, KC_M, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,
  //         LT(2, KC_LEFT), TG(1), KC_LGUI, KC_NO, LT(3, KC_ENT), LT(1, KC_SPC), RALT_T(KC_DOWN), RGUI_T(KC_UP), KC_NO, RCTL_T(KC_RIGHT)),
  [0] = LAYOUT(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, RSFT_T(KC_ENT),
        OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,
        LT(2, KC_LEFT), TG(1), KC_LGUI, KC_NO, LT(3, KC_ENT), LT(1, KC_SPC), RALT_T(KC_DOWN), RGUI_T(KC_UP), KC_NO, RCTL_T(KC_RIGHT)),



  // [1] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
  //         KC_TAB, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_TRNS, KC_PLUS, KC_1, KC_2, KC_3, KC_ASTR, KC_TRNS,
  //         KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_TRNS,
  //         KC_TRNS, KC_TRNS, KC_NO, KC_0, KC_SPC, KC_WH_L, KC_WH_D, KC_NO, KC_WH_R),
  //
  // [2] = LAYOUT(KC_BTN2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_COLN, RALT(KC_BSPC),
  //         KC_TRNS, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_NO, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENT, RALT(KC_D),
  //         KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN1, RALT(KC_LEFT), RALT(KC_RIGHT), KC_MS_U, RALT(KC_B), RALT(KC_F),
  //         KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, LALT(KC_DEL), KC_DEL, KC_MS_L, KC_MS_D, KC_NO, KC_MS_R),
  //
  // [3] = LAYOUT(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_NO, KC_NO, KC_TRNS, KC_TRNS,
  //         KC_CAPS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_NO, KC_PLUS, KC_DLR, KC_PIPE, KC_BSLS, KC_DQT,
  //         KC_TRNS, KC_NO, KC_SLCT, KC_PAUS, KC_VOLD, KC_VOLU, KC_MUTE, KC_MINS, KC_EQL, KC_LT, KC_GT, KC_QUES,
  //         KC_TRNS, KC_TRNS, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS)
};

void process_indicator_update(layer_state_t state, led_t led_state) {
  // Clear the first three LEDs
  for (int i = 0; i < 3; i++) {
    rgblight_setrgb_at(0, 0, 0, i);
  }

  // Caps Lock indicator: LED 0 turns red
  if (led_state.caps_lock) {
    rgblight_setrgb_at(255, 0, 0, 0);
  }

  // Layer 1: Set RGB 0 to magenta
  if (state & (1<<1)) {
    rgblight_setrgb_at(255, 0, 255, 0);  // Magenta on LED 0
  }

  // Layer 2: Set RGB 1 to blue
  if (state & (1<<2)) {
    rgblight_setrgb_at(0, 0, 255, 1);  // Blue on LED 1
  }

  // Layer 3: Set RGB 2 to yellow
  if (state & (1<<3)) {
    rgblight_setrgb_at(255, 255, 0, 2);  // Yellow on LED 2
  }

  // Layer 4: Set RGB 0 to cyan and RGB 1 to orange
  if (state & (1<<4)) {
    rgblight_setrgb_at(0, 255, 255, 0);  // Cyan on LED 0
    rgblight_setrgb_at(255, 165, 0, 1);  // Orange on LED 1
  }

  // Layer 5: Set RGB 1 to purple and RGB 2 to green
  if (state & (1<<5)) {
    rgblight_setrgb_at(128, 0, 128, 1);  // Purple on LED 1
    rgblight_setrgb_at(0, 255, 0, 2);    // Green on LED 2
  }

  // Apply the changes to RGB lights
  rgblight_set();
};

void keyboard_post_init_user(void) {
  process_indicator_update(layer_state, host_keyboard_led_state());
};

void led_set_user(uint8_t usb_led) {
  process_indicator_update(layer_state, host_keyboard_led_state());
};

layer_state_t layer_state_set_user(layer_state_t state) {
  process_indicator_update(state, host_keyboard_led_state());
    return state;
};

/* const uint16_t PROGMEM test_combo1[] = {KC_D, KC_V, COMBO_END}; */
/* const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END}; */
/* const uint16_t PROGMEM test_combo3[] = {KC_C, KC_X, COMBO_END}; */
/* const uint16_t PROGMEM test_combo4[] = {KC_COMM, KC_H, COMBO_END}; */
/* combo_t key_combos[COMBO_COUNT] = { */
/*     COMBO(test_combo1, LGUI(KC_V)), */
/*     COMBO(test_combo2, LGUI(KC_C)), */
/*     COMBO(test_combo3, LGUI(KC_X)), */
/*     COMBO(test_combo4, KC_MINS), */
/* }; */
