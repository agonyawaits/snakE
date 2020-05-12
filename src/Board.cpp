#include "Board.hpp"
#include "Vector2.hpp"
#include <random>
#include <ncurses.h>

Board::Board(const Vector2i& size)
    : m_size(size)
{
}

Vector2i Board::size() const {
    return m_size;
}

void Board::draw(WINDOW* window) const {
    mvwhline(window, 0, 0, 0, m_size.x());
    mvwhline(window, m_size.y(), 0, 0, m_size.x());
    mvwvline(window, 0, 0, 0, m_size.y());
    mvwvline(window, 0, m_size.x(), 0, m_size.y());
    mvwaddch(window, 0, 0, ACS_ULCORNER);
    mvwaddch(window, m_size.y(), 0, ACS_LLCORNER);
    mvwaddch(window, 0, m_size.x(), ACS_URCORNER);
    mvwaddch(window, m_size.y(), m_size.x(), ACS_LRCORNER);
}

Vector2i Board::randomPosition() const {
    return Vector2i(
        rand() % (m_size.x()-2) + 1,
        rand() % (m_size.y()-2) + 1
    );
}
