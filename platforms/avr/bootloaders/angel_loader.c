/* Copyright 2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "bootloader.h"

#include <avr/wdt.h>

#define FLASH_SIZE (FLASHEND + 1L)
#ifdef PROTOCOL_LUFA
#include <LUFA/Drivers/USB/USB.h>
#endif
#if !defined(MCUCSR)
#    if defined(MCUSR)
#        define MCUCSR MCUSR
#    endif
#endif
#define BOOTLOADER_RESET_KEY 0xB007B007
#define BOOTLOADER_START      (FLASHEND - BOOTLOADER_SIZE + 1)
uint32_t reset_key  __attribute__ ((section (".noinit")));
__attribute__((weak)) void bootloader_jump(void) {
    // Taken with permission of Stephan Baerwolf from https://github.com/tinyusbboard/API/blob/master/apipage.c
	USB_Disable();
	cli();
    // watchdog reset
    reset_key = BOOTLOADER_RESET_KEY;
    wdt_enable(WDTO_250MS);
    for (;;);
}
/* this runs before main() */
void bootloader_jump_after_watchdog_reset(void) __attribute__ ((used, naked, section (".init3")));
void bootloader_jump_after_watchdog_reset(void)
{
    if ((MCUSR & (1<<WDRF)) && reset_key == BOOTLOADER_RESET_KEY) {
        reset_key = 0;

        // some of bootloaders may need to preseve?
        MCUSR = 0;

        // disable watchdog timer
        wdt_disable();


        // This is compled into 'icall', address should be in word unit, not byte.
        ((void (*)(void))( (uint16_t)(BOOTLOADER_START / 2) ))();
    }
}

__attribute__((weak)) void mcu_reset(void) {
    // setup watchdog timeout
    wdt_enable(WDTO_15MS);

    // wait for watchdog timer to trigger
    while (1) {
    }
}

