/*
Copyright 2014 Ralf Schmitt <ralf@bunkertor.net>

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
#include "backlight.h"
#include "led.h"

void backlight_init_ports()
{
/* LEDs are on output compare pins OC1B OC1C
   This activates fast PWM mode on them.
   Prescaler 256 and 8-bit counter results in
   16000000/256/256 = 244 Hz blink frequency.
   Output on PWM pins are turned off when the timer
   reaches the value in the output compare register,
   and are turned on when it reaches TOP (=256). */
    TCCR1A |=      // Timer control register 1A
        (1<<WGM10) | // Fast PWM 8-bit
        (1<<COM1B1)| // Clear OC1B on match, set at TOP
        (1<<COM1C1); // Clear OC1C on match, set at TOP
    TCCR1B |=      // Timer control register 1B
        (1<<WGM12) | // Fast PWM 8-bit
        (1<<CS12);   // Prescaler 256

    // enable output
    DDRB |= 0b11100000; // PB7 (switch), PB6 (pcb), PB5 (caps)
}

void led_set(uint8_t usb_led)
{
    (usb_led & (1<<USB_LED_CAPS_LOCK)) ? backlight_caps_enable() : backlight_caps_disable();
}

void backlight_set(uint8_t level)
{
    if (level == 0) {
        // disable PWM and make sure outputs are off
        TCCR1A &= (1<<COM1B1) | (1<<COM1C1);
        PORTB &= ~0b11000000;
    } else {
        TCCR1A |= (1<<WGM10) | (1<<COM1B1) |(1<<COM1C1);
        uint8_t scaled = level * level * BACKLIGHT_SCALE - 1;
        OCR1B = scaled; // Output compare register 1B (PB7 - switch)
        OCR1C = scaled; // Output compare register 1C (PB6 - pcb)
    }
}

void backlight_caps_enable()
{
    PORTB |= 0b00100000;
}

void backlight_caps_disable()
{
    PORTB &= ~0b00100000;
}

void backlight_caps_invert()
{
    PORTB ^= 0b00100000;
}
