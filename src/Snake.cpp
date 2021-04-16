#include "Snake.hpp"
#include "Object.hpp"
#include "Board.hpp"
#include "Vector2.hpp"
#include "Direction.hpp"
#include "Window.hpp"
#include <ncurses.h>
#include <vector>

const int Snake::s_minSizeCanDie = 5;

Snake::Snake()
    : m_body(std::vector<Object>{ Object(Vector2i()) }), m_alive(true)
{
}

Snake::Snake(const Vector2i& position)
    : m_body(std::vector<Object>{ Object(position) }), m_alive(true)
{
}

bool Snake::alive() const {
    return m_alive;
}

Object Snake::head() const {
    return m_body.front();
}

bool Snake::collides(const Object& object) const {
    for (const auto& block : m_body) {
        if (block == object) {
            return true;
        }
    }
    return false;
}

bool Snake::collides(const Board& board) const {
    return head().position().x() == 0 ||
        head().position().y() == 0 ||
        head().position().x() == board.size().x() ||
        head().position().y() == board.size().y();
}

void Snake::draw(WINDOW* window) const {
    head().draw(window, '*');
    for (size_t i = 1; i < m_body.size(); ++i) {
      m_body[i].draw(window, 'o');
    }
}

void Snake::move(const Direction& direction) {
    if (!m_alive) {
        return;
    }

    for (int i = m_body.size()-1; i > 0; --i) {
        m_body[i].moveTo(m_body[i-1].position());
    }
    m_body.front().move(direction);

    m_alive = !died();
}

void Snake::extend() {
    m_body.emplace_back(
        Object(
            m_body.back().position()
        )
    );
}

bool Snake::died() const {
    if (m_body.size() < Snake::s_minSizeCanDie) {
        return false;
    }

    for (size_t i = Snake::s_minSizeCanDie-1;
         i < m_body.size();
         ++i)
    {
        if (head() == m_body[i]) {
            return true;
        }
    }

    return false;
}
