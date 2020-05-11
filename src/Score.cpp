#include "Score.hpp"
#include "Vector2.hpp"
#include <ncurses.h>

Score::Score(const Vector2i& position, const int& step)
    : m_position(position), m_score(0), m_step(step)
{
}

int Score::score() const {
    return m_score;
}

void Score::increase() {
    m_score += m_step;
}

void Score::draw(WINDOW* window) const {
    mvwprintw(window, m_position.y(), m_position.x(), "%d", m_score);
}
