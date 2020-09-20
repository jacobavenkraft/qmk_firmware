/* Copyright 2019 Yan-Fa Li
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _TKL,
  _FUNC
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,  
  LOWER,
  RAISE,
  BACKLIT,
  TKL,
  FUNC,
  MY_PLS_EQ,
  MY_MNS_EQ,
  MY_OR_EQ,
  MY_AND_EQ,
  MY_COPY,
  MY_TM,
  MY_RGTM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_main( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,  \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),  \
  KC_LCTL, KC_LGUI, KC_LALT, FUNC,   LOWER,   KC_SPC,  KC_SPC,  RAISE,    TKL,    KC_LEFT,  KC_DOWN,   KC_RGHT  \
),

/* Lower: This is a number layer with numbers across the top and a numpad
 
 */
[_LOWER] = LAYOUT_main( \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,      KC_0,  KC_BSPC,  \
  KC_CLCK, _______, _______,_______,_______,_______, KC_ASTR,    KC_4,    KC_5,    KC_6,   KC_MINS,  KC_BSLS, \
  _______, _______, _______,_______,_______,_______, KC_SLSH,    KC_1,    KC_2,    KC_3,   KC_PLUS,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_0,  KC_DOT,   KC_EQL, _______  \
),

/* Raise: This is a symbol layer with brackets on home keys

 */
[_RAISE] = LAYOUT_main( \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,     KC_F6,    KC_F7,     KC_F8,    KC_F9,   KC_F10,  KC_F11, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH,  KC_DLR,  KC_PERC,   KC_CIRC,  KC_AMPR,   KC_ASTR,  KC_LPRN, KC_RPRN, KC_BSPC,  \
  KC_CLCK, _______, _______, KC_SLASH, KC_LCBR, KC_LBRC,   KC_RBRC,  KC_RCBR,   KC_BSLS,  KC_MINS, KC_PLUS, KC_PIPE, \
  _______, _______,_______, _______, _______, MY_PLS_EQ, MY_MNS_EQ,MY_AND_EQ, MY_OR_EQ, KC_UNDS, KC_EQL, KC_END, \
  _______, _______, _______, _______, _______,  _______,   _______,  _______,   _______,  KC_LEFT, KC_DOWN, KC_RIGHT \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_main( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_BSPC,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Ten Keyless Pad:
This is the navigation and insert/delete pad from a tenkeyless keyboard
 */
[_TKL] = LAYOUT_main( \
  _______,    _______,    _______,    _______,    _______,    _______, _______, _______,      _______,  KC_PSCR,      KC_BRK, KC_BSPC,   \
  _______,    _______,    KC_MS_U,    _______,    _______,    _______, _______, _______,      _______ , KC_INS,      KC_HOME, KC_PGUP,   \
  KC_CLCK,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_BTN1,    KC_BTN2, _______, _______,  LCTL(KC_BRK), KC_DEL ,      KC_END, KC_PGDN,   \
  KC_LSFT,    _______,    _______,    _______,    _______,    _______, _______, _______, LALT(KC_PSCR), _______,       KC_UP, _______,   \
  _______,    _______,    _______,    _______,    KC_LGUI,    KC_SPC , KC_SPC , KC_RGUI,       _______, KC_LEFT,     KC_DOWN, KC_RIGHT  \
),


[_FUNC] = LAYOUT_main( \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  KC_CLCK, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_U, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R  \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
		case TKL:
		  if(record->event.pressed){
			  layer_off(_RAISE);
			  layer_off(_LOWER);
			  layer_off(_ADJUST);
			  layer_off(_FUNC);
			  layer_on(_TKL);
		  }
		  else
		  {
			  layer_off(_TKL);
		  }
		  return false;
		  break;
		case FUNC:
		  if(record->event.pressed) {
			  layer_off(_RAISE);
			  layer_off(_LOWER);
			  layer_off(_ADJUST);
			  layer_off(_TKL);
			  layer_on(_FUNC);
		  }
		  else 
		  {
			  layer_off(_FUNC);
		  }
		  return false;
		  break;
		case MY_PLS_EQ:
			if(record->event.pressed)
			{
				SEND_STRING("+=");
			}
			return false;
			break;
		case MY_MNS_EQ:
			if(record->event.pressed)
			{
				SEND_STRING("-=");
			}
			return false;
			break;
		case MY_OR_EQ:
			if(record->event.pressed)
			{
				SEND_STRING("|=");
			}
			return false;
			break;
		case MY_AND_EQ:
			if(record->event.pressed)
			{
				SEND_STRING("&=");
			}
			return false;
			break;
		case MY_COPY:
			if(record->event.pressed)
			{
				SEND_STRING("©");
			}
			return false;
			break;
		case MY_RGTM:
			if(record->event.pressed)
			{
				SEND_STRING("®");
			}
			return false;
			break;
		case MY_TM:
			if(record->event.pressed)
			{
				SEND_STRING("™");
			}
			return false;
			break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
}
