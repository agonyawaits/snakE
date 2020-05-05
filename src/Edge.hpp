#pragma once

#include "Vector2.hpp"
#include "IDrawable.hpp"
#include <ncurses.h>

class Edge final : public IDrawable {
public:
    Edge(const Vector2i&);

    void      draw(WINDOW*) const;
    Vector2i  size() const;

private:
    Vector2i m_size;
};
