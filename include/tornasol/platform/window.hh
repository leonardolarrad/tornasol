#pragma once
#include <functional>
#include "tornasol/common/common.hh"
#include "tornasol/platform/input.hh"

namespace sol {

class window {
public:
    std::function<void(key, i32, input_action, key_modifier)>  on_input_key;
    std::function<void(char32_t)>                              on_input_char;  
    
    // std::function<void(ivec2)>              on_move;
    // std::function<void(size2<i32>)>         on_resize;
    // std::function<void(void)>               on_close;
    // std::function<void(void)>               on_minimize;
    // std::function<void(void)>               on_maximize;
    // std::function<void()>                   on_focus;
    // std::function<void()>                   on_blur;
    // std::function<void()>                   on_refresh;
    // std::function<void(fvec2)>              on_cursor_move;
    // std::function<void()>                   on_cursor_enter;
    // std::function<void()>                   on_cursor_leave;
    // std::function<void(fvec2)>              on_scroll;
    // std::function<void(mouse_button, 
    //     input_action, key_modifier)>        on_mouse_button;
    // std::function<void(key, i32, 
    //     input_action, key_modifier)>        on_key;
    // std::function<void(u32)>                on_char;
    // std::function<void(u32, key_modifier)>  on_char_mods;
    // std::function<void(isize2)>             on_framebuffer_resize;

    // auto close() -> void;
    // auto maximize() -> void;
    // auto minimize() -> void;
    // auto restore() -> void;
    // auto raise() -> void;
    // auto get_title() const -> std::string_view;
    // auto set_title(std::string_view title) -> void;
    // auto get_size() const -> isize2;
    // auto set_size(isize2 size) -> void;
    // auto get_position() const -> ivec2;
    // auto set_position(ivec2 pos) -> void;   

    virtual ~window() {}
    virtual auto show() noexcept -> void = 0;
    virtual auto hide() noexcept -> void = 0;
    virtual auto should_close() const noexcept -> bool = 0;

    virtual auto make_current_gl_context() noexcept -> void = 0;
    virtual auto swap_buffers() noexcept -> void = 0;
};

TORNASOL_EXPORT 
auto make_window(std::string_view title, isize2 size) -> result<unique<window>>;

}