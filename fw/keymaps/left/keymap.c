#include QMK_KEYBOARD_H

enum layers {
  _DEF = 0, _NUM, _BRC, _SYM, _MSC, _NAV, _MSE,
};

enum custom_keycodes {
  CTL_LCK = SAFE_RANGE,
  GUI_LCK,
  ALT_LCK,
  SFT_LCK,
  CLR_LCK,
};

enum combos {
  _7, _8, _9, _0,
  _B, _C, _D, _F, _G, _H, _J, _K, _L,
  _M, _N, _P, _Q, _U, _V, _W, _X, _Z,
  _COMM, _DOT, _SLSH, _QUOT, _EXLM, _QUES,
  _SPC, _BSPC, _DEL, _ENT, _ESC, _TAB,
  _CTL, _GUI, _ALT, _SFT, _SFT1, _CLR,
  _NAV_ON, _MSE_ON, _NAV_OFF, _MSE_OFF,
};

#define S_NUM LT(_NUM, KC_S)
#define A_BRC LT(_BRC, KC_A)
#define E_SYM LT(_SYM, KC_E)
#define O_MSC LT(_MSC, KC_O)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case CTL_LCK:
    if (record->event.pressed) {
      if (get_mods() & MOD_BIT(KC_LCTL)) {
        unregister_mods(MOD_BIT(KC_LCTL));
      } else {
        register_mods(MOD_BIT(KC_LCTL));
      }
    }
    break;
  case GUI_LCK:
    if (record->event.pressed) {
      if (get_mods() & MOD_BIT(KC_LGUI)) {
        unregister_mods(MOD_BIT(KC_LGUI));
      } else {
        register_mods(MOD_BIT(KC_LGUI));
      }
    }
    break;
  case ALT_LCK:
    if (record->event.pressed) {
      if (get_mods() & MOD_BIT(KC_LALT)) {
        unregister_mods(MOD_BIT(KC_LALT));
      } else {
        register_mods(MOD_BIT(KC_LALT));
      }
    }
    break;
  case SFT_LCK:
    if (record->event.pressed) {
      if (get_mods() & MOD_BIT(KC_LSFT)) {
        unregister_mods(MOD_BIT(KC_LSFT));
      } else {
        register_mods(MOD_BIT(KC_LSFT));
      }
    }
    break;
  case CLR_LCK:
    clear_mods();
    break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEF] = LAYOUT(
    S_NUM, KC_T, KC_R, A_BRC,
    O_MSC, KC_I, KC_Y, E_SYM
  ),
  [_NUM] = LAYOUT(
    XXXXXXX, KC_3, KC_2, KC_1,
    XXXXXXX, KC_6, KC_5, KC_4
  ),
  [_BRC] = LAYOUT(
    LSFT(KC_LBRC), KC_LBRC, LSFT(KC_9), XXXXXXX,
    LSFT(KC_RBRC), KC_RBRC, LSFT(KC_0), XXXXXXX
  ),
  [_SYM] = LAYOUT(
    KC_BSLS, KC_SCLN, KC_GRV, LSFT(KC_3),
    KC_EQL, KC_MINS, LSFT(KC_2), XXXXXXX
  ),
  [_MSC] = LAYOUT(
    XXXXXXX, KC_VOLU, KC_MUTE, KC_MPLY,
    XXXXXXX, KC_VOLD, KC_MPRV, KC_MNXT
  ),
  [_NAV] = LAYOUT(
    KC_PGUP, KC_HOME, KC_UP, KC_END,
    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_MSE] = LAYOUT(
    KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1,
    KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R
  ),
};

const uint16_t PROGMEM seven_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM eight_combo[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM nine_combo[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM zero_combo[] = {KC_5, KC_6, COMBO_END};

const uint16_t PROGMEM b_combo[] = {E_SYM, O_MSC, COMBO_END};
const uint16_t PROGMEM c_combo[] = {E_SYM, KC_Y, COMBO_END};
const uint16_t PROGMEM d_combo[] = {A_BRC, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM f_combo[] = {A_BRC, KC_R, COMBO_END};
const uint16_t PROGMEM g_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM h_combo[] = {E_SYM, KC_I, COMBO_END};
const uint16_t PROGMEM j_combo[] = {KC_T, S_NUM, COMBO_END};
const uint16_t PROGMEM k_combo[] = {KC_Y, O_MSC, COMBO_END};
const uint16_t PROGMEM l_combo[] = {E_SYM, KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM m_combo[] = {KC_Y, KC_I, O_MSC, COMBO_END};
const uint16_t PROGMEM n_combo[] = {KC_I, O_MSC, COMBO_END};
const uint16_t PROGMEM p_combo[] = {E_SYM, KC_I, O_MSC, COMBO_END};
const uint16_t PROGMEM q_combo[] = {A_BRC, KC_T, S_NUM, COMBO_END};
const uint16_t PROGMEM u_combo[] = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM v_combo[] = {KC_R, S_NUM, COMBO_END};
const uint16_t PROGMEM w_combo[] = {A_BRC, S_NUM, COMBO_END};
const uint16_t PROGMEM x_combo[] = {KC_R, KC_T, S_NUM, COMBO_END};
const uint16_t PROGMEM z_combo[] = {A_BRC, KC_R, KC_T, S_NUM, COMBO_END};

const uint16_t PROGMEM comm_combo[] = {A_BRC, KC_Y, COMBO_END};
const uint16_t PROGMEM dot_combo[] = {A_BRC, KC_I, COMBO_END};
const uint16_t PROGMEM slsh_combo[] = {A_BRC, O_MSC, COMBO_END};
const uint16_t PROGMEM quot_combo[] = {KC_R, KC_Y, COMBO_END};
const uint16_t PROGMEM exlm_combo[] = {KC_T, KC_I, COMBO_END};
const uint16_t PROGMEM ques_combo[] = {S_NUM, O_MSC, COMBO_END};

const uint16_t PROGMEM spc_combo[] = {E_SYM, KC_Y, KC_I, O_MSC, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_R, E_SYM, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {A_BRC, E_SYM, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {A_BRC, KC_R, O_MSC, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {A_BRC, KC_R, KC_T, O_MSC, COMBO_END};

const uint16_t PROGMEM ctl_combo[] = {S_NUM, E_SYM, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {S_NUM, KC_Y, COMBO_END};
const uint16_t PROGMEM alt_combo[] = {S_NUM, KC_I, COMBO_END};
const uint16_t PROGMEM sft_combo[] = {A_BRC, KC_Y, KC_I, O_MSC, COMBO_END};
const uint16_t PROGMEM sft1_combo[] = {KC_R, KC_T, S_NUM, E_SYM, COMBO_END};
const uint16_t PROGMEM clr_combo[] = {A_BRC, KC_R, KC_T, S_NUM, E_SYM, KC_Y, KC_I, O_MSC, COMBO_END};

const uint16_t PROGMEM nav_on_combo[] = {KC_R, E_SYM, KC_I, COMBO_END};
const uint16_t PROGMEM mse_on_combo[] = {A_BRC, KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM nav_off_combo[] = {KC_UP, KC_RGHT, KC_LEFT, COMBO_END};
const uint16_t PROGMEM mse_off_combo[] = {KC_BTN1, KC_BTN2, KC_MS_D, COMBO_END};

combo_t key_combos[] = {
  [_7] = COMBO(seven_combo, KC_7),
  [_8] = COMBO(eight_combo, KC_8),
  [_9] = COMBO(nine_combo, KC_9),
  [_0] = COMBO(zero_combo, KC_0),

  [_B] = COMBO(b_combo, KC_B),
  [_C] = COMBO(c_combo, KC_C),
  [_D] = COMBO(d_combo, KC_D),
  [_F] = COMBO(f_combo, KC_F),
  [_G] = COMBO(g_combo, KC_G),
  [_H] = COMBO(h_combo, KC_H),
  [_J] = COMBO(j_combo, KC_J),
  [_K] = COMBO(k_combo, KC_K),
  [_L] = COMBO(l_combo, KC_L),
  [_M] = COMBO(m_combo, KC_M),
  [_N] = COMBO(n_combo, KC_N),
  [_P] = COMBO(p_combo, KC_P),
  [_Q] = COMBO(q_combo, KC_Q),
  [_U] = COMBO(u_combo, KC_U),
  [_V] = COMBO(v_combo, KC_V),
  [_W] = COMBO(w_combo, KC_W),
  [_X] = COMBO(x_combo, KC_X),
  [_Z] = COMBO(z_combo, KC_Z),

  [_COMM] = COMBO(comm_combo, KC_COMM),
  [_DOT] = COMBO(dot_combo, KC_DOT),
  [_SLSH] = COMBO(slsh_combo, KC_SLSH),
  [_QUOT] = COMBO(quot_combo, KC_QUOT),
  [_EXLM] = COMBO(exlm_combo, LSFT(KC_1)),
  [_QUES] = COMBO(ques_combo, LSFT(KC_SLSH)),

  [_SPC] = COMBO(spc_combo, KC_SPC),
  [_BSPC] = COMBO(bspc_combo, KC_BSPC),
  [_DEL] = COMBO(del_combo, KC_DEL),
  [_ENT] = COMBO(ent_combo, KC_ENT),
  [_ESC] = COMBO(esc_combo, KC_ESC),
  [_TAB] = COMBO(tab_combo, KC_TAB),

  [_CTL] = COMBO(ctl_combo, CTL_LCK),
  [_GUI] = COMBO(gui_combo, GUI_LCK),
  [_ALT] = COMBO(alt_combo, ALT_LCK),
  [_SFT] = COMBO(sft_combo, SFT_LCK),
  [_SFT1] = COMBO(sft1_combo, OSM(MOD_LSFT)),
  [_CLR] = COMBO(clr_combo, CLR_LCK),

  [_NAV_ON] = COMBO(nav_on_combo, TG(_NAV)),
  [_MSE_ON] = COMBO(mse_on_combo, TG(_MSE)),
  [_NAV_OFF] = COMBO(nav_off_combo, TO(_DEF)),
  [_MSE_OFF] = COMBO(mse_off_combo, TO(_DEF)),
};
