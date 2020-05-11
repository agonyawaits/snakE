#pragma once

#include "Vector2.hpp"
#include "IDrawable.hpp"
#include <ncurses.h>

class Board final : public IDrawable {
public:
    Board(const Vector2i&);

    void      draw(WINDOW*) const;
    Vector2i  size() const;

private:
    Vector2i m_size;
};
