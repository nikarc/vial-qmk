#pragma once

#define VENDOR_ID     0xFEAE

#undef PRODUCT_ID
#define PRODUCT_ID    0x8847

#undef DEVICE_VER
#define DEVICE_VER    0x0001

/* #define DESCRIPTION   Hotswap MiniVan 40% */

#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS { D7, B5, F7, D4 }
#define MATRIX_COL_PINS { D2, D3, D5, D6, B4, B6, F6, F5, F4, F1, F0, B3 }


#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_LEVELS 1
#define BACKLIGHT_PIN B7

#define DEBOUNCE 5
#define TAPPING_TERM 170

#define USB_MAX_POWER_CONSUMPTION 100
#define PERMISSIVE_HOLD
#define RGB_DI_PIN D0
#define RGBLIGHT_LED_COUNT 3
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#define IS_COMMAND() ( keyboard_report->mods == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)) )

#define AUTO_SHIFT_TIMEOUT 150
#define NO_AUTO_SHIFT_ALPHA

/* #define COMBO_COUNT 5 */

#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL

#define VIAL_KEYBOARD_UID {0x0A, 0x00, 0x3A, 0x48, 0x54, 0x8E, 0x3E, 0x9C}
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 11 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 6
