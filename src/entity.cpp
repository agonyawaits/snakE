#include <ncurses.h>
#include "entity.h"
#include "v2.h"

#define CHAR_DEFAULT '@'
#define CHECK_DIRECTION(new, old)        \
    (((new) != NONE && (old) == NONE) || \
    ((new) == UP && (old) != DOWN)    || \
    ((new) == DOWN && (old) != UP)    || \
    ((new) == LEFT && (old) != RIGHT) || \
    ((new) == RIGHT && (old) != LEFT))

Entity::Entity()
    : m_position({}), m_direction(NONE)
{
}

Entity::Entity(const V2 &position)
    : m_position(position), m_direction(NONE)
{
}

V2
Entity::position() const {
    return m_position;
}

Direction
Entity::direction() const {
    return m_direction;
}

void
Entity::draw(WINDOW *window) const {
    mvwaddch(window, m_position.y(), m_position.x(), CHAR_DEFAULT);
}

void
Entity::draw(WINDOW *window, chtype symbol) const {
    mvwaddch(window, m_position.y(), m_position.x(), symbol);
}

void
Entity::moveTo(const V2 &position) {
    m_position = position;
}

V2
Entity::newPos() const {
    switch(m_direction) {
        case UP:    return { m_position.x(), m_position.y()-1 };
        case DOWN:  return { m_position.x(), m_position.y()+1 };
        case LEFT:  return { m_position.x()-1, m_position.y() };
        case RIGHT: return { m_position.x()+1, m_position.y() };
        case NONE:  return m_position;
    }
}

void
Entity::move(Direction direction) {
    m_direction = CHECK_DIRECTION(direction, m_direction) ? direction : m_direction;
    moveTo(newPos());
}

bool
Entity::operator==(const Entity &other) const {
    return other.m_position == m_position;
}
