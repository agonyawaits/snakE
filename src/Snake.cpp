#include "Object.hpp"
#include "Snake.hpp"
#include "Vector2.hpp"
#include "Direction.hpp"
#include <ncurses.h>

Snake::Snake() : m_head(Object(Vector2i())), m_alive(true)
{
}

Snake::Snake(const Vector2i& position) : m_head(Object(position)), m_alive(true)
{
}

bool Snake::alive() const {
    return m_alive;
}

void Snake::draw(WINDOW* window) const {
    mvwaddch(window, m_head.y(), m_head.x(), currentHeadSymbol());
    for (const auto& block : m_body) {
        block.draw(window);
    }
}

void Snake::move(const Direction& direction) {
    if (!m_alive) {
        return;
    }

    moveBody();
    m_head.move(direction);
    postMoveUpdate();
}

void Snake::extend() {
    m_body.emplace_back(
        Object(
            m_body.empty() ? m_head.position() : m_body.back().position()
        )
    );
}

void Snake::moveBody() {
    if (m_body.empty()) {
        return;
    }

    for (int i = m_body.size()-1; i > 0; --i) {
        m_body[i].move(m_body[i-1].direction());
    }

    m_body.front().move(m_head.direction());
}

void Snake::postMoveUpdate() {
    if (m_body.size() < 4) {
        return;
    }

    for (int i = 3; i < m_body.size(); ++i) {
        if (m_head == m_body[i]) {
            m_alive = false;
            return;
        }
    }
}

chtype Snake::currentHeadSymbol() const {
    switch (m_head.direction()) {
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
