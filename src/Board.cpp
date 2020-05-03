#include "Board.hpp"
#include "Window.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Vector2.hpp"
#include "Direction.hpp"
#include <ncurses.h>
#include <random>

Board::Board(const int& h, const int& w, const Vector2i& position)
    : Window(h, w, position), m_snake(Snake(randomPosition())),
    m_apple(Object(randomPosition())), m_live(true)
{
    keypad(m_window, TRUE);
}

bool Board::live() const {
    return m_live;
}

void Board::update() {
    if (!m_live) {
        return;
    }

    wclear(m_window);
    draw();
    m_snake.draw(m_window);
    m_apple.draw(m_window, '@');

    if (m_snake.headPosition() == m_apple.position()) {
        m_apple = Object(randomPosition());
        m_snake.extend();
    }

    m_snake.move(parseInput(wgetch(m_window)));
    m_live = m_snake.alive() && noCollision();
}

void Board::draw() const {
    box(m_window, 0, 0);
}

Vector2i Board::randomPosition() const {
    return Vector2i(
        rand() % (m_width-2) + 1,
        rand() % (m_height-2) + 1
    );
}

Direction Board::parseInput(const int& input) const {
    switch (input) {
        case KEY_LEFT:
            return Direction::LEFT;

        case KEY_RIGHT:
            return Direction::RIGHT;

        case KEY_UP:
            return Direction::UP;

        case KEY_DOWN:
            return Direction::DOWN;

        default:
            return Direction::NONE;
    }
}

bool Board::noCollision() const {
    return m_snake.headPosition().x() > 0 &&
        m_snake.headPosition().x() < m_width &&
        m_snake.headPosition().y() > 0 &&
        m_snake.headPosition().y() < m_height;
}
