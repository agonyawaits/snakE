#include "Game.hpp"
#include "Window.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Direction.hpp"

Game::Game(const Window& window)
    : m_window(window), m_board(window.size()), m_snake(Snake(m_board.randomPosition())),
    m_apple(Object(m_board.randomPosition())), m_isOver(false)
{
}

void Game::execute() {
    while (!m_isOver) {
        render();
        update();
    }
}

void Game::render() const {
    m_window.clear();
    m_window.render(m_board);
    m_window.render(m_snake);
    m_window.render(m_apple, '@');
}

void Game::update() {
    if (m_snake.head() == m_apple) {
        do {
            m_apple = Object(m_board.randomPosition());
        } while(m_snake.collides(m_apple));

        m_snake.extend();
    }

    m_snake.move(parseInput(m_window.getInput()));
    m_isOver = m_isOver || !m_snake.alive() || m_snake.collides(m_board);
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
