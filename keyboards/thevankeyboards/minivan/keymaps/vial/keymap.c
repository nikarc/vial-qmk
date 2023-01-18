#include "MiniVan20221213055608.h"
enum custom_keycodes {
  M_IME = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LALT));
        return false;
    }
  }
  else {
    switch(keycode) {
      case M_IME:
        SEND_STRING(SS_UP(X_LSFT)SS_UP(X_LALT));
        return false;
    }
  }
  return true;
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* [0] = LAYOUT( */
  /*         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC */
  /*         LCTL_T(KC_ESC), KC_A, KC_R, KC_S, KC_T, KC_G, KC_K, KC_N, KC_E, KC_I, KC_O, RSFT_T(KC_ENT), */
  /*         OSM(MOD_LSFT), KC_X, KC_C, KC_D, KC_V, KC_Z, KC_M, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT, */
  /*         LT(2, KC_LEFT), TG(1), KC_LGUI, KC_NO, LT(3, KC_ENT), LT(1, KC_SPC), RALT_T(KC_DOWN), RGUI_T(KC_UP), KC_NO, RCTL_T(KC_RIGHT)), */
  [0] = LAYOUT( /* Qwerty */
            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
            LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
            MO(1), KC_LALT, KC_LGUI, KC_ENT, KC_SPC, KC_RGUI, MO(3), MO(2)),

  [1] = LAYOUT( /* Layer 1 */
          KC_GRV, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_7, KC_8, KC_9, KC_LBRC, KC_DEL,
          KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_4, KC_5, KC_6, KC_RCBR, KC_MINS,
          KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_0, KC_1, KC_2, KC_3, KC_EQL, KC_TRANS,
          KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, RESET),

  [2] = LAYOUT( /* Layer 2 */
          KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, RALT(KC_TRANS),
          KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, RALT(KC_TRANS),
          KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, RALT(KC_TRANS), RALT(KC_TRANS), KC_TRANS, RALT(KC_TRANS), RALT(KC_TRANS),
          KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, LALT(KC_TRANS), KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS),

  [3] = LAYOUT(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_NO, KC_NO, KC_TRNS, KC_TRNS,
          KC_CAPS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_NO, KC_PLUS, KC_DLR, KC_PIPE, KC_BSLS, KC_DQT,
          KC_TRNS, KC_NO, KC_SLCT, KC_PAUS, KC_VOLD, KC_VOLU, KC_MUTE, KC_MINS, KC_EQL, KC_LT, KC_GT, KC_QUES,
          KC_TRNS, KC_TRNS, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS)
};

void process_indicator_update(layer_state_t state, led_t led_state) {
  for (int i = 0; i < 3; i++) {
    rgblight_setrgb_at(0, 0, 0, i);
  }
  if (led_state.caps_lock) {
  rgblight_setrgb_at(255, 0, 0, 0);
}

    if (state & (1<<1)) {
  rgblight_setrgb_at(255, 0, 255, 0);
}

  if (state & (1<<2)) {
  rgblight_setrgb_at(0, 0, 255, 1);
}

    if (state & (1<<3)) {
  rgblight_setrgb_at(255, 255, 0, 1);
}

  if (state & (1<<1)) {
  rgblight_setrgb_at(10, 255, 125, 2);
}


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
