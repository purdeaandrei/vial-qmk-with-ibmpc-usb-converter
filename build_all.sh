#!/bin/bash
set -e
for keymap in vial vial_VERY_INSECURE; do
    for var in atmega32u2_atmel_dfu atmega32u2_usbasploader atmega32u4_atmel_dfu atmega32u4_bootloadhid atmega32u4_caterina atmega32u4_halfkay atmega32u4_qmk_dfu atmega32u4_qmk_hid atmega32u4_usbasploader; do
        make -j converter/ibmpc_usb/$var:$keymap
    done
done
