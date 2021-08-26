#include "game.h"
#include "window.h"
#include "entity.h"
#include "snake.h"
#include "board.h"

#define POINTS_PER_APPLE 10

Game::Game(const Window &window)
    : m_window(window), m_wasted(false),
    m_board({ m_window.size().x()-1, m_window.size().y()-2 }),
    m_snake({ m_board.spot() }),
    m_apple({ m_board.spot() }),
    m_score({ V2(0, m_window.size().y()-1), POINTS_PER_APPLE })
{
    while(!m_wasted) {
        render();
        update();
    }
}

void
Game::render() const {
    m_window.clear();
    m_window.render(m_board, YELLOW);
    m_window.render(m_snake, GREEN);
    m_window.render(m_apple, RED);
    m_window.render(m_score);
}

void
Game::update() {
    if(m_snake.head() == m_apple) {
        do {
            m_apple = Entity(m_board.spot());
        } while(m_snake.collides(m_apple));

        m_snake.extend();
        m_score.increase();
    }

    m_snake.move(m_window.input().direction());
    m_wasted = m_snake.collides(m_board) || m_snake.died(); 
}

Score::Score(const V2 &position, int step)
    : m_position(position), m_score(0), m_step(step)
{
}

void
Score::increase() {
    m_score += m_step;
}

void
Score::draw(WINDOW *window) const {
    mvwprintw(window, m_position.y(), m_position.x(), "%d", m_score);
}
