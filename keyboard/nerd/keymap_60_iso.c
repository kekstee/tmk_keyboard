#include "keymap_common.h"
#include "backlight.h"

// bootloader == LSFT RSFT PAUS

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = KEYMAP_ISO(
         ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSPC, \
         TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,NUHS, \
        CAPS,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT, ENT, \
        LSFT,NUBS,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT, FN0, \
        LCTL,LGUI,LALT,           SPC,                         RALT,RGUI,RCTL),
    [1] = KEYMAP_ISO(
         GRV,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, DEL, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,  UP, INS,TRNS, \
         FN1,VOLD,VOLU,MUTE,EJCT,TRNS,TRNS,TRNS,HOME,PGUP,LEFT,RGHT,PENT, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,END ,PGDN,DOWN,TRNS,TRNS, \
        TRNS,TRNS,TRNS,           FN2,                         TRNS,TRNS,TRNS),
    [2] = KEYMAP_ISO(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  UP,TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                         LEFT,DOWN,RGHT),
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_TOGGLE(2),
    [2] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH)
};
