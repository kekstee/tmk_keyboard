#include "keymap_common.h"
#include "backlight.h"

// bootloader == LSFT RSFT PAUS

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = KEYMAP_60(
         ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSLS, GRV, \
         TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSPC, \
        LCTL,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT,      ENT, \
        LSFT,  NO,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT, FN0, \
          NO,LGUI,LALT,           SPC,                      NO,RALT,RGUI,  NO),
    [1] = KEYMAP_60(
         PWR,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, INS, DEL, \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,  UP,TRNS,TRNS, \
        TRNS,VOLD,VOLU,MUTE,EJCT,TRNS,TRNS,TRNS,HOME,PGUP,LEFT,RGHT,     PENT, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,END ,PGDN,DOWN,TRNS,TRNS, \
        TRNS,TRNS,TRNS,           FN2,                    TRNS,TRNS,TRNS,TRNS),
    [2] = KEYMAP_60(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
         FN7,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, FN3,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, FN4,TRNS,TRNS, \
        TRNS,TRNS,TRNS,           FN2,                    TRNS,TRNS,TRNS,TRNS),
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [2] = ACTION_LAYER_MOMENTARY(2),
    [3] = ACTION_BACKLIGHT_INCREASE(),
    [4] = ACTION_BACKLIGHT_DECREASE(),
    [7] = ACTION_BACKLIGHT_TOGGLE()
};
