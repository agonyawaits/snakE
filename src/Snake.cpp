#include "Object.hpp"
#include "Snake.hpp"
#include "Vector2.hpp"
#include "Direction.hpp"
#include <ncurses.h>
#include <vector>

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

Vector2i Snake::headPosition() const {
    return m_body.front().position();
}

void Snake::draw(WINDOW* window) const {
    m_body.front().draw(window, currentHeadSymbol());
    for (int i = 1; i < m_body.size(); ++i) {
      m_body[i].draw(window);
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

    postMoveUpdate();
}

void Snake::extend() {
    m_body.emplace_back(
        Object(
            m_body.back().position()
        )
    );
}

void Snake::postMoveUpdate() {
    if (m_body.size() < 5) {
        return;
    }

    for (int i = 4; i < m_body.size(); ++i) {
        if (m_body.front() == m_body[i]) {
            m_alive = false;
            return;
        }
    }
}

chtype Snake::currentHeadSymbol() const {
    switch (m_body.front().direction()) {
        case Direction::LEFT :
            return ACS_LARROW;

        case Direction::RIGHT :
            return ACS_RARROW;

        case Direction::UP :
            return ACS_UARROW;

        case Direction::DOWN :
            return 'v';

        case Direction::NONE:
            return '*';

        default:
            throw "Unsupported direction";
    }
}
