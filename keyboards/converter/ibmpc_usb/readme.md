# IBM keyboard protocol converter

This is a QMK and Vial port of hasu's TMK IBM PC Keyboard Converter, with some
added features. You can read more about the original TMK version here:
https://github.com/tmk/tmk_keyboard/wiki/IBM-PC-Keyboard-Converter

I hesitate to call this an "IBM PC" converter, though, given that the scope of
that part of TMK has grown a lot since it start, and it now incorporates
terminal keyboards as well.

The ibmpc.c and ibmpc.h code has been moved from TMK's tmk_core/protocol
directory into the appropriate "keyboard" directory in this version.

It runs on AVR chips; I have personally only tested the code on the ATmega32U4,
which this amount of code only just fits onto.

## Build

If you want to compile the Vial version without also compiling the QMK one at
the same time, move into the root director then do:
```
make converter/ibmpc_usb:vial
```

## Wiring

### Required

Keyboard | ATMega32U4
:------- | :---------
Data     | PD0
Clock    | PD1
VCC      | VCC
GND      | GND

Depending on your keyboard, your cables, and the clarity of your power source,
it may be wise to connect pull-up resistors on all of the signal lines (between
the signal line and VCC). The TMK project recommends using resistors between 1
and 4.7 kOhms. Obviously, only do this on the signal lines; don't bridge VCC to
GND!

### Required by some "XT" protocol keyboards

Keyboard | ATMega32U4
:------- | :---------
Reset    | PB6 or PB7

Some older IBM PC compatible keyboards will refuse to initialise unless you
wire up their Reset pin, and doing so won't harm keyboards that don't need it.

### Optional

Function        | ATMega32U4
:-------------- | :---------
Secondary Data  | PD2
Secondary Clock | PD3
Caps Lock LED   | PF5
Num Lock LED    | PF6
Scroll Lock LED | PF7

The secondary data/clock pair are for the PS/2 interface; for example, you could
hook up a mouse or trackball. I haven't tested this with this specific code yet
but I can tell you that if support for it is present here, it is not structured
the same way as it is in TMK (the LED functions were different in a way that
made that apparent).

Indicator LEDs are entirely optional and support for them is only included here
for convenience when using an older IBM PC keyboard or terminal keyboard that
has no LEDs of its own. If your keyboard already has indicator LEDs on it, those
will still work fine even if you don't wire up any LEDs to the converter and/or
comment out the pin definitions for the indicators in led_pins.h.


## Development Path

The initial QMK port of hasu's work with TMK, with the addition of support for
DEC VT220 layout Televideo terminal keyboards was done by Markus Fritsche:
https://github.com/marfrit/qmk_firmware/tree/ibmpc_usb_port

This was then ported to Vial and further improved by Purdea Andrei:
https://github.com/purdeaandrei/vial-qmk-with-ibmpc-usb-converter

My contribution so far is mostly smaller tweaks here and there, notably support
for converters with lock status indicator LEDs following the same pinout as the
original converters put together by Soarer. My own fork is currently here:
https://github.com/an-achronism/vial-qmk/tree/ibmpc_usb


## Additional Resources

- Soarer's Converter: http://geekhack.org/index.php?topic=17458.0
- 102keys (1392595): http://geekhack.org/index.php?topic=10737.0
- 122keys (1390876): http://www.seasip.info/VintagePC/ibm_1390876.html
- kbdbabel: http://www.kbdbabel.org/
- RJ45 connector: http://www.kbdbabel.org/conn/kbd_connector_ibmterm.png
- DIN connector: http://www.kbdbabel.org/conn/kbd_connector_ibm3179_318x_319x.png
- WinAVR: http://winavr.sourceforge.net/
