/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _UTIL,
  _SYMB,
  _NUMS,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  UTIL
};

#define SYMB MO(_SYMB)
#define NUMS MO(_NUMS)
#define CAPS_SH LSFT_T(KC_CAPSLOCK)
#define ENT_SH RSFT_T(KC_ENT)
#define SP_SYMB LT(SYMB, KC_SPC)
#define SP_NUMS LT(NUMS, KC_SPC)

// Greek key codes
// uppercase
#define UALPH 0x0391
#define UBETA 0x0392
#define UGAMM 0x0393
#define UDELT 0x0394
#define UEPSI 0x0395
#define UZETA 0x0396
#define UETA  0x0397
#define UTHET 0x0398
#define UIOTA 0x0399
#define UKAPP 0x039A
#define ULAMB 0x039B
#define UMU   0x039C
#define UNU   0x039D
#define UXI   0x039E
#define UOMIC 0x039F
#define UPI   0x03A0
#define URHO  0x03A1
#define USIGM 0x03A3
#define UTAU  0x03A4
#define UUPSI 0x03A5
#define UPHI  0x03A6
#define UCHI  0x03A7
#define UPSI  0x03A8
#define UOMEG 0x03A9

// lowercase
#define LALPH 0x03B1
#define LBETA 0x03B2
#define LGAMM 0x03B3
#define LDELT 0x03B4
#define LEPSI 0x03B5
#define LZETA 0x03B6
#define LETA  0x03B7
#define LTHET 0x03B8
#define LIOTA 0x03B9
#define LKAPP 0x03BA
#define LLAMB 0x03BB
#define LMU   0x03BC
#define LNU   0x03BD
#define LXI   0x03BE
#define LOMIC 0x03BF
#define LPI   0x03C0
#define LRHO  0x03C1
#define LSIGM 0x03C3
#define LTAU  0x03C4
#define LUPSI 0x03C5
#define LPHI  0x03C6
#define LCHI  0x03C7
#define LPSI  0x03C8
#define LOMEG 0x03C9

#define FSIGM 0x03C2
// uppercase tonos
#define UALTO 0x0386
#define UEPTO 0x0388
#define UETTO 0x0389
#define UIOTO 0x038A
#define UOMTO 0x038C
#define UUPTO 0x038E
#define UOOTO 0x038F
// lowercase tonos
#define LALTO 0x03AC
#define LEPTO 0x03AD
#define LETTO 0x03AE
#define LIOTO 0x03AF
#define LOMTO 0x03CC
#define LUPTO 0x03CD
#define LOOTO 0x03CE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Util | GUI  |    Space    |    Space    | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_2x2u(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    CAPS_SH, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SH,
    KC_LCTL, KC_LALT, UTIL, KC_LGUI, SP_SYMB, SP_NUMS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),


/* Util
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |Qwerty|      |             |             |      | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_UTIL] = LAYOUT_planck_2x2u(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,    _______,
	_______, _______, QWERTY, _______,     _______     ,     _______     , _______, KC_LEFT, KC_DOWN,    KC_RGHT
),


/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMB] = LAYOUT_planck_2x2u(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______,     _______     ,     _______     , KC_MNXT, KC_VOLD,  KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMS] = LAYOUT_planck_2x2u(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______,     _______     ,     _______     , KC_MNXT, KC_VOLD,  KC_VOLU, KC_MPLY
),


/* Adjust (Symbol + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_2x2u(
    RESET, _______,  DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______,  _______,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______,     _______     ,     _______     , _______, _______,  _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _SYMB, _NUMS, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case UTIL:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_UTIL);
      }
      return false;
      break;
  }
  return true;
}

// bool muse_mode = false;
// uint8_t last_muse_note = 0;
// uint16_t muse_counter = 0;
// uint8_t muse_offset = 70;
// uint16_t muse_tempo = 50;
// 
// void encoder_update(bool clockwise) {
//   if (muse_mode) {
//     if (IS_LAYER_ON(_NUMS)) {
//       if (clockwise) {
//         muse_offset++;
//       } else {
//         muse_offset--;
//       }
//     } else {
//       if (clockwise) {
//         muse_tempo+=1;
//       } else {
//         muse_tempo-=1;
//       }
//     }
//   } else {
//     if (clockwise) {
//       #ifdef MOUSEKEY_ENABLE
//         register_code(KC_MS_WH_DOWN);
//         unregister_code(KC_MS_WH_DOWN);
//       #else
//         register_code(KC_PGDN);
//         unregister_code(KC_PGDN);
//       #endif
//     } else {
//       #ifdef MOUSEKEY_ENABLE
//         register_code(KC_MS_WH_UP);
//         unregister_code(KC_MS_WH_UP);
//       #else
//         register_code(KC_PGUP);
//         unregister_code(KC_PGUP);
//       #endif
//     }
//   }
// }
// 
// void dip_update(uint8_t index, bool active) {
//   switch (index) {
//     case 0:
//       if (active) {
// //         #ifdef AUDIO_ENABLE
// //           PLAY_SONG(plover_song);
// //         #endif
//         layer_on(_ADJUST);
//       } else {
// //         #ifdef AUDIO_ENABLE
// //           PLAY_SONG(plover_gb_song);
// //         #endif
//         layer_off(_ADJUST);
//       }
//       break;
//     case 1:
//       if (active) {
//         muse_mode = true;
//       } else {
//         muse_mode = false;
//         #ifdef AUDIO_ENABLE
//           stop_all_notes();
//         #endif
//       }
//    }
// }
// 
// void matrix_scan_user(void) {
//   #ifdef AUDIO_ENABLE
//     if (muse_mode) {
//       if (muse_counter == 0) {
//         uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
//         if (muse_note != last_muse_note) {
//           stop_note(compute_freq_for_midi_note(last_muse_note));
//           play_note(compute_freq_for_midi_note(muse_note), 0xF);
//           last_muse_note = muse_note;
//         }
//       }
//       muse_counter = (muse_counter + 1) % muse_tempo;
//     }
//   #endif
// }
// 
// bool music_mask_user(uint16_t keycode) {
//   switch (keycode) {
//     case NUMS:
//     case SYMB:
//       return false;
//     default:
//       return true;
//   }
// }

// This just doesn't work correctly...
// It works the same way without the following as with.

// #ifdef UNICODE_KEY_LNX
//   #undef UNICODE_KEY_LNX
// #endif
// // default is LCTL(LSFT(KC_U))
// #define UNICODE_KEY_LNX LCTL(LSFT(KC_E))
// void matrix_init_user(void) {
//   // UC_WIN, UC_OSX or UC_LNX to se Unicode Input Mode of the OS
//   // This sort of works for my Debian box but not with all apps. Kate and Dolphin (KDE) don't not work
//   // correctly but it does in Gnome mostly (gedit, terminal). When it doesn't work it just outputs the
//   // raw codes without composing them into a character.
//   
//     set_unicode_input_mode(UC_LNX); // REPLACE UC_XXXX with the Unicode Input Mode for your OS. See table below.
// }
