#include <random>
#include <ncurses.h>
#include "board.h"
#include "v2.h"

Board::Board(const V2 &size)
    : m_size(size)
{
}

V2
Board::size() const {
    return m_size;
}

void
Board::draw(WINDOW *window) const {
    mvwhline(window, 0, 0, 0, m_size.x());
    mvwhline(window, m_size.y(), 0, 0, m_size.x());
    mvwvline(window, 0, 0, 0, m_size.y());
    mvwvline(window, 0, m_size.x(), 0, m_size.y());
    mvwaddch(window, 0, 0, ACS_ULCORNER);
    mvwaddch(window, m_size.y(), 0, ACS_LLCORNER);
    mvwaddch(window, 0, m_size.x(), ACS_URCORNER);
    mvwaddch(window, m_size.y(), m_size.x(), ACS_LRCORNER);
}

V2
Board::spot() const {
    return { rand() % (m_size.x()-2) + 1, rand() % (m_size.y()-2) + 1 };
}
