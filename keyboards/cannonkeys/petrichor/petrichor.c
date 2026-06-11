// Copyright 2023 Andrew Kannan
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

const rgblight_segment_t numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_PURPLE}
);
const rgblight_segment_t capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_GREEN}
);
const rgblight_segment_t fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);

const rgblight_segment_t* const PROGMEM enabled_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    numlock_layer,
    capslock_layer,
    fn_layer
);

void keyboard_post_init_kb(void) {
    keyboard_post_init_user();
    rgblight_layers = enabled_rgb_layers;
}

bool led_update_kb(led_t led_state) {
    if(!led_update_user(led_state)){
        return false;
    }
    rgblight_set_layer_state(0, led_state.num_lock);
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
}
