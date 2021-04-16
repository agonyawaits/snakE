#pragma once

#include "IDrawable.hpp"
#include "Vector2.hpp"
#include <ncurses.h>

class Score final : public IDrawable {
public:
    Score(const Vector2i&, int);

    void increase();
    void draw(WINDOW*) const;

private:
    Vector2i    m_position;
    int         m_score;
    int         m_step;
};
