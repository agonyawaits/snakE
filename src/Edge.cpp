#include "Edge.hpp"
#include "Vector2.hpp"
#include <ncurses.h>

Edge::Edge(const Vector2i& size)
    : m_size(size)
{
}

Vector2i Edge::size() const {
    return m_size;
}

void Edge::draw(WINDOW* window) const {
    box(window, 0, 0);
}
