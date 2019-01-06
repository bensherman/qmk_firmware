#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ortho_5x15(
		KC_ESC,  KC_1,    KC_2,    KC_3,  KC_4,    KC_5,    KC_NLCK, KC_MINS, KC_EQL, KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,    KC_T,    KC_P7,   KC_P8,   KC_P9,  KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_HOME,
		KC_LCTL, KC_A,    KC_S,    KC_D,  KC_F,    KC_G,    KC_P4,   KC_P5,   KC_P6,  KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,    KC_B,    KC_P1,   KC_P2,   KC_P3,  KC_N,    KC_M,   KC_BSLS, KC_GRV,  KC_UP,   KC_QUOT,
		KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_LBRC, KC_RBRC, KC_ENT,  KC_P0,   KC_SPC, KC_COMM, KC_DOT, KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
	),
	[1] = LAYOUT_ortho_5x15(
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_F5, KC_NO,   KC_NO,   KC_NO,    KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10,  KC_DEL,
		RGB_MOD, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_HOME, KC_UP,   KC_PGUP,  KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_INS, 
		KC_CAPS, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_LEFT, KC_NO,   KC_RGHT,  KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,
		KC_RSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_END,  KC_DOWN, KC_PGDN,  KC_NO, KC_NO, KC_NO, KC_NO,   KC_VOLU, KC_NO,
		KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO, KC_MSTP, KC_VOLD, KC_MPLY
	)
};
