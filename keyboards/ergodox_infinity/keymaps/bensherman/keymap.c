#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(  // layer 0 : default
  // left hand
  KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_MINUS,
  KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,LALT(LGUI(KC_LCTRL)),
  KC_LCTRL,KC_A,KC_S,KC_D,KC_F,KC_G,
  KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_LGUI,
  LT(1,KC_GRAVE),KC_LBRACKET,KC_RBRACKET,KC_LALT,KC_LGUI,
  KC_DELETE,KC_LGUI,
  KC_HOME,
  KC_SPACE,KC_TAB,KC_END,
  // right hand
  KC_EQUAL,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPACE,
  RALT(RGUI(KC_RCTRL)),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_QUOTE,
  KC_H,KC_J,KC_K,KC_L,LT(2,KC_SCOLON),KC_ENTER,
  KC_RGUI,KC_N,KC_M,KC_COMMA,KC_DOT,RCTL_T(KC_SLASH),KC_RSHIFT,
  KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,TT(1),
  KC_LALT,CTL_T(KC_EQUAL),
  KC_PGUP,KC_PGDOWN,KC_ENTER,KC_SPACE
  ),

// SYMBOLS
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F11,
  KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRANSPARENT,
  KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRAVE,
  KC_TRANSPARENT,KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,KC_TRANSPARENT,
  KC_TRANSPARENT,KC_AMPR,KC_ASTR,KC_LABK,KC_RABK,
  RGB_MOD,KC_TRANSPARENT,
  KC_TRANSPARENT,
  RGB_VAD,RGB_VAI,KC_TRANSPARENT,
  // right hand
  KC_F12,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_TRANSPARENT,
  KC_TRANSPARENT,KC_UP,KC_7,KC_8,KC_9,KC_ASTR,KC_BSLASH,
  KC_DOWN,KC_4,KC_5,KC_6,KC_KP_MINUS,KC_TRANSPARENT,
  KC_TRANSPARENT,KC_AMPR,KC_1,KC_2,KC_3,KC_KP_PLUS,KC_TRANSPARENT,
  KC_KP_DOT,KC_KP_0,KC_TRANSPARENT,KC_EQUAL,KC_TRANSPARENT,
  RGB_TOG,RGB_SLD,
  KC_TRANSPARENT,
  KC_TRANSPARENT,RGB_HUD,RGB_HUI
  ),
  
[MDIA] = LAYOUT_ergodox(
  KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
  KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
  KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,
  KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
  KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,
  KC_TRANSPARENT,KC_TRANSPARENT,
  KC_TRANSPARENT,
  KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,

  KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
  KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
  KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,
  KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,
  KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_AUDIO_MUTE,
  KC_TRANSPARENT,KC_TRANSPARENT,
  KC_TRANSPARENT,
  KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
