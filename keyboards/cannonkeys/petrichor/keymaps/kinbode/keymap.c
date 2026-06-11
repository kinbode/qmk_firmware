// Copyright 2024 Andrew Kannan
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define HUE_OFFSET 128 
#define FN_LED_STATE_INDEX 2

enum layers {
    _MAC,
    _FN_MAC,
    _PC,
    _FN_PC
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAC] = LAYOUT_all(
        KC_ESC,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        MO(_FN_MAC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,     XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,            KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LGUI,     KC_LALT, XXXXXXX,                            KC_SPC,                    XXXXXXX, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT,          KC_P0,   KC_PDOT, KC_PENT
    ),

    [_FN_MAC] = LAYOUT_all(
        KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,   KC_F6,   KC_F7,      KC_F8,   KC_F9,       KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______, DF(_PC), _______, _______, QK_BOOT,
        KC_CAPS,    _______,    _______,    C(KC_UP),   _______,    _______, _______, G(KC_LEFT), KC_UP,   G(KC_RGHT),  _______, _______, _______, _______,          UG_HUEU, UG_VALU, UG_SATU, _______,
        _______,    _______,    C(KC_LEFT), C(KC_DOWN), C(KC_RGHT), _______, _______, KC_LEFT,    KC_DOWN, KC_RGHT,     _______, _______,          _______,          UG_PREV, UG_TOGG, UG_NEXT, _______,
        _______,    _______,    _______,    _______,    _______,    _______, _______, KC_PGUP,    _______, KC_PGDN,     _______, _______, _______, _______,          UG_HUED, UG_VALD, UG_SATD, _______,
        LCG(KC_NO), LCA(KC_NO), _______,                                     KC_BSPC,                      _______,     _______, _______, _______, _______, _______,          _______, _______, _______
    ),
    
    [_PC] = LAYOUT_all(
        KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        MO(_FN_PC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_LSFT,    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,            KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,    KC_LALT, XXXXXXX,                            KC_SPC,                    XXXXXXX, KC_RALT, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT,          KC_P0,   KC_PDOT, KC_PENT
    ),

    [_FN_PC] = LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______, DF(_MAC), _______, _______, QK_BOOT,
        KC_CAPS, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, _______,          _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,          _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, KC_PGDN, _______, _______, _______, _______,          _______,  _______, _______, _______,
        _______, _______, _______,                            KC_BSPC,                   _______, _______, _______, _______, _______, _______,           _______, _______, _______
    ),

};

layer_state_t default_layer_state_set_user(layer_state_t state) {
    static uint8_t current_default_layer = 0xFF;
    uint8_t new_default_layer = get_highest_layer(state);
    if (new_default_layer == current_default_layer) {
        return state;
    }

    HSV hsv = rgblight_get_hsv();
    
    switch (new_default_layer) {
        case _PC:
            hsv.h += HUE_OFFSET;
            break;
        case _MAC:
            hsv.h -= HUE_OFFSET;
            break;
        default:
            break;
    }
    
    rgblight_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
    
    current_default_layer = new_default_layer;
    
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(FN_LED_STATE_INDEX, layer_state_cmp(state, _FN_MAC) || layer_state_cmp(state, _FN_PC));
    return state;
}