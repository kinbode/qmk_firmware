// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _SYMBOL,
    _NAVIGATION,
    _FUNCTION,
    _ADJUST
};

#define ENT_SYM LT(_SYMBOL, KC_ENT)
#define NAV     MO(_NAVIGATION)
#define FUNC    MO(_FUNCTION)
#define ADJUST  MO(_ADJUST)

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* BASE
 * .-----------------------------------------.                    .-----------------------------------------.
 * | ESC  |  1   |  2   |  3   |  4   |  5   |                    |   6  |  7   |  8   |  9   |  0   |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |                    |   Y  |  U   |  I   |  O   |  P   |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  A   |  S   |  D   |  F   |  G   |-------.    .-------|   H  |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|  Z   |  X   |  C   |  V   |  B   |-------|    |-------|  N   |  M   |  ,   |  .   |  /   |RShift|
 * '-----------------------------------------/       /    \       \-----------------------------------------'
 *                   | LGUI | LAlt | FUNC | / Enter /      \ Space \  | NAV  | RAlt |ADJUST|
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '------'------'------'-------'          '-------''------'------'------'
 */
[_BASE] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                             KC_LGUI, KC_LALT, FUNC,    ENT_SYM, KC_SPC,  NAV,     KC_RALT, ADJUST
),

/* SYMBOL
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  *   |  &   |      |                    |      |  [   |  ]   |  !   |  ?   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  $   |  #   |  @   |  !   |  _   |-------.    .-------|  =   |  {   |  }   |  (   |  )   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|      |      |  ^   |  %   |      |-------|    |-------|      |  -   |  +   |      |      |RShift|
 * '-----------------------------------------/       /    \       \-----------------------------------------'
 *                   | LGUI | LAlt | FUNC | / Enter /      \Backspc\  | NAV  | RAlt |ADJUST|
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '------'------'------'-------'          '-------''------'------'------'
 */
[_SYMBOL] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_ASTR, KC_AMPR, XXXXXXX,                   XXXXXXX, KC_LBRC, KC_RBRC, KC_EXLM, KC_QUES, XXXXXXX,
  _______, KC_DLR,  KC_HASH, KC_AT,   KC_EXLM, KC_UNDS,                   KC_EQL,  KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, KC_CIRC, KC_PERC, XXXXXXX, _______, _______, XXXXXXX, KC_MINS, KC_PLUS, XXXXXXX, XXXXXXX, _______,
                             _______, _______, _______, _______, KC_BSPC, _______, _______, _______
),

/* NAVIGATION
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    | Ins  | Home |  Up  | End  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |      |      |      |      |      |-------.    .-------| Del  | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      | PgUp |      | PgDn |      |RShift|
 * '-----------------------------------------/       /    \       \-----------------------------------------'
 *                   | LGUI | LAlt | FUNC | / Enter /      \ Space \  | NAV  | RAlt |ADJUST|
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '------'------'------'-------'          '-------''------'------'------'
 */
[_NAVIGATION] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_INS,  KC_HOME, KC_UP,   KC_END,  XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_PGUP, XXXXXXX, KC_PGDN, XXXXXXX, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),

/* FUNCTION
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |Numlck|  /   |  *   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |                    |      |  7   |  8   |  9   |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |  F5  |  F6  |  F7  |  F8  |      |-------.    .-------|      |  4   |  5   |  6   |  +   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|  F9  | F10  | F11  | F12  |      |-------|    |-------|      |  1   |  2   |  3   |  .   |RShift|
 * '-----------------------------------------/       /    \       \-----------------------------------------'
 *                   | LGUI | LAlt | FUNC | / Enter /      \   0   \  | NAV  | RAlt |ADJUST|
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '------'------'------'-------'          '-------''------'------'------'
 */
 [_FUNCTION] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                   XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,  XXXXXXX,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                   XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,  XXXXXXX,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, _______, _______, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PDOT,  _______,
                             _______, _______, _______, _______, KC_P0,   _______, _______, _______
),

/* ADJUST
 * .-----------------------------------------.                    .-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | Boot |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Sat- |Mode+ | Sat+ |      |                    |      |      | Vol+ |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Val- |RGBTog| Val+ |      |-------.    .-------|      |      | Mute |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      | Hue- |Mode- | Hue+ |      |-------|    |-------|      |      | Vol- |      |      |      |
 * '-----------------------------------------/       /    \       \-----------------------------------------'
 *                   | LGUI | LAlt | FUNC | / Enter /      \ Space \  | NAV  | RAlt |ADJUST|
 *                   |      |      |      |/       /        \       \ |      |      |      |
 *                   '------'------'------'-------'          '-------''------'------'------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  XXXXXXX, XXXXXXX, RGB_SAD, RGB_MOD, RGB_SAI, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, RGB_VAD, RGB_TOG, RGB_VAI, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, RGB_HUD, RGB_RMOD,RGB_HUI, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, _______, _______, _______
)
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    if (clockwise) {
        tap_code(KC_WH_L);
    } else {
        tap_code(KC_WH_R);
    }
  } else if (index == 1) {
    if (clockwise) {
        tap_code(KC_WH_U);
    } else {
        tap_code(KC_WH_D);
    }
  }
  return false;
}
#endif

#ifdef OLED_ENABLE
#define OLED_WIDTH             128
#define OLED_HEIGHT            32
#define LAYER_TITLE_SIZE       12
#define LAYER_TOP_OFFSET       4
#define LAYER_SIZE             8
#define LAYER_OFFSET           10
#define LAYER_OVERLAY_SIZE     12

static char layer_title[] = {
  0x00, 0x00, 0x28, 0xb4, 0x20, 0x20, 0xa0, 0x00, 0x00, 0xff, 0x00, 0xff,
  0x00, 0x00, 0x27, 0x28, 0x2f, 0xe8, 0x27, 0xc0, 0x00, 0xff, 0x00, 0xff,
  0x00, 0x00, 0x39, 0x05, 0x3d, 0x44, 0x3c, 0x01, 0x00, 0xff, 0x00, 0xff,
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1f, 0x00, 0x00, 0xff, 0x00, 0xff
};

static char layer_base[] = {
  0x00, 0x00, 0xe0, 0x10, 0xe0, 0x00, 0xf0, 0x00,
  0x00, 0x00, 0x38, 0x41, 0x39, 0x05, 0x78, 0x00,
  0x80, 0x40, 0x4e, 0x81, 0x4f, 0x51, 0x8f, 0x00,
  0x0f, 0x08, 0x08, 0x0f, 0x08, 0x08, 0x0f, 0x00
};

static char layer_symbol[] = {
  0x02, 0x02, 0x32, 0x4a, 0x4a, 0x4a, 0x32, 0x00,
  0x10, 0x10, 0x90, 0x56, 0x59, 0x51, 0x5e, 0x00,
  0x00, 0x00, 0x96, 0x95, 0x95, 0x75, 0x15, 0xe0,
  0x3c, 0x40, 0x40, 0x3c, 0x02, 0x42, 0x3c, 0x00
};

static char layer_navigation[] = {
  0x00, 0x00, 0x70, 0x90, 0x70, 0x10, 0x90, 0x60,
  0x00, 0x02, 0x00, 0x8a, 0x8a, 0x52, 0x22, 0x00,
  0x80, 0x80, 0x9c, 0x82, 0x9e, 0xa2, 0x9e, 0x00,
  0x08, 0x0c, 0x0a, 0x09, 0x08, 0x08, 0x08, 0x00
};

static char layer_function[] = {
  0x00, 0x00, 0x4c, 0xaa, 0xaa, 0xaa, 0x4a, 0x00,
  0x00, 0x12, 0x38, 0x92, 0x12, 0x92, 0x0a, 0x00,
  0x00, 0x00, 0x63, 0x54, 0x54, 0x54, 0x53, 0x00,
  0x78, 0x40, 0x45, 0x75, 0x45, 0x45, 0x43, 0x00
};

static char layer_adjust[] = {
  0x00, 0x08, 0xdc, 0x08, 0xc8, 0x28, 0xc4, 0x00,
  0x00, 0x80, 0x24, 0xa5, 0xa4, 0xa4, 0x9d, 0x00,
  0x10, 0x10, 0x10, 0x70, 0x90, 0x90, 0xf4, 0x03,
  0x1c, 0x22, 0x22, 0x3e, 0x22, 0x22, 0x22, 0x00
};

static char layer_overlay[] = {
  0xf8, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf8,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0x1f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f
};

static void draw_layer(char* data, uint8_t layer_index) {
  uint8_t offset =
    LAYER_TOP_OFFSET + 
    LAYER_TITLE_SIZE + 
    LAYER_OFFSET +
    LAYER_SIZE*layer_index +
    LAYER_OFFSET*layer_index; 

  if (get_highest_layer(layer_state) == layer_index) {
    offset -= 2;
    for (uint8_t i = 0; i < LAYER_OVERLAY_SIZE; i++) {
      if (i < 2 || i > 9) {
        oled_write_raw_byte(layer_overlay[i], offset + i);
        oled_write_raw_byte(layer_overlay[LAYER_OVERLAY_SIZE + i], offset + i + OLED_WIDTH);
        oled_write_raw_byte(layer_overlay[2*LAYER_OVERLAY_SIZE + i], offset + i + 2*OLED_WIDTH);
        oled_write_raw_byte(layer_overlay[3*LAYER_OVERLAY_SIZE + i], offset + i + 3*OLED_WIDTH);
      } else {
        oled_write_raw_byte(layer_overlay[i] ^ data[i - 2], offset + i);
        oled_write_raw_byte(layer_overlay[LAYER_OVERLAY_SIZE + i] ^ data[LAYER_SIZE + i - 2], offset + i + OLED_WIDTH);
        oled_write_raw_byte(layer_overlay[2*LAYER_OVERLAY_SIZE + i] ^ data[2*LAYER_SIZE + i - 2], offset + i + 2*OLED_WIDTH);
        oled_write_raw_byte(layer_overlay[3*LAYER_OVERLAY_SIZE + i] ^ data[3*LAYER_SIZE + i - 2], offset + i + 3*OLED_WIDTH);
      }
    }
  } else {
    for (uint8_t i = 0; i < LAYER_SIZE; i++) {
      oled_write_raw_byte(data[i], offset + i);
      oled_write_raw_byte(data[LAYER_SIZE + i], offset + i + OLED_WIDTH);
      oled_write_raw_byte(data[2*LAYER_SIZE + i], offset + i + 2*OLED_WIDTH);
      oled_write_raw_byte(data[3*LAYER_SIZE + i], offset + i + 3*OLED_WIDTH);
    }
  }
}

static void draw_layers(void) {
  oled_clear();

  for (uint8_t i = 0; i < LAYER_TITLE_SIZE; i++) {
    oled_write_raw_byte(layer_title[i], LAYER_TOP_OFFSET + i);
    oled_write_raw_byte(layer_title[LAYER_TITLE_SIZE + i], LAYER_TOP_OFFSET + i + OLED_WIDTH);
    oled_write_raw_byte(layer_title[2*LAYER_TITLE_SIZE + i], LAYER_TOP_OFFSET + i + 2*OLED_WIDTH);
    oled_write_raw_byte(layer_title[3*LAYER_TITLE_SIZE + i], LAYER_TOP_OFFSET + i + 3*OLED_WIDTH);
  }

  draw_layer(layer_base, 0);
  draw_layer(layer_symbol, 1);
  draw_layer(layer_navigation, 2);
  draw_layer(layer_function, 3);
  draw_layer(layer_adjust, 4);
}

typedef struct {
  int8_t offset_x;
  int8_t offset_y;
  int8_t translation_x;
  int8_t translation_y;
  uint16_t frame_data[];
} animation_frame;

typedef struct {
  uint8_t tag;
  uint8_t frame_count;
  animation_frame* frames[];
} animation;

#define FRAME_DURATION   100
#define SPRITE_DIMENSION  16
#define ANIMATION_NONE     0
#define ANIMATION_IDLE1    1
#define ANIMATION_IDLE2    2
#define ANIMATION_CLEAN1   3
#define ANIMATION_CLEAN2   4
#define ANIMATION_PLAY     5
#define ANIMATION_SLEEP    6
#define ANIMATION_JUMP     7
#define ANIMATION_SCARED   8
#define ANIMATION_WALK     9
#define ANIMATION_RUN     10
#define DIRECTION_UP      -1
#define DIRECTION_DOWN     1
#define DIRECTION_LEFT    -1
#define DIRECTION_RIGHT    1

static animation_frame animation_idle1_frame1 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0630, 0x05d0, 0x0410, 0x0530,
    0x0410, 0x0410, 0x0820, 0x0820, 0x0820, 0x7150, 0x9150, 0xfff0
  }
};
static animation_frame animation_idle1_frame2 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0630, 0x05d0, 0x0410, 0x0530, 
    0x0410, 0x0410, 0x0820, 0x0820, 0x3820, 0x5150, 0xb150, 0xdff0
  }
};
static animation_frame animation_idle1_frame3 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0630, 0x05d0, 0x0410, 0x0530,
    0x0410, 0x0410, 0x0820, 0x0820, 0x7820, 0x9150, 0xf150, 0x1ff0
  }
};
static animation_frame animation_idle1_frame4 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0630, 0x05d0, 0x0410, 0x0530,
    0x0410, 0x0410, 0x0820, 0x0820, 0xc820, 0xb150, 0x5150, 0x3ff0
  }
};

static animation animation_idle1 = {
  ANIMATION_IDLE1,
  8,
  {
    &animation_idle1_frame1,
    &animation_idle1_frame2,
    &animation_idle1_frame3,
    &animation_idle1_frame4,
    &animation_idle1_frame1,
    &animation_idle1_frame1,
    &animation_idle1_frame1,
    &animation_idle1_frame1
  }
};

static animation_frame animation_idle2_frame1 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0330, 0x02d0, 0x0420, 0x0490,
    0x0410, 0x0410, 0x0820, 0x0820, 0x0820, 0x7150, 0x9150, 0xfff0
  }
};
static animation_frame animation_idle2_frame2 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0330, 0x02d0, 0x0420, 0x0490,
    0x0410, 0x0410, 0x0820, 0x0820, 0x3820, 0x5150, 0xb150, 0xdff0
  }
};
static animation_frame animation_idle2_frame3 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0330, 0x02d0, 0x0420, 0x0490,
    0x0410, 0x0410, 0x0820, 0x0820, 0x7820, 0x9150, 0xf150, 0x1ff0
  }
};
static animation_frame animation_idle2_frame4 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0330, 0x02d0, 0x0420, 0x0490,
    0x0410, 0x0410, 0x0820, 0x0820, 0xc820, 0xb150, 0x5150, 0x3ff0
  }
};

static animation animation_idle2 = {
  ANIMATION_IDLE2,
  8,
  {
    &animation_idle2_frame1,
    &animation_idle2_frame2,
    &animation_idle2_frame3,
    &animation_idle2_frame4,
    &animation_idle2_frame1,
    &animation_idle2_frame1,
    &animation_idle2_frame1,
    &animation_idle2_frame1
  }
};

static animation_frame animation_clean1_frame1 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0630, 0x05d0, 0x0410, 0x05b0,
    0x0410, 0x0410, 0x0870, 0x0888, 0x08f0, 0x7140, 0x9140, 0xffc0
  }
};
static animation_frame animation_clean1_frame2 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0630, 0x05d0, 0x0410,
    0x05b0, 0x0410, 0x0870, 0x0888, 0x08f0, 0x7140, 0x9140, 0xffc0
  }
};
static animation_frame animation_clean1_frame3 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0cc0, 0x0be0, 0x05a0,
    0x0410, 0x0450, 0x0870, 0x0888, 0x08f0, 0x7140, 0x9140, 0xffc0
  }
};
static animation_frame animation_clean1_frame4 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0cc0, 0x0be0, 0x05a0, 0x0410,
    0x0470, 0x0410, 0x0870, 0x0888, 0x08f0, 0x7140, 0x9140, 0xffc0
  }
};

static animation animation_clean1 = {
  ANIMATION_CLEAN1,
  4,
  {
    &animation_clean1_frame1,
    &animation_clean1_frame2,
    &animation_clean1_frame3,
    &animation_clean1_frame4
  }
};

static animation_frame animation_clean2_frame1 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0630, 0x05d0, 0x0410, 0x05b0,
    0x0410, 0x0410, 0x0870, 0x0888, 0x08f0, 0x7140, 0x9140, 0xffc0
  }
};
static animation_frame animation_clean2_frame2 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0600, 0x05f0, 0x0428,
    0x0418, 0x05b8, 0x0818, 0x09e8, 0x0830, 0x7140, 0x9140, 0xffc0
  }
};
static animation_frame animation_clean2_frame3 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0600, 0x05c0, 0x0430,
    0x0428, 0x05b8, 0x0818, 0x09e8, 0x0830, 0x7140, 0x9140, 0xffc0
  }
};
static animation_frame animation_clean2_frame4 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0600, 0x05f8, 0x0408, 0x0410,
    0x05b0, 0x0448, 0x0868, 0x0830, 0x0820, 0x7140, 0x9140, 0xffc0
  }
};

static animation animation_clean2 = {
  ANIMATION_CLEAN2,
  4,
  {
    &animation_clean2_frame1,
    &animation_clean2_frame2,
    &animation_clean2_frame3,
    &animation_clean2_frame4
  }
};

static animation_frame animation_play_frame1 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0330, 0x62f0, 0xa210,
    0xa210, 0xa248, 0xbe08, 0x4010, 0x4010, 0x5110, 0x5f50, 0x6db0
  }
};
static animation_frame animation_play_frame2 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0060, 0x00a0, 0x66a0, 0xa510,
    0xb430, 0x5490, 0x5c10, 0x4020, 0x4010, 0x5148, 0x5f78, 0x6d80
  }
};
static animation_frame animation_play_frame3 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0060, 0x00a0, 0x36a0, 0x5510,
    0x5430, 0x5490, 0x5c18, 0x4004, 0x403c, 0x5140, 0x5f40, 0x6d80
  }
};
static animation_frame animation_play_frame4 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0018, 0x3028, 0x51a8,
    0x5144, 0xa10c, 0xbf24, 0x4104, 0x4004, 0x5104, 0x5f72, 0x6d8e
  }
};
static animation_frame animation_play_frame5 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0060, 0x00a0, 0x06a0, 0x3510,
    0x5430, 0xa490, 0xbc10, 0x8020, 0x4010, 0x5148, 0x5f78, 0x6d80
  }
};

static animation animation_play = {
  ANIMATION_PLAY,
  8,
  {
    &animation_play_frame1,
    &animation_play_frame2,
    &animation_play_frame3,
    &animation_play_frame4,
    &animation_play_frame3,
    &animation_play_frame5,
    &animation_play_frame1,
    &animation_play_frame1
  }
};

static animation_frame animation_sleep_frame1 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x00c6, 0x00ba, 0x0382, 0x0cee, 0x1082, 0x78f6, 0x8509, 0xffff
  }
};
static animation_frame animation_sleep_frame2 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x00c6, 0x00ba, 0x0782, 0x18ee, 0x2082, 0x78f6, 0x8509, 0xffff
  }
};
static animation_frame animation_sleep_frame3 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x00c6, 0x00ba, 0x0f82, 0x10ee, 0x2082, 0x78f6, 0x8509, 0xffff
  }
};

static animation animation_sleep = {
  ANIMATION_SLEEP,
  8,
  {
    &animation_sleep_frame1,
    &animation_sleep_frame2,
    &animation_sleep_frame3,
    &animation_sleep_frame2,
    &animation_sleep_frame1,
    &animation_sleep_frame1,
    &animation_sleep_frame1,
    &animation_sleep_frame1
  }
};

static animation_frame animation_jump_frame1 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0630, 0x05d0, 0x0410, 0x0530,
    0x0410, 0x0410, 0x0820, 0x0820, 0x0820, 0x7150, 0x9150, 0xfff0
  }
};
static animation_frame animation_jump_frame2 = {
  0, 0, 0, 0,
  {
    0x0630, 0x05d0, 0x0410, 0x0d3e, 0x12d2, 0x14d4, 0x1234, 0x0818,
    0x0410, 0x0820, 0x0820, 0x1010, 0x13d0, 0x6c30, 0x9000, 0x6000
  }
};
static animation_frame animation_jump_frame3 = {
  -3, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0318, 0x02e8, 0x0208, 0x0298, 0x0208, 0x060c,
    0x0932, 0x109a, 0x22a4, 0x2140, 0x5b20, 0xaaa0, 0xa660, 0x4000
  }
};
static animation_frame animation_jump_frame4 = {
  -4, 0, 0, 0,
  {
    0x0000, 0x0000, 0x6000, 0xa000, 0xa000, 0xa330, 0x9af0, 0x4608,
    0x4218, 0x4248, 0x4208, 0x5818, 0x6404, 0x02f4, 0x028c, 0x0180
  }
};
static animation_frame animation_jump_frame5 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3000, 0x5330, 0x52f0,
    0x5208, 0x5e08, 0x4298, 0x4008, 0x8010, 0xbd10, 0xc2e8, 0x0338
  }
};
static animation_frame animation_jump_frame6 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0330, 0x62f0,
    0xa208, 0xa298, 0xa208, 0xbe08, 0x4010, 0x4010, 0x5110, 0x7ff0
  }
};
static animation_frame animation_jump_frame7 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0330, 0x62f0, 0xa208,
    0xa298, 0xa208, 0xbe08, 0x4010, 0x4010, 0x5110, 0x5f50, 0x6db0
  }
};

static animation animation_jump = {
  ANIMATION_JUMP,
  8,
  {
    &animation_jump_frame1,
    &animation_jump_frame2,
    &animation_jump_frame3,
    &animation_jump_frame4,
    &animation_jump_frame5,
    &animation_jump_frame6,
    &animation_jump_frame7,
    &animation_jump_frame1
  }
};

static animation_frame animation_scared_frame1 = {
  0, 0, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0330, 0x62f0, 0xa210,
    0xa248, 0xa208, 0xbe08, 0x4010, 0x4010, 0x5110, 0x5f50, 0x6db0
  }
};
static animation_frame animation_scared_frame2 = {
  0, 1, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc0cc, 0xa0bc,
    0xa1a4, 0xa6b2, 0x9882, 0x6082, 0x200c, 0x2f88, 0x2ea8, 0x32d8
  }
};
static animation_frame animation_scared_frame3 = {
  0, 1, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc0cc, 0xa0bc,
    0xa7a4, 0xa8b2, 0x9082, 0x6082, 0x200c, 0x2f88, 0x2ea8, 0x32d8
  }
};
static animation_frame animation_scared_frame4 = {
  0, 1, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc0cc, 0xafbc,
    0xb0a4, 0xb0b2, 0x8082, 0x6082, 0x270c, 0x2f88, 0x2ea8, 0x32d8
  }
};
static animation_frame animation_scared_frame5 = {
  0, 1, 0, 0,
  {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0xde, 0x52, 0x59, 0x41, 0x41, 0x86, 0xc4, 0x54, 0x6c, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xa0, 0x57, 0x28, 0x10, 0x10, 0x10, 0x13, 0x17, 0x17, 0x19
  }
};
static animation_frame animation_scared_frame6 = {
  0, 1, 0, 0,
  {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc0cc, 0xa0bc,
    0xa7a4, 0xb8b2, 0x8082, 0x6082, 0x200c, 0x2f88, 0x2ea8, 0x32d8
  }
};

static animation animation_scared =  {
  ANIMATION_SCARED,
  8,
  {
    &animation_scared_frame1,
    &animation_scared_frame2,
    &animation_scared_frame3,
    &animation_scared_frame4,
    &animation_scared_frame5,
    &animation_scared_frame5,
    &animation_scared_frame6,
    &animation_scared_frame1
  }
};

// static animation animation_walk = {
//   ANIMATION_WALK,
//   8,
//   {
//     animation_walk_frame1,
//     animation_walk_frame2,
//     animation_walk_frame3,
//     animation_walk_frame4,
//     animation_walk_frame5,
//     animation_walk_frame6,
//     animation_walk_frame7,
//     animation_walk_frame8
//   }
// };

// static animation animation_run = {
//   ANIMATION_RUN,
//   8,
//   {
//     animation_run_frame1,
//     animation_run_frame2,
//     animation_run_frame3,
//     animation_run_frame4,
//     animation_run_frame5,
//     animation_run_frame6,
//     animation_run_frame7,
//     animation_run_frame8
//   }
// };

uint32_t frame_timer = 0;
uint32_t current_frame = 0;
int16_t position_x = 56;
int16_t position_y = 4;
int8_t direction_x = DIRECTION_RIGHT;
int8_t direction_y = DIRECTION_UP;
animation* active_animation = &animation_idle1;

static void draw_animation(void) {
  if (timer_elapsed32(frame_timer) < FRAME_DURATION) return;

  frame_timer = timer_read32();

  if (current_frame >= active_animation->frame_count) {
    current_frame = 0; 
    int rand_val = (rand() % 1000) + 1;
    
    switch (active_animation->tag) {
      case ANIMATION_IDLE1:
        if (rand_val <= 700)      break;
        else if (rand_val <= 850) active_animation = &animation_idle2;
        else if (rand_val <= 910) active_animation = &animation_clean1;
        else if (rand_val <= 950) active_animation = &animation_play;
        else if (rand_val <= 980) active_animation = &animation_jump;
        else if (rand_val <= 990) active_animation = &animation_sleep;
        else if (rand_val <= 995) active_animation = &animation_scared;
        // else if (rand_val <= 999) active_animation = &animation_walk;
        // else                      active_animation = &animation_run;
        else                      active_animation = &animation_idle2;
        break;
      case ANIMATION_IDLE2:
        if (rand_val <= 600)      break;
        else                      active_animation = &animation_idle1;
        break;
      case ANIMATION_CLEAN1:
        if (rand_val <= 700)      break;
        else if (rand_val <= 950) active_animation = &animation_clean2;
        else                      active_animation = &animation_idle1;
        break;
      case ANIMATION_CLEAN2:
        if (rand_val <= 700)      break;
        else                      active_animation = &animation_clean1;
        break;
      case ANIMATION_PLAY:
        if (rand_val <= 850)      break;
        else                      active_animation = &animation_idle1;
        break;
      case ANIMATION_SLEEP:
        if (rand_val <= 980)      break;
        else                      active_animation = &animation_idle1;
        break;
      case ANIMATION_JUMP:
        active_animation = &animation_idle1;
        // if (rand_val <= 750)      active_animation = &animation_idle1;
        // else                      active_animation = &animation_run;
        break;
      case ANIMATION_SCARED:
        if (rand_val <= 500)      break;
        else if (rand_val <= 750) active_animation = &animation_idle1;
        else if (rand_val <= 900) active_animation = &animation_run;
        else                      active_animation = &animation_play;
        break;
      // case ANIMATION_WALK:
      //   break;
      // case ANIMATION_RUN:
      //   break;
    }
  }
  
  oled_clear();

  position_x += active_animation->frames[current_frame]->translation_x * direction_x;
  if (position_x < -SPRITE_DIMENSION) {
    position_x = -SPRITE_DIMENSION;
    direction_x = DIRECTION_RIGHT;
  }
  else if (position_x > OLED_WIDTH) {
    position_x = OLED_WIDTH;
    direction_x = DIRECTION_LEFT;
  }

  position_y += active_animation->frames[current_frame]->translation_y * direction_y;
  if (position_y < -SPRITE_DIMENSION) {
    position_y = -SPRITE_DIMENSION;
    direction_y = DIRECTION_DOWN;
  }
  else if (position_y > OLED_HEIGHT) {
    position_y = OLED_HEIGHT;
    direction_y = DIRECTION_UP;
  }
  
  int16_t frame_position_x = position_x + active_animation->frames[current_frame]->offset_x * direction_x;
  int16_t frame_position_y = position_y + active_animation->frames[current_frame]->offset_y * direction_y;

  for (uint8_t i = 0; i < SPRITE_DIMENSION; i++) {    
    int16_t buffer_offset = frame_position_x + i;
    if (buffer_offset < 0) continue; 
    if (buffer_offset >= OLED_WIDTH - 1) break;
    
    uint8_t frame_data_index;
    switch (direction_x) {
      case DIRECTION_RIGHT:
        frame_data_index = i;
      case DIRECTION_LEFT:
        frame_data_index = SPRITE_DIMENSION - i;
    }

    uint16_t sprite_line = active_animation->frames[current_frame]->frame_data[frame_data_index];
    switch (direction_y) {
      case DIRECTION_UP:
        break;
      case DIRECTION_DOWN:
        sprite_line = (sprite_line & 0xff00) >> 8 | (sprite_line & 0x00ff) << 8;
        sprite_line = (sprite_line & 0xf0f0) >> 4 | (sprite_line & 0x0f0f) << 4;
        sprite_line = (sprite_line & 0xcccc) >> 2 | (sprite_line & 0x3333) << 2;
        sprite_line = (sprite_line & 0xaaaa) >> 1 | (sprite_line & 0x5555) << 1;
        break;
    }
    uint32_t screen_line = sprite_line;
    
    if (frame_position_y >= 0) screen_line <<= frame_position_y;
    else screen_line >>= -frame_position_y;
    uint8_t line_seg_1 = screen_line;
    uint8_t line_seg_2 = screen_line >> 8;
    uint8_t line_seg_3 = screen_line >> 16;
    uint8_t line_seg_4 = screen_line >> 24;

    oled_write_raw_byte(line_seg_1, buffer_offset);
    oled_write_raw_byte(line_seg_2, buffer_offset + OLED_WIDTH);
    oled_write_raw_byte(line_seg_3, buffer_offset + 2*OLED_WIDTH);
    oled_write_raw_byte(line_seg_4, buffer_offset + 3*OLED_WIDTH);
  }

  current_frame++;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  srand(timer_read32());
  return OLED_ROTATION_180;
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    draw_layers();
  } else {
    draw_animation();
  }

  return false;
}
#endif
