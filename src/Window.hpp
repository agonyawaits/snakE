#pragma once

#include "Vector2.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Board.hpp"
#include <ncurses.h>

class Window final {
public:
    Window(const Vector2i&, const Vector2i&);
    ~Window();

    void      clear() const;
    void      render(const Board&) const;
    void      render(const Object&, const chtype='o') const;
    void      render(const Snake&) const;
    int       getInput() const;
    Vector2i  size() const;

private:
    Vector2i  m_size;
    WINDOW*   m_window;
};
