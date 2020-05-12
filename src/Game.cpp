#include "Game.hpp"
#include "Window.hpp"
#include "Object.hpp"
#include "Snake.hpp"
#include "Score.hpp"
#include "Color.hpp"

Game::Game(const Window& window)
    : m_window(window), m_wasted(false),
    m_board(Vector2i(m_window.size().x()-1, m_window.size().y()-2)),
    m_snake(Snake(m_board.randomPosition())),
    m_apple(Object(m_board.randomPosition())),
    m_score(Score(Vector2i(0, m_window.size().y()-1), 10))
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
    m_window.render(m_board, Color::YELLOW);
    m_window.render(m_snake, Color::GREEN);
    m_window.render(m_apple, Color::RED);
    m_window.render(m_score);
}

void Game::update() {
    if (m_snake.head() == m_apple) {
        do {
            m_apple = Object(m_board.randomPosition());
        } while(m_snake.collides(m_apple));

        m_snake.extend();
        m_score.increase();
    }

    m_snake.move(m_window.getInput().direction());
    m_wasted = !m_snake.alive() || m_snake.collides(m_board);
}
