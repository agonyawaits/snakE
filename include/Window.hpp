#pragma once

#include "Vector2.hpp"
#include "IDrawable.hpp"
#include "Input.hpp"
#include <ncurses.h>

class Window final {
public:
    Window(const Vector2i&, const Vector2i&);
    ~Window();

    enum Color {
        GREEN = 1, RED, YELLOW
    };

    void      clear() const;
    void      render(const IDrawable&) const;
    void      render(const IDrawable&, const Color&) const;
    Input     input() const;
    Vector2i  size() const;

private:
    Vector2i  m_size;
    WINDOW*   m_window;
};
