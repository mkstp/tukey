/* Copyright 2022 Marc St. Pierre
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

enum layer_names {
    _BASE,
    _SYMBOL,
    _FUNCTION,
    _MOUSE
};

enum custom_keycodes {
    DSPC = SAFE_RANGE, //DOT THEN SPACE THEN HOLD SHIFT FOR THE NEXT CHARACTER
    QSPC, //QUESTION MARK THEN SPACE THEN HOLD SHIFT
    ESPC, //EXCLAMATION MARK THEN SPACE THEN HOLD SHIFT
    CSPC, //COMMA THEN SPACE
    REPEAT, //REPEAT LAST KEY PRESSED
    TG_CLCK, //CLICK THEN EXIT MOUSE LAYER
};

//code for repeat key. from: https://gist.github.com/NotGate/3e3d8ab81300a86522b2c2549f99b131

#define OSL_SYM OSL(_SYMBOL)
#define OSL_FUN OSL(_FUNCTION)
#define TGL_MOU TG(_MOUSE)
#define OS_SFT OSM(MOD_RSFT)
#define CUT RCTL(KC_X)
#define COPY RCTL(KC_C)
#define UNDO RCTL(KC_Z)
#define PSTE RCTL(KC_V)

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

// Initialize variables holding the bitfield
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;

void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if (keycode != REPEAT) {
        // Early return when holding down a pure layer key
        // to retain modifiers
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
                return;
        }
        last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    last_keycode = GET_TAP_KC(keycode);
                }
                break;
            default:
                if (record->event.pressed) {
                    last_keycode = keycode;
                }
                break;
        }
    } else { // keycode == REPEAT
        if (record->event.pressed) {
            register_mods(last_modifier);
            register_code16(last_keycode);
        } else {
            unregister_code16(last_keycode);
            unregister_mods(last_modifier);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    process_repeat_key(keycode, record);
    // It's important to update the mod variables *after* calling process_repeat_key, or else
    // only a single modifier from the previous key is repeated (e.g. Ctrl+Shift+T then Repeat produces Shift+T)
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();

    switch (keycode) {
    case DSPC:
        if (record->event.pressed) {
            // when keycode DSPC is pressed
            SEND_STRING(". ");  
        } else {
            set_oneshot_mods(MOD_BIT(KC_RSFT));
        }
        break;
    case QSPC:
        if (record->event.pressed) {
            SEND_STRING("? ");  
        } else {
            set_oneshot_mods(MOD_BIT(KC_RSFT));
        }
        break;
    case ESPC:
        if (record->event.pressed) {
            SEND_STRING("! ");  
        } else {
            set_oneshot_mods(MOD_BIT(KC_RSFT));
        }
        break;
    case CSPC:
        if (record->event.pressed) {
            SEND_STRING(", ");
        }
        break;
    case TG_CLCK:
        if (record->event.pressed) {
            tap_code(KC_BTN1);
        } else {
            layer_off(_MOUSE);
        }
        break;
    }
    return true;
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        REPEAT , KC_O   , KC_L   , KC_C   , KC_W   , KC_R   ,                   KC_T   , KC_O   , KC_R   , KC_F   , KC_P   , KC_BSPC,
        KC_TAB , KC_A   , KC_N   , KC_D   , KC_S   , KC_M   ,                   KC_L   , KC_E   , KC_I   , KC_H   , KC_T   , KC_ENT ,
        KC_ESC , KC_Q   , KC_X   , KC_V   , KC_G   , KC_B   , QSPC   , ESPC   , KC_K   , KC_U   , KC_Y   , KC_J   , KC_Z   , KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, KC_RCTL, OSL_FUN, KC_SPC , CSPC   , DSPC   , KC_SPC , OSL_SYM, KC_RCTL, KC_RGUI, KC_RALT, TGL_MOU  
    ),
    [_SYMBOL] = LAYOUT(
        _______, KC_SCLN, KC_RCBR, KC_RPRN, KC_RBRC, KC_PIPE,                   KC_BSLS, KC_SLSH, KC_PLUS, KC_DQUO, KC_ASTR, _______,
        _______, KC_LCBR, KC_LPRN, KC_LBRC, KC_COLN, KC_COMM,                   KC_DOT , KC_EQL , KC_MINS, KC_QUOT, KC_UNDS, _______,
        _______, KC_EXLM, KC_CIRC, KC_LT  , KC_GT  , KC_QUES, KC_0   , KC_1   , KC_AMPR, KC_PERC, KC_DLR , KC_HASH, KC_AT  , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_FUNCTION] = LAYOUT(
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        _______, KC_DEL , KC_LALT, KC_LSFT, KC_RCTL, KC_COMM,                   KC_DOT , KC_DOWN, KC_LEFT, KC_RGHT, KC_UP  , _______,
        _______, UNDO   , CUT    , COPY   , PSTE   , KC_SLSH, KC_GRV , KC_TILD, KC_MINS, KC_PGDN, KC_HOME, KC_END , KC_PGUP, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   COPY   , KC_BTN1, KC_MS_U, KC_F13 , PSTE   , _______,
        _______, _______, _______, _______, _______, _______,                   _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL0, TG_CLCK,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U, _______, KC_ACL1, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_F13 , KC_BTN1, KC_BTN2, _______, _______, _______
    )
};
