#include "Object.hpp"
#include "Vector2.hpp"
#include "Direction.hpp"
#include <ncurses.h>

Object::Object()
    : m_position(Vector2i()), m_direction(Direction::NONE)
{
}

Object::Object(const Vector2i& position)
    : m_position(position), m_direction(Direction::NONE)
{
}

Object::~Object()
{
}

int Object::x() const {
    return m_position.x();
}

int Object::y() const {
    return m_position.y();
}

Vector2i Object::position() const {
    return m_position;
}

Direction Object::direction() const {
    return m_direction;
}

void Object::draw(WINDOW* window, const chtype symbol) const {
    mvwaddch(window, y(), x(), symbol);
}

void Object::move(const Direction& direction) {
    m_direction = canChangeDirection(direction) ? direction : m_direction;

    switch (m_direction) {
        case Direction::UP:
            m_position = Vector2i(x(), y()-1);
            break;

        case Direction::DOWN:
            m_position = Vector2i(x(), y()+1);
            break;

        case Direction::LEFT:
            m_position = Vector2i(x()-1, y());
            break;

        case Direction::RIGHT:
            m_position = Vector2i(x()+1, y());
            break;

        case Direction::NONE:
            break;

        default:
            throw "Unsupported direction!";
    }
}

bool Object::operator== (const Object& other) const {
    return other.m_position == m_position;
}

bool Object::canChangeDirection(const Direction& direction) const {
    return (m_direction == Direction::NONE) ||
        (direction == Direction::UP && m_direction != Direction::DOWN) ||
        (direction == Direction::DOWN && m_direction != Direction::UP) ||
        (direction == Direction::LEFT && m_direction != Direction::RIGHT) ||
        (direction == Direction::RIGHT && m_direction != Direction::LEFT);
}
