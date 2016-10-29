/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/io.h>
#include "stdint.h"
#include "led.h"
#include "backlight.h"

/* GH60 LEDs
 *   GPIO pads
 *   0 F7 WASD LEDs
 *   1 F6 ESC LED
 *   2 F5 FN LED
 *   3 F4 POKER Arrow LEDs
 *   B2 Capslock LED
 *   B0 not connected
 */
inline void gh60_caps_led_on(void) { DDRB |= (1<<2); PORTB &= ~(1<<2); }
inline void gh60_poker_leds_on(void) { DDRF |= (1<<4); PORTF &= ~(1<<4); }
inline void gh60_fn_led_on(void) { DDRF |= (1<<5); PORTF &= ~(1<<5); }
inline void gh60_esc_led_on(void) { DDRF |= (1<<6); PORTF &= ~(1<<6); }
inline void gh60_wasd_leds_on(void) { DDRF |= (1<<7); PORTF &= ~(1<<7); }

inline void gh60_caps_led_off(void) { DDRB &= ~(1<<2); PORTB &= ~(1<<2); }
inline void gh60_poker_leds_off(void) { DDRF &= ~(1<<4); PORTF &= ~(1<<4); }
inline void gh60_fn_led_off(void) { DDRF &= ~(1<<5); PORTF &= ~(1<<5); }
inline void gh60_esc_led_off(void) { DDRF &= ~(1<<6); PORTF &= ~(1<<6); }
inline void gh60_wasd_leds_off(void) { DDRF &= ~(1<<7); PORTF &= ~(1<<7); }

void led_layer_set(uint32_t state)
{
    if (state & (1<<2)) {
        gh60_poker_leds_on();
    } else {
        gh60_poker_leds_off();
    }
}

void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        gh60_caps_led_on();
    } else {
        gh60_caps_led_off();
    }
}

void backlight_set(uint8_t level)
{
    (level & 1) ? gh60_esc_led_on() : gh60_esc_led_off();
}
