#pragma once

#include "Vector2.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include <ncurses.h>

class Window final {
public:
    Window(const int&, const int&, const Vector2i&);
    virtual ~Window();

    int h() const;
    int w() const;
    void clear() const;
    void drawBorder() const;
    void drawObject(const Object&, const chtype='o') const;
    void drawSnake(const Snake&) const;
    int getInput() const;
    Vector2i randomPosition() const;

private:
    int m_height, m_width;
    WINDOW* m_window;
};
