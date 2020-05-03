#pragma once

#include "Vector2.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include <ncurses.h>

class Window final {
public:
    Window(const Vector2u&, const Vector2i&);
    ~Window();

    int       height() const;
    int       width() const;
    void      clear() const;
    void      drawBorder() const;
    void      drawObject(const Object&, const chtype='o') const;
    void      drawSnake(const Snake&) const;
    int       getInput() const;
    Vector2i  randomPosition() const;

private:
    Vector2u  m_size;
    WINDOW*   m_window;
};
