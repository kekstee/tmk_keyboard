#include "action.h"
#include "action_layer.h"
#include "action_util.h"
#include "keymap_common.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* 0: qwerty
     * ,-----------------------------------------------------------.
     * |`  |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  #|Bsp|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
     * |-----------------------------------------------------------|
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Enter   |
     * |-----------------------------------------------------------|
     * |Shft|  \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Esc|
     * |-----------------------------------------------------------'
     * |Ctrl|Gui |Alt |         Space         |App |Alt |Gui |Ctrl |
     * `-----------------------------------------------------------'
     */
    [0] = KEYMAP( \
        FN1, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NUHS, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,  \
        LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN0, \
        LCTL,LGUI,LALT,          SPC,                     APP, RALT,FN0,RCTL),
    [1] = KEYMAP( \
        FN1, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS, UP, TRNS,BSPC, \
        TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,PENT, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS,END, PGDN,DOWN,TRNS,TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
};

enum function_id {
    ESCAPE
};

const action_t fn_actions[] PROGMEM = {
    [0]  = ACTION_LAYER_MOMENTARY(1),
    [1]  = ACTION_FUNCTION(ESCAPE),
};

// Circumvent the layer switching discarding pressed keys
// when using LSFT as FN for ESC/GRV toggle by turning
// ESC itself into a function
// https://github.com/p3lim/keyboard_firmware/commit/fd799c12b69a5ab5addd1d4c03380a1b8ef8e9dc
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (id == ESCAPE) {
        void (*method)(uint8_t) = (record->event.pressed) ? &add_key : &del_key;
        uint8_t shifted = get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));

        if (layer_state == 0) {
            method(shifted ? KC_GRAVE : KC_ESCAPE);
        } else {
            method(shifted ? KC_ESCAPE : KC_GRAVE);
        }

        send_keyboard_report();
    }
}

