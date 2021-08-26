#include "snake.h"
#include "entity.h"
#include "board.h"
#include "v2.h"
#include "window.h"
#include <ncurses.h>
#include <vector>

#define MIN_SIZE_CAN_DIE 5

Snake::Snake()
    : m_body(std::vector<Entity>{ Entity(V2()) })
{
}

Snake::Snake(const V2& position)
    : m_body(std::vector<Entity>{ Entity(position) })
{
}

Entity
Snake::head() const {
    return m_body.front();
}

bool
Snake::collides(const Entity &Entity) const {
    for(const auto &block : m_body)
        if(block == Entity)
            return true;

    return false;
}

bool
Snake::collides(const Board &board) const {
    return head().position().x() == 0 ||
        head().position().y() == 0 ||
        head().position().x() == board.size().x() ||
        head().position().y() == board.size().y();
}

void
Snake::draw(WINDOW *window) const {
    head().draw(window, '*');
    for(size_t i = 1; i < m_body.size(); ++i)
        m_body[i].draw(window, 'o');
}

void
Snake::move(Direction direction) {
    for(size_t i = m_body.size()-1; i > 0; --i)
        m_body[i].moveTo(m_body[i-1].position());
    m_body.front().move(direction);
}

void
Snake::extend() {
    m_body.emplace_back(m_body.back().position());
}

bool
Snake::died() const {
    if(m_body.size() < MIN_SIZE_CAN_DIE)
        return false;

    for(size_t i = MIN_SIZE_CAN_DIE; i < m_body.size(); ++i)
        if(head() == m_body[i])
            return true;

    return false;
}
