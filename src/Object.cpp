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

Vector2i Object::position() const {
    return m_position;
}

Direction Object::direction() const {
    return m_direction;
}

void Object::draw(WINDOW* window) const {
    mvwaddch(window, m_position.y(), m_position.x(), '@');
}

void Object::draw(WINDOW* window, const chtype& symbol) const {
    mvwaddch(window, m_position.y(), m_position.x(), symbol);
}

void Object::move(const Direction& direction) {
    m_direction = canChangeDirection(direction) ? direction : m_direction;

    switch (m_direction) {
        case Direction::UP:
        {
            moveTo(Vector2i(m_position.x(), m_position.y()-1));
        } break;

        case Direction::DOWN:
        {    
            moveTo(Vector2i(m_position.x(), m_position.y()+1));
        } break;

        case Direction::LEFT:
        {    
            moveTo(Vector2i(m_position.x()-1, m_position.y()));
        } break;

        case Direction::RIGHT:
        {    
            moveTo(Vector2i(m_position.x()+1, m_position.y()));
        } break;

        case Direction::NONE:
        {    
        } break;

        default:
        {
            throw "Unsupported direction!";
        } break;
    }
}

void Object::moveTo(const Vector2i& position) {
    m_position = position;
}

bool Object::operator== (const Object& other) const {
    return other.m_position == m_position;
}

bool Object::canChangeDirection(const Direction& direction) const {
    return (direction != Direction::NONE && m_direction == Direction::NONE) ||
        (direction == Direction::UP && m_direction != Direction::DOWN) ||
        (direction == Direction::DOWN && m_direction != Direction::UP) ||
        (direction == Direction::LEFT && m_direction != Direction::RIGHT) ||
        (direction == Direction::RIGHT && m_direction != Direction::LEFT);
}
