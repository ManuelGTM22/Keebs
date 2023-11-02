#include QMK_KEYBOARD_H

enum layer_number {
  _COLEMAK_DH = 0,
  _BAJA,
  _ALTA,
  _MOUSE
};

enum layer_names{
  _Default,
  _Lower,
  _Raise,
  _Mouse
};

enum custom_taps{
  TD_PC,
  TD_COMI,
  TD_SLA,
  TD_CAPS,
  TD_ALT,
  TD_ENIE,
  TD_MIN,
  TD_MAX,
  TD_CERRAR
};

enum custom_keycodes{
  _COPIAR = SAFE_RANGE,
  _PEGAR,
  _SCREEN,
  _MAIL,
  _UNDO,
  _FLASH,
  _PRESENTACION,
  _CLEAR
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode){
    case _COPIAR:
      if(record -> event.pressed){
        SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_C));
      }else{
        clear_keyboard();
      }
      break;

    case _PEGAR:
        if(record -> event.pressed){
          SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_V));
        }else{
          clear_keyboard();
        }
          break;

    case _SCREEN:
      if(record -> event.pressed){
        SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_DOWN(X_S));
        }else{
          clear_keyboard();
        }
        break;

    case _UNDO:
      if(record -> event.pressed){
        SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_Z));
      }else{
        clear_keyboard();
      }
      break;

    case _FLASH:
     if (record->event.pressed) {
        SEND_STRING("qmk compile -kb lily58/rev1 -km manuel_keymap");
      }
    break;

    case _MAIL: 
      if (record->event.pressed) {
        SEND_STRING("manuelgabrielt@gmail.com");
      }
    break;
  
    case _PRESENTACION:
      if(record -> event.pressed){
        SEND_STRING("Universidad Pedro Henriquez Urena\nNombre \nManuel Gabriel Torres Malena\nMatricula \n20-1346 \nProfesor\n Materia\n");
      }
      break;
   }
  return true;
  

}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LBSPC |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   DEL   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   . |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTL | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RALT|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_COLEMAK_DH] = LAYOUT(

  //-----------Primera mitad--------------------------------------------------------------------------------Segunda mitad------------------------------------------------------------
  KC_ESC,   KC_1,   KC_2,   TD(TD_CERRAR),  KC_4, KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,   KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y,   TD(TD_PC),  KC_BSLS,
  TD(TD_CAPS),  KC_A, KC_R, KC_S, KC_T,    KC_G,                                   KC_M,    KC_N, KC_E, KC_I, KC_O, TD(TD_COMI),
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_D,   KC_V, _COPIAR,                       _PEGAR,  KC_K,    KC_H,    TD(TD_MAX), TD(TD_MIN),  TD(TD_SLA),  KC_RSFT,
                         KC_LALT, KC_LGUI,  MO(_BAJA), KC_ENT,                                KC_SPC,  MO(_ALTA) , KC_RALT, KC_DEL 
),
/* LOWER 
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_BAJA] = LAYOUT(
  _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,           
  KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR,KC_PERC,            KC_PLUS, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, _______,
  _______,KC_1,  KC_2,  KC_3, KC_4, KC_5,                 KC_MINUS, KC_UNDS, KC_LCBR, KC_RCBR,KC_CIRC , KC_PIPE,
  _______, KC_0, KC_9, KC_8, KC_7, KC_6, _______, _______,  KC_EQL, KC_PSLS , KC_LBRC , KC_RBRC,KC_TILD ,_______, 
                          _______, _______, _______, _______, _______,  _______, _______, _______ //h
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_ALTA] = LAYOUT(
  KC_F1,  KC_F2, KC_F3, KC_F4, KC_5, KC_F6,                                     KC_F7, KC_F8, KC_9, KC_F10, KC_F11, KC_F12,
  _______,  KC_HOME,  XXXXXXX, KC_UP,  XXXXXXX, XXXXXXX,                        XXXXXXX,    KC_MPRV,    KC_MPLY,    KC_MNXT,_______,  _______,
  _______,  XXXXXXX, KC_LEFT,    KC_DOWN,   KC_RIGHT, _______,              _______, KC_VOLD, KC_VOLU, KC_MSEL,XXXXXXX, XXXXXXX,
  _______,   _UNDO,   _SCREEN, _______,  _______,  _______,   _______, _______,  _______, _______, _______,  _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_MOUSE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_MS_ACCEL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,                   KC_BTN2, KC_WH_L, KC_WH_D, KC_WH_R, KC_MS_ACCEL0, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _MAIL, _FLASH, KC_SLEP, KC_PWR, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ;, twice for :
    [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_COMI] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT)),
    [TD_SLA] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_SLSH)),
    [TD_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_LALT),
    [TD_ENIE] = ACTION_TAP_DANCE_DOUBLE(KC_N, RALT(KC_N)),
    [TD_MAX] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, LSFT(KC_COMM)),
    [TD_MIN] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LSFT(KC_DOT)),
    [TD_CERRAR] = ACTION_TAP_DANCE_DOUBLE(KC_3, LALT(KC_F4))
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _BAJA, _ALTA, _MOUSE);
}


//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);                     

// funcion que renderiza la imagen de en la pantalla oled 

static void render_my_logo(void) {
  static const char PROGMEM my_logo[] = { 

0x2f, 0xeb, 0x29, 0xef, 0x20, 0x3f, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 
0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0xfd, 0x01, 
0xff, 0x57, 0x53, 0x5f, 0x4b, 0x7b, 0x0b, 0xfb, 0x4b, 0x4b, 0x7b, 0x8b, 0x8b, 0xcb, 0xcb, 0xcb, 
0xcb, 0xcb, 0x8b, 0x8b, 0x0b, 0x7b, 0x4b, 0x4b, 0xfb, 0x0b, 0x7b, 0x4b, 0x5f, 0x53, 0x57, 0xff, 
0x00, 0xff, 0x02, 0xf3, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 
0xff, 0x01, 0xff, 0x01, 0xff, 0xc1, 0xf1, 0x3d, 0x0e, 0x03, 0x01, 0x01, 0x00, 0x70, 0x78, 0x38, 
0x18, 0x08, 0x01, 0x01, 0x03, 0x07, 0x0e, 0x3c, 0xf1, 0xc1, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 
0x00, 0xff, 0x40, 0xcf, 0x80, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 
0xff, 0x00, 0xff, 0x00, 0xff, 0x07, 0x1f, 0x79, 0xe1, 0x81, 0x01, 0x01, 0x01, 0x1d, 0x3d, 0x39, 
0x31, 0x21, 0x01, 0x01, 0x81, 0xc1, 0xe1, 0x79, 0x1f, 0x07, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
0xf4, 0xd7, 0x94, 0xf7, 0x04, 0xfc, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 
0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 
0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 
0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 
0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 
0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0xbf, 0x80, 
0xff, 0xd5, 0x95, 0xf5, 0xa5, 0xbd, 0xa1, 0xbf, 0xa4, 0xa5, 0xbd, 0xa3, 0xa2, 0xa6, 0xa6, 0xa6, 
0xa6, 0xa6, 0xa3, 0xa3, 0xa1, 0xbd, 0xa4, 0xa4, 0xbf, 0xa1, 0xbd, 0xa5, 0xf5, 0x95, 0xd5, 0xff
};
  oled_write_raw_P(my_logo, sizeof(my_logo));
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

layer_state_t layer_sate_set_user(layer_state_t state){
  oled_clear();
  return state;
}

bool oled_task_user(void) {

  led_t led_state = host_keyboard_led_state();

  if(is_keyboard_master()){
  
        oled_set_cursor(0,0);
    
    switch (get_highest_layer(layer_state)){
        case _BAJA:
            oled_set_cursor(2,1);
            oled_write_P(PSTR("Layer: Low"), false);
            break;
        case _ALTA:
            oled_set_cursor(2,1);
            oled_write_P(PSTR("Layer: Upper"), false);
            break; 
        case _MOUSE:
          oled_set_cursor(2,1);
          oled_write_P(PSTR("Layer: Mouse"), false);
          break;
        default: 
          render_my_logo();
          oled_set_cursor(2,1); //horinzontal, vertical 
          oled_write_P(PSTR("Layer: Base"), false); 
          oled_set_cursor(2,2);         
          oled_write_P(led_state.caps_lock ? PSTR("Caps: On") : PSTR("Caps: Off"), false);
          oled_set_cursor(2,3);
  
          break;
    }

  }else{
      oled_write(read_logo(), false);
    }  
  return false;
}

#endif // OLED_ENABLE



