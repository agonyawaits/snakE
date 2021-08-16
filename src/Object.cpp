#include "Object.hpp"
#include "Vector2.hpp"
#include "Direction.hpp"
#include <ncurses.h>

#define CHAR_DEFAULT '@'

Object::Object()
    : m_position(Vector2i()), m_direction(NONE)
{
}

Object::Object(const Vector2i& position)
    : m_position(position), m_direction(NONE)
{
}

Vector2i Object::position() const {
    return m_position;
}

Direction Object::direction() const {
    return m_direction;
}

void Object::draw(WINDOW* window) const {
    mvwaddch(window, m_position.y(), m_position.x(), CHAR_DEFAULT);
}

void Object::draw(WINDOW* window, const chtype& symbol) const {
    mvwaddch(window, m_position.y(), m_position.x(), symbol);
}

void Object::move(const Direction& direction) {
    m_direction = canChangeDirection(direction) ? direction : m_direction;

    switch (m_direction) {
        case UP:
        {
            moveTo(Vector2i(m_position.x(), m_position.y()-1));
        } break;

        case DOWN:
        {    
            moveTo(Vector2i(m_position.x(), m_position.y()+1));
        } break;

        case LEFT:
        {    
            moveTo(Vector2i(m_position.x()-1, m_position.y()));
        } break;

        case RIGHT:
        {    
            moveTo(Vector2i(m_position.x()+1, m_position.y()));
        } break;

        case NONE:
        default:
        {
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
    return (direction != NONE && m_direction == NONE) ||
        (direction == UP && m_direction != DOWN) ||
        (direction == DOWN && m_direction != UP) ||
        (direction == LEFT && m_direction != RIGHT) ||
        (direction == RIGHT && m_direction != LEFT);
}
