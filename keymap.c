#include QMK_KEYBOARD_H

enum user_macro { UM_EILOWER, UM_KANARAISE, UM_ESCCTRL };
#define M_EILOWER MACROTAP(UM_EILOWER)      // 「Lower」キー用のキーコード
#define M_KANARAISE MACROTAP(UM_KANARAISE)  // 「Raise」キー用のキーコード
#define M_ESCCTRL MACROTAP(UM_ESCCTRL)      // 「CTRL」キー用のキーコード

// #ifdef RGBLIGHT_ENABLE
// // Following line allows macro to read current RGB settings
// extern rgblight_config_t rgblight_config;
// #endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes { QWERTY = SAFE_RANGE, LOWER, RAISE, ADJUST, BACKLIT, RGBRST };

enum macro_keycodes {
    SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_QWERTY] = LAYOUT(\
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            M_ESCCTRL, KC_A, KC_S, KC_D, KC_F, KC_G,                                   KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_LGUI, M_EILOWER, KC_SPC,                                                KC_ENT, M_KANARAISE, KC_RALT \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // TAB, Q, W, E, R, T,                                                         Y, U, I, O, P, Backspace,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // Tap(esc) Hold(Ctrl), A, S, D, F, G,                                         H, J, K, L, ;, ',
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // Shift, Z, X, C, V, B,                                                       N, M, ',', '.', /, Shift,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // Command, Tap(ei) Hold(LOWER), Space,                                        Enter, Tap(kana) Hold(Raise), Option
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    ),

    [_LOWER] = LAYOUT(\
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR,                                  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                KC_BSLS, KC_PLUS, KC_PEQL, KC_LCBR, KC_RCBR, KC_MINS, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                KC_PIPE, KC_GRV, KC_NO, KC_LBRC, KC_RBRC, KC_UNDS, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------
            KC_LGUI, LOWER, KC_SPC,                                                    KC_ENT, RAISE, KC_RALT \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // ~, !, @, #, $, %                                                            ^, &, *, (, ), Backspace,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // Ctrl, xxx, xxx, xxx, xxx, xxx,                                              \, +, =, {, }, -,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // Option, xxx, xxx, xxx, xxx, xxx,                                              |, `, xxx, [, ], _,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------
        // Command, LOWER, Space,                                                      Enter, RAISE, Option
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    ),

    [_RAISE] = LAYOUT(\
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_GRV, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5,                                 KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_BSPC, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                 KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_LSFT, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO,                               KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_NO, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_LGUI, LOWER, KC_SPC,                                                    KC_ENT, RAISE, KC_RALT \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // `, 1, 2, 3, 4, 5,                                                           6, 7, 8, 9, 0, Backspace,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // ESC, xxx, xxx, xxx, xxx, xxx,                                                    ←, ↓, ↑, →, xxx, xxx,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // Shift, xxx, xxx, xxx, xxx, xxx,                                                 HOME, Page Down, Page Up, END, xxx, xxx,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // Command, LOWER, Space,                                                      Enter, RAISE, Option
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    ),

    [_ADJUST] = LAYOUT(\
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_SLEP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_MFFD,                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MSTP, KC_MPLY,                        KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_LGUI, LOWER, KC_SPC,                                                    KC_ENT, RAISE, KC_RALT \
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.

        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // Sleap, xxx, xxx, xxx, xxx, xxx,                                             xxx, xxx, xxx, xxx, xxx, xxx,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // xxx, xxx, xxx, xxx, Prev Track, Next Track,                                 xxx, xxx, xxx, xxx, xxx, xxx,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // xxx, MUTE, Volume Down, Volume Up, Media Stop, Media Play,                  Brightness Down,  Brightness Up, xxx, xxx, xxx, xxx,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        // Command, LOWER, Space,                                                      Enter, RAISE, Option
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    ),

    // clang-format on
};

// int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
// void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
//     if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
//         layer_on(layer3);
//     } else {
//         layer_off(layer3);
//     }
// }

void matrix_init_user(void) {
// #ifdef RGBLIGHT_ENABLE
//     RGB_current_mode = rgblight_config.mode;
// #endif

// SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
    iota_gfx_init(!has_usb());  // turns on the display
#endif
}

// SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
void        set_timelog(void);
const char *read_timelog(void);

void matrix_scan_user(void) { iota_gfx_task(); }

void matrix_render_user(struct CharacterMatrix *matrix) {
    set_timelog();
    if (is_master) {
        // If you want to change the display of OLED, you need to change here
        matrix_write_ln(matrix, read_layer_state());
        matrix_write_ln(matrix, read_keylog());
        matrix_write_ln(matrix, read_timelog());
        // matrix_write_ln(matrix, read_keylogs());
        // matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
        // matrix_write_ln(matrix, read_host_led_state());
    } else {
        matrix_write(matrix, read_logo());
    }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
    if (memcmp(dest->display, source->display, sizeof(dest->display))) {
        memcpy(dest->display, source->display, sizeof(dest->display));
        dest->dirty = true;
    }
}

void iota_gfx_task_user(void) {
    struct CharacterMatrix matrix;
    matrix_clear(&matrix);
    matrix_render_user(&matrix);
    matrix_update(&display, &matrix);
}
#endif  // SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef SSD1306OLED
        set_keylog(keycode, record);
#endif
    }

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << _QWERTY);
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                // update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                // update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                // update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                // update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            //         case RGB_MOD:
            // #ifdef RGBLIGHT_ENABLE
            //             if (record->event.pressed) {
            //                 rgblight_mode(RGB_current_mode);
            //                 rgblight_step();
            //                 RGB_current_mode = rgblight_config.mode;
            //             }
            // #endif
            //             return false;
            //         case RGBRST:
            // #ifdef RGBLIGHT_ENABLE
            //             if (record->event.pressed) {
            //                 eeconfig_update_rgblight_default();
            //                 rgblight_enable();
            //                 RGB_current_mode = rgblight_config.mode;
            //             }
            // #endif
            //             break;
    }
    return true;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case UM_EILOWER:  // タップで「英数」と「無変換」、ホールドで「Lower」
            return MACRO_TAP_HOLD_LAYER(record, MACRO(T(MHEN), T(LANG2), END), _LOWER);
            break;
        case UM_KANARAISE:  // タップで「かな」と「変換」、ホールドで「Raise」
            return MACRO_TAP_HOLD_LAYER(record, MACRO(T(HENK), T(LANG1), END), _RAISE);
            break;
        case UM_ESCCTRL:  // タップで「ESC」、ホールドで「CTRL」
            return MACRO_TAP_HOLD_MOD(record, MACRO(T(ESC), END), LCTRL);
    };
    return MACRO_NONE;
}
