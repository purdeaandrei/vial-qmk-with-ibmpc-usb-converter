/*
Copyright 2016 Jun Wako <wakojun@gmail.com>
*/
#ifndef _UNIMAP_H_
#define _UNIMAP_H_

#include <stdint.h>
#include <stdbool.h>

// Universal map table: 8x16=128key
#define UNIMAP_ROWS 8
#define UNIMAP_COLS 16

// Universal map position codes
enum unimap_position_codes {
//  logical name            position(row << 4 | col)
//  ------------------------------------------------
    UNIMAP_KANA,            // 0x00
    UNIMAP_VOLUME_DOWN,     // 0x01
    UNIMAP_VOLUME_UP,       // 0x02
    UNIMAP_VOLUME_MUTE,     // 0x03
    UNIMAP_A,               // 0x04
    UNIMAP_B,               // 0x05
    UNIMAP_C,               // 0x06
    UNIMAP_D,               // 0x07
    UNIMAP_E,               // 0x08
    UNIMAP_F,               // 0x09
    UNIMAP_G,               // 0x0A
    UNIMAP_H,               // 0x0B
    UNIMAP_I,               // 0x0C
    UNIMAP_J,               // 0x0D
    UNIMAP_K,               // 0x0E
    UNIMAP_L,               // 0x0F
    UNIMAP_M,               // 0x10
    UNIMAP_N,               // 0x11
    UNIMAP_O,               // 0x12
    UNIMAP_P,               // 0x13
    UNIMAP_Q,               // 0x14
    UNIMAP_R,               // 0x15
    UNIMAP_S,               // 0x16
    UNIMAP_T,               // 0x17
    UNIMAP_U,               // 0x18
    UNIMAP_V,               // 0x19
    UNIMAP_W,               // 0x1A
    UNIMAP_X,               // 0x1B
    UNIMAP_Y,               // 0x1C
    UNIMAP_Z,               // 0x1D
    UNIMAP_1,               // 0x1E
    UNIMAP_2,               // 0x1F
    UNIMAP_3,               // 0x20
    UNIMAP_4,               // 0x21
    UNIMAP_5,               // 0x22
    UNIMAP_6,               // 0x23
    UNIMAP_7,               // 0x24
    UNIMAP_8,               // 0x25
    UNIMAP_9,               // 0x26
    UNIMAP_0,               // 0x27
    UNIMAP_ENTER,           // 0x28
    UNIMAP_ESCAPE,          // 0x29
    UNIMAP_BSPACE,          // 0x2A
    UNIMAP_TAB,             // 0x2B
    UNIMAP_SPACE,           // 0x2C
    UNIMAP_MINUS,           // 0x2D
    UNIMAP_EQUAL,           // 0x2E
    UNIMAP_LBRACKET,        // 0x2F
    UNIMAP_RBRACKET,        // 0x30
    UNIMAP_BSLASH,          // 0x31
    UNIMAP_NONUS_HASH,      // 0x32 ISO UK hash
    UNIMAP_SCOLON,          // 0x33
    UNIMAP_QUOTE,           // 0x34
    UNIMAP_GRAVE,           // 0x35
    UNIMAP_COMMA,           // 0x36
    UNIMAP_DOT,             // 0x37
    UNIMAP_SLASH,           // 0x38
    UNIMAP_CAPSLOCK,        // 0x39
    UNIMAP_F1,              // 0x3A
    UNIMAP_F2,              // 0x3B
    UNIMAP_F3,              // 0x3C
    UNIMAP_F4,              // 0x3D
    UNIMAP_F5,              // 0x3E
    UNIMAP_F6,              // 0x3F
    UNIMAP_F7,              // 0x40
    UNIMAP_F8,              // 0x41
    UNIMAP_F9,              // 0x42
    UNIMAP_F10,             // 0x43
    UNIMAP_F11,             // 0x44
    UNIMAP_F12,             // 0x45
    UNIMAP_PSCREEN,         // 0x46
    UNIMAP_SCROLLLOCK,      // 0x47
    UNIMAP_PAUSE,           // 0x48
    UNIMAP_INSERT,          // 0x49
    UNIMAP_HOME,            // 0x4A
    UNIMAP_PGUP,            // 0x4B
    UNIMAP_DELETE,          // 0x4C
    UNIMAP_END,             // 0x4D
    UNIMAP_PGDOWN,          // 0x4E
    UNIMAP_RIGHT,           // 0x4F
    UNIMAP_LEFT,            // 0x50
    UNIMAP_DOWN,            // 0x51
    UNIMAP_UP,              // 0x52
    UNIMAP_NUMLOCK,         // 0x53
    UNIMAP_KP_SLASH,        // 0x54
    UNIMAP_KP_ASTERISK,     // 0x55
    UNIMAP_KP_MINUS,        // 0x56
    UNIMAP_KP_PLUS,         // 0x57
    UNIMAP_KP_ENTER,        // 0x58
    UNIMAP_KP_1,            // 0x59
    UNIMAP_KP_2,            // 0x5A
    UNIMAP_KP_3,            // 0x5B
    UNIMAP_KP_4,            // 0x5C
    UNIMAP_KP_5,            // 0x5D
    UNIMAP_KP_6,            // 0x5E
    UNIMAP_KP_7,            // 0x5F
    UNIMAP_KP_8,            // 0x60
    UNIMAP_KP_9,            // 0x61
    UNIMAP_KP_0,            // 0x62
    UNIMAP_KP_DOT,          // 0x63
    UNIMAP_NONUS_BSLASH,    // 0x64 ISO UK backslash
    UNIMAP_APPLICATION,     // 0x65
    UNIMAP_KP_COMMA,        // 0x66
    UNIMAP_KP_EQUAL,        // 0x67
    UNIMAP_F13,             // 0x68
    UNIMAP_F14,             // 0x69
    UNIMAP_F15,             // 0x6A
    UNIMAP_F16,             // 0x6B
    UNIMAP_F17,             // 0x6C
    UNIMAP_F18,             // 0x6D
    UNIMAP_F19,             // 0x6E
    UNIMAP_F20,             // 0x6F
    UNIMAP_F21,             // 0x70
    UNIMAP_F22,             // 0x71
    UNIMAP_F23,             // 0x72
    UNIMAP_F24,             // 0x73
    UNIMAP_JYEN,            // 0x74
    UNIMAP_RO,              // 0x75
    UNIMAP_HENK,            // 0x76
    UNIMAP_MHEN,            // 0x77
    UNIMAP_LCTRL,           // 0x78
    UNIMAP_LSHIFT,          // 0x79
    UNIMAP_LALT,            // 0x7A
    UNIMAP_LGUI,            // 0x7B
    UNIMAP_RCTRL,           // 0x7C
    UNIMAP_RSHIFT,          // 0x7D
    UNIMAP_RALT,            // 0x7E
    UNIMAP_RGUI,            // 0x7F
    UNIMAP_NO,              // 0x80
};

/*
 * Short names
 */
#define UNIMAP_LCTL UNIMAP_LCTRL
#define UNIMAP_RCTL UNIMAP_RCTRL
#define UNIMAP_LSFT UNIMAP_LSHIFT
#define UNIMAP_RSFT UNIMAP_RSHIFT
#define UNIMAP_ESC  UNIMAP_ESCAPE
#define UNIMAP_BSPC UNIMAP_BSPACE
#define UNIMAP_ENT  UNIMAP_ENTER
#define UNIMAP_DEL  UNIMAP_DELETE
#define UNIMAP_INS  UNIMAP_INSERT
#define UNIMAP_CAPS UNIMAP_CAPSLOCK
#define UNIMAP_CLCK UNIMAP_CAPSLOCK
#define UNIMAP_RGHT UNIMAP_RIGHT
#define UNIMAP_PGDN UNIMAP_PGDOWN
#define UNIMAP_PSCR UNIMAP_PSCREEN
#define UNIMAP_SLCK UNIMAP_SCROLLLOCK
#define UNIMAP_PAUS UNIMAP_PAUSE
#define UNIMAP_BRK  UNIMAP_PAUSE
#define UNIMAP_NLCK UNIMAP_NUMLOCK
#define UNIMAP_SPC  UNIMAP_SPACE
#define UNIMAP_MINS UNIMAP_MINUS
#define UNIMAP_EQL  UNIMAP_EQUAL
#define UNIMAP_GRV  UNIMAP_GRAVE
#define UNIMAP_RBRC UNIMAP_RBRACKET
#define UNIMAP_LBRC UNIMAP_LBRACKET
#define UNIMAP_COMM UNIMAP_COMMA
#define UNIMAP_BSLS UNIMAP_BSLASH
#define UNIMAP_SLSH UNIMAP_SLASH
#define UNIMAP_SCLN UNIMAP_SCOLON
#define UNIMAP_QUOT UNIMAP_QUOTE
#define UNIMAP_APP  UNIMAP_APPLICATION
#define UNIMAP_NUHS UNIMAP_NONUS_HASH
#define UNIMAP_NUBS UNIMAP_NONUS_BSLASH
/* Japanese specific */
#define UNIMAP_ZKHK UNIMAP_GRAVE
#define UNIMAP_JPY  UNIMAP_JYEN
/* Keypad */
#define UNIMAP_P1   UNIMAP_KP_1
#define UNIMAP_P2   UNIMAP_KP_2
#define UNIMAP_P3   UNIMAP_KP_3
#define UNIMAP_P4   UNIMAP_KP_4
#define UNIMAP_P5   UNIMAP_KP_5
#define UNIMAP_P6   UNIMAP_KP_6
#define UNIMAP_P7   UNIMAP_KP_7
#define UNIMAP_P8   UNIMAP_KP_8
#define UNIMAP_P9   UNIMAP_KP_9
#define UNIMAP_P0   UNIMAP_KP_0
#define UNIMAP_PDOT UNIMAP_KP_DOT
#define UNIMAP_PCMM UNIMAP_KP_COMMA
#define UNIMAP_PSLS UNIMAP_KP_SLASH
#define UNIMAP_PAST UNIMAP_KP_ASTERISK
#define UNIMAP_PMNS UNIMAP_KP_MINUS
#define UNIMAP_PPLS UNIMAP_KP_PLUS
#define UNIMAP_PEQL UNIMAP_KP_EQUAL
#define UNIMAP_PENT UNIMAP_KP_ENTER
/* Consumer Page */
#define UNIMAP_MUTE UNIMAP_VOLUME_MUTE
#define UNIMAP_VOLU UNIMAP_VOLUME_UP
#define UNIMAP_VOLD UNIMAP_VOLUME_DOWN

#endif
