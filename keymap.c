#include QMK_KEYBOARD_H

enum custom_keycodes {
    M1 = SAFE_RANGE,
    M2,
    M3,
    M4,
    M5,
    M6,
    M7,
    M8,
    M9,
    M10,
    M11,
    M12,
};

void f11(uint16_t keycode){
  tap_code(KC_F11);
  tap_code(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case M1:
        if (record->event.pressed) {
          f11(KC_A);
        }
        break;
    case M2:
        if (record->event.pressed) {
          f11(KC_S);
        }
        break;
    case M3:
        if (record->event.pressed) {
          f11(KC_D);
        }
        break;
    case M4:
        if (record->event.pressed) {
          f11(KC_F);
        }
        break;
    case M5:
        if (record->event.pressed) {
          f11(KC_G);
        }
        break;
    case M6:
        if (record->event.pressed) {
          f11(KC_Z);
        }
        break;
    case M7:
        if (record->event.pressed) {
          f11(KC_X);
        }
        break;
    case M8:
        if (record->event.pressed) {
          f11(KC_C);
        }
        break;
    case M9:
        if (record->event.pressed) {
          f11(KC_V);
        }
        break;
    case M10:
        if (record->event.pressed) {
          f11(KC_B);
        }
        break;
    case M11:
        if (record->event.pressed) {
          f11(KC_H);
        }
        break;
    case M12:
        if (record->event.pressed) {
          f11(KC_N);
        }
        break;
    }
    return true;
};

enum layers {
  BASE,
  LOWER,
  RAISE,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Alt  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |      |      | Shift| Lower|    Space    |Raise |  F19 |   OS | Ctrl | Enter|
 * `-----------------------------------------------------------------------------------'
 * 
 */
[BASE] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,   KC_Y,      KC_U,      KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,       KC_G,   KC_H,      KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,   KC_N,      KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
    KC_ESC,  _______, _______, KC_LSFT, MO(LOWER),  KC_SPC, MO(RAISE), KC_F19,    KC_LGUI, KC_RCTL, KC_ENT,  _______ 
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   |  |   `  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | F11A | F11S | F11D | F11F | F11G | F11H |   [  |   ]  |   {  |   }  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | F11Z | F11X | F11C | F11V | F11B | F11N |   <  |   >  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,  KC_AMPR, KC_ASTR, KC_PIPE, KC_GRV, KC_BSPC,
    _______, M1,	    M2,      M3,      M4,      M5,      M11,      KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_DQT,
    _______, M6,      M7,      M8,      M9,      M10,     M12,      KC_LABK, KC_RABK, KC_LPRN, KC_RPRN, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | F12  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  <-  |   ↓  |   ↑  |   -> |   ~  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   +  |   -  |   =  |   _  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[RAISE] = LAYOUT_planck_grid(
    KC_F12,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,     KC_BSPC,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TILD,  KC_BSLS,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_PLUS, KC_MINS, KC_EQL,   KC_UNDS,  _______,   
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,_______,  _______
),

/*  (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      | MU   |      |      | Bri- | Bri+ | M1   | M2   |      | Play |  全角 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MR   | MD   | ML   |      |      | WL   | WD   | WU   | WR   |      | 半角 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Vol- | Vol+ | Mute |      | Prev | Next |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[ADJUST] = LAYOUT_planck_grid(
    _______,  _______, KC_MS_U, _______, _______, KC_BRID, KC_BRIU, KC_BTN1, KC_BTN2, _______, KC_MPLY, KC_LNG1,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, KC_LNG2,
    _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_MPRV, KC_MNXT, _______,
    _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
  
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, LOWER, RAISE, ADJUST);
}