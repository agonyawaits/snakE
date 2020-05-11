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
    //box(window, 0, 0);
    mvwhline(window, 0, 0, 0, m_size.x());
    mvwhline(window, m_size.y(), 0, 0, m_size.x());
    mvwvline(window, 0, 0, 0, m_size.y());
    mvwvline(window, 0, m_size.x(), 0, m_size.y());
    mvwaddch(window, 0, 0, ACS_ULCORNER);
    mvwaddch(window, m_size.y(), 0, ACS_LLCORNER);
    mvwaddch(window, 0, m_size.x(), ACS_URCORNER);
    mvwaddch(window, m_size.y(), m_size.x(), ACS_LRCORNER);
}
