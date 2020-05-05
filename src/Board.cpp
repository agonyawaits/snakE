#include "Board.hpp"
#include "Vector2.hpp"
#include <ncurses.h>
#include <random>

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

Vector2i Board::randomPosition() const {
    return Vector2i(
        rand() % (m_size.x()-2) + 1,
        rand() % (m_size.y()-2) + 1
    );
}
