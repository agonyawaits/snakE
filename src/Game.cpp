#include "Game.hpp"
#include "Window.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Direction.hpp"

Game::Game(const Window& window)
    : m_window(window), m_board(Vector2i(window.size().x()-2, window.size().y()-2)), m_snake(Snake(m_window.randomPosition())),
    m_apple(Object(m_window.randomPosition())), m_wasted(false)
{
}

void Game::execute() {
    while (!m_wasted) {
        render();
        update();
    }
}

void Game::render() const {
    m_window.clear();
    m_window.render(m_board);
    m_window.render(m_snake);
    m_window.render(m_apple);// window size, random position, add score printing
}

void Game::update() {
    if (m_snake.head() == m_apple) {
        do {
            m_apple = Object(m_window.randomPosition());
        } while(m_snake.collides(m_apple));

        m_snake.extend();
    }

    m_snake.move(m_window.getInput().direction());
    m_wasted = !m_snake.alive() || m_snake.collides(m_board);
}
