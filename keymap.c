#include QMK_KEYBOARD_H

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
 * | Esc  |      |      | Shift| Lower|    Space    |Raise |  OS  |      |      | Enter|
 * `-----------------------------------------------------------------------------------'
 * 
 */
[BASE] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,   KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,       KC_G,   KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,   KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
    KC_ESC,  _______, _______, KC_LSFT, MO(LOWER),  KC_SPC, KC_SPC,  MO(RAISE), KC_LGUI, _______, _______, KC_ENT 
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  ↑   |      |      |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  <-  |  ↓   |  ->  |      |      | Home | End  | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    _______, _______, _______, KC_UP,   _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F8  |  F10 |  F11 |  F12 |  F5  |  ↑   |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |      |  <-  |  ↓ 　|  ->  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, KC_F8,   KC_F10,  KC_F11,  KC_F12,  KC_F5,   KC_UP,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F1,   KC_F2,   KC_F3,   _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Power| RESET| Btn1 | W Dn | Btn2 | Bri- | Bri+ |      | M Up |Print | Play | kana |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | WR   | W Up | W L  | Prev | Next | M L  | M Dn | M R  | Wake | 無変換|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Vol- | Vol+ | Mute |      |      | Sleep|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[ADJUST] = LAYOUT_planck_grid(
    KC_PWR,    RESET, KC_BTN1, KC_WH_D, KC_BTN2, KC_BRID, KC_BRIU, _______, KC_MS_U,  _______, KC_MPLY, KC_KANA,
    _______, _______, KC_WH_R, KC_WH_U, KC_WH_L, KC_MPRV, KC_MNXT, KC_MS_L, KC_MS_D,  KC_MS_R, KC_WAKE, KC_MHEN,
    _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,  _______, KC_SLEP,        ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
  
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, LOWER, RAISE, ADJUST);
}