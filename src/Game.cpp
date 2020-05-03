#include "Game.hpp"
#include "Window.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Direction.hpp"

Game::Game(const Window& window)
    : m_window(window), m_snake(Snake(m_window.randomPosition())),
    m_apple(Object(m_window.randomPosition())), m_isOver(false)
{
}

bool Game::isOver() const {
    return m_isOver;
}

void Game::render() const {
    m_window.clear();
    m_window.drawBorder();
    m_window.drawSnake(m_snake);
    m_window.drawObject(m_apple, '@');
}

void Game::update() {
    if (m_snake.headPosition() == m_apple.position()) {
        m_apple = Object(m_window.randomPosition());
        m_snake.extend();
    }

    m_snake.move(parseInput(m_window.getInput()));
    m_isOver = m_isOver || !(m_snake.alive() && noCollision());
}

Direction Game::parseInput(const int& input) const {
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

bool Game::noCollision() const {
    return m_snake.headPosition().x() > 0 &&
        m_snake.headPosition().x() < m_window.width()-1 &&
        m_snake.headPosition().y() > 0 &&
        m_snake.headPosition().y() < m_window.height()-1;
}
