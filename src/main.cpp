extern "C" {
#include QMK_KEYBOARD_H
#include <visualizer/visualizer.h>
#include <visualizer/default_animations.h>
}

static bool initial_update = true;

void initialize_user_visualizer(visualizer_state_t* state) {
    initial_update = true;
    start_keyframe_animation(&default_startup_animation);
}

void user_visualizer_resume(visualizer_state_t* state) {
    initial_update = true;
    start_keyframe_animation(&default_startup_animation);
}

void user_visualizer_suspend(visualizer_state_t* state) {
    start_keyframe_animation(&default_suspend_animation);
}

void update_user_visualizer_state(visualizer_state_t* state,
        visualizer_keyboard_status_t* prev_status) {
    if (initial_update) {
        initial_update=false;
        start_keyframe_animation(&led_test_animation);
    }
}

#include <util/keymap.hpp>

/* Number of keys for TrueFox layout */
#define KEYMAP_SIZE 68

constexpr std::array<std::array<keycode_t, KEYMAP_SIZE>, 2> layers = {
    layer(KEYMAP_SIZE, R"keymap(
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┬────┐
│Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ \ │ `  │Ins │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┼────┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │BSpc  │Del │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴──────┼────┤
│ MO1  │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter   │Brk │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬────┼────┤
│ LShift │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RShift│ ↑  │App │
├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴─┬────┼────┼────┤
│LCtl│LGui│LAlt│         Space          │RAlt│RCtl │ ←  │ ↓  │ →  │
└────┴────┴────┴────────────────────────┴────┴─────┴────┴────┴────┘
)keymap"),
    layer(KEYMAP_SIZE, R"keymap(
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┬────┐
│   │ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│   │ 💡 │PScr│
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┼────┤
│     │   │   │   │   │   │   │   │ ⏮ │ ⏯ │ ⏭ │ 🔉│ 🔊│  🔇  │RST │
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴──────┼────┤
│      │   │   │   │   │   │   │   │   │ ⏹ │ 🔅│ 🔆│         │    │
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬────┼────┤
│ CAPS   │   │   │   │   │   │   │   │   │   │   │ CAPS │PgUp│    │
├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴─┬────┼────┼────┤
│    │    │    │                        │    │     │Home│PgDn│End │
└────┴────┴────┴────────────────────────┴────┴─────┴────┴────┴────┘
)keymap")
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = apply_array(LAYOUT_truefox, KEYMAP_SIZE, layers[0]),
    [1] = apply_array(LAYOUT_truefox, KEYMAP_SIZE, layers[1])
};
