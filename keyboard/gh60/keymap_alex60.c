#include "keymap_common.h"
#include "action_layer.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = KEYMAP_HHKB(
         ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSLS, GRV, \
         TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSPC, \
        CAPS,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT,      ENT, \
        LSFT,        Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT, FN0, \
        LCTL,LGUI,LALT,           SPC,               NO  ,     RALT,RGUI,RCTL),
    [1] = KEYMAP_HHKB(
         PWR,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, INS, DEL, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,UP  ,TRNS,TRNS, \
         FN1,VOLD,VOLU,MUTE,EJCT,TRNS,TRNS,TRNS,HOME,PGUP,LEFT,RGHT,     PENT, \
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, END,PGDN,DOWN,TRNS,TRNS, \
        TRNS,TRNS,TRNS,           FN2,               TRNS,     TRNS,TRNS,TRNS),
    [2] = KEYMAP_HHKB(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  UP,TRNS, \
        TRNS,TRNS,TRNS,          TRNS,               TRNS,     LEFT,DOWN,RGHT),
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_TOGGLE(2),
    [2] = ACTION_BACKLIGHT_LEVEL(1),
};

