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
/*
 *    The backlight LED pins PB6 and PB7 can be
 *    controlled through the output compare values in
 *    OCR1C and OCR1B.
 *    Counter1 is set to Fast PWM 8-bit mode with
 *    a prescaler divisor of 256. (WGM10, WGM12, and CS12 bits
 *    set in the control registers A/B)
 *
 *          f_clk      16000000
 *    f = --------- = ----------- =~ 244Hz 
 *        N*(1+TOP)   256*(1+255)
 *
 *    The comparision port is set to low once the counter matches
 *    our compare value (COM1x1 bit set in control register).
 *    Setting the compare register (OCR1x) to BOTTOM (=0)
 *    results in a narrow spike for each TOP+1 cycle.
 *    So the comparison output is deactivated to reach
 *    zero output.
 */
    // Timer/Counter1 Control Registers
    TCCR1A |= (1<<WGM10);
    TCCR1B |= (1<<WGM12) | (1<<CS12);

    // Enable output pins
    DDRB |= 0b11100000; // PB7 (switch), PB6 (pcb), PB5 (caps)

    // PB6 and 7 are only used by output compare
    PORTB &= ~0b11000000;
}

void backlight_set(uint8_t level)
{
    if (level == 0) {
        // Disable comparison
        TCCR1A &= ~(1<<COM1B1);
    } else {
        // Enable comparison
        TCCR1A |= (1<<COM1B1);
        // Set output compare register 1B (PB7 - switch)
        OCR1B = level * level * BACKLIGHT_SCALE - 1;
    }
}

void backlightb_set(uint8_t level)
{
    if (level == 0) {
        // Disable comparison
        TCCR1A &= ~(1<<COM1C1);
    } else {
        // Enable comparison
        TCCR1A |= (1<<COM1C1);
        // Set output compare register 1C (PB6 - pcb)
        OCR1C = level * level * BACKLIGHT_SCALE - 1;
    }
}

void led_set(uint8_t usb_led)
{
    (usb_led & (1<<USB_LED_CAPS_LOCK)) ? backlight_caps_enable() : backlight_caps_disable();
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
