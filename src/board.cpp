#include <random>
#include <ncurses.h>
#include "board.h"
#include "v2.h"

Board::Board(const V2 &size, const V2 &position)
    : m_position(position), m_size(size)
{
}

V2
Board::size() const {
    return m_size;
}

V2
Board::position() const {
    return m_position;
}

void
Board::draw(WINDOW *window) const {
    mvwhline(window, m_position.y(), m_position.x(), 0, m_size.x());
    mvwhline(window, m_position.y() + m_size.y(), m_position.x(), 0, m_size.x());
    mvwvline(window, m_position.y(), m_position.x(), 0, m_size.y());
    mvwvline(window, m_position.y(), m_position.x() + m_size.x(), 0, m_size.y());
    mvwaddch(window, m_position.y(), m_position.x(), ACS_ULCORNER);
    mvwaddch(window, m_position.y() + m_size.y(), m_position.x(), ACS_LLCORNER);
    mvwaddch(window, m_position.y(), m_position.x() +m_size.x(), ACS_URCORNER);
    mvwaddch(window, m_position.y() + m_size.y(), m_position.x() + m_size.x(), ACS_LRCORNER);
}

V2
Board::spot() const {
    return {
        (rand() % (m_size.x()-2)) + m_position.x() + 1,
        (rand() % (m_size.y()-2)) + m_position.y() + 1
    };
}
