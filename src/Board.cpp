#include "Board.hpp"
#include "Vector2.hpp"
#include <ncurses.h>

Board::Board(const Vector2i& size)
    : m_size(size)
{
}

Vector2i Board::size() const {
    return m_size;
}

void Board::draw(WINDOW* window) const {
    box(window, 0, 0);
}
