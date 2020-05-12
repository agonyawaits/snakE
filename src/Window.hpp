#pragma once

#include "Vector2.hpp"
#include "IDrawable.hpp"
#include "Input.hpp"
#include "Color.hpp"
#include <ncurses.h>

class Window final {
public:
    Window(const Vector2i&, const Vector2i&);
    ~Window();

    void      clear() const;
    void      render(const IDrawable&) const;
    void      render(const IDrawable&, const Color&) const;
    Input     getInput() const;
    Vector2i  size() const;

private:
    Vector2i  m_size;
    WINDOW*   m_window;
};
