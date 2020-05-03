#pragma once

#include "Vector2.hpp"
#include <ncurses.h>

class Window {
public:
    Window(const int&, const int&, const Vector2i&);
    virtual ~Window();

protected:
    Vector2i m_position;
    int m_height, m_width;
    WINDOW* m_window;
};
