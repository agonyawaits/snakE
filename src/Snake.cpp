#include "Snake.hpp"
#include "Object.hpp"
#include "Vector2.hpp"
#include "Direction.hpp"
#include "Window.hpp"
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

bool Snake::collides(const Window& window) const {
    return head().x() == 0 ||
        head().y() == 0 ||
        head().x() == window.size().x()-1 ||
        head().y() == window.size().y()-1;
}

void Snake::draw(WINDOW* window) const {
    head().draw(window, selfie());
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

    if (died()) {
        m_alive = false;
    }
}

void Snake::extend() {
    m_body.emplace_back(
        Object(
            m_body.back().position()
        )
    );
}

bool Snake::died() const {
    if (m_body.size() < 5) {
        return false;
    }

    for (int i = 4; i < m_body.size(); ++i) {
        if (head() == m_body[i]) {
            return true;
        }
    }

    return false;
}

chtype Snake::selfie() const {
    switch (head().direction()) {
        case Direction::LEFT :
            return '<';

        case Direction::RIGHT :
            return '>';

        case Direction::UP :
            return '^';

        case Direction::DOWN :
            return 'v';

        case Direction::NONE:
            return '*';

        default:
            throw "Unsupported direction";
    }
}
