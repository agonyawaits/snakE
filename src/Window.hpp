#pragma once

#include "Vector2.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include <ncurses.h>

class Snake; // NOTE: Forward declaration to avoid compile error.

class Window final {
public:
    Window(const Vector2i&, const Vector2i&);
    ~Window();

    Vector2i  size() const;
    void      clear() const;
    void      drawBorder() const;
    void      drawObject(const Object&, const chtype='o') const;
    void      drawSnake(const Snake&) const;
    int       getInput() const;
    Vector2i  randomPosition() const;

private:
    Vector2i  m_size;
    WINDOW*   m_window;
};
