#include <unistd.h>
#include <cassert>
#include "game.h"
#include "window.h"
#include "entity.h"
#include "snake.h"
#include "board.h"

#define POINTS_PER_APPLE 10
#define BOARDW 50
#define BOARDH 15

Game::Game(const Window &window) 
    : m_window(window), m_menu(window.size()), m_wasted(false),
    m_board({ BOARDW, BOARDH }, { (window.size().x-BOARDW)/2, (window.size().y-BOARDH)/2 }),
    m_snake(m_board.spot()),
    m_apple(m_board.spot()),
    m_score({ m_board.position().x, BOARDH+m_board.position().y+1 }, POINTS_PER_APPLE)
{
    assert(BOARDW < m_window.size().x && BOARDH < m_window.size().y);
    for(;;)
    {
        launch_menu();
        if(m_menu.quited())
            break;
        launch_game();
        sleep(1);
        reset();
    }
}

void
Game::launch_menu() {
    while(m_menu.active()) {
        m_window.clear();
        m_window.render(m_menu);
        m_menu.update(m_window.input().key());
    }
}

void
Game::launch_game() {
    while(!m_wasted) {
        render();
        update();
    }
}

void
Game::reset() {
    m_snake = { m_board.spot() };
    m_apple = { m_board.spot() };
    m_wasted = false;
    m_menu.reset();
    m_score.reset();
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
            m_apple = { m_board.spot() };
        } while(m_snake.collides(m_apple));

        m_snake.extend();
        m_score.increase();
    }

    m_snake.move(m_window.input().direction());
    if(m_menu.borders_on()) {
        m_wasted = m_snake.collides(m_board) || m_snake.died();
    } else {
        m_wasted = m_snake.died();
        if(!m_wasted && m_snake.collides(m_board)) {
            m_snake.relocate(m_board.spot());
        }
    }
}

Score::Score(const V2 &position, int step)
    : m_position(position), m_score(0), m_high_score(0), m_step(step)
{
}

void
Score::increase() {
    m_score += m_step;
}

void
Score::draw(WINDOW *window) const {
    mvwprintw(window, m_position.y, m_position.x, "Score %d", m_score);
    mvwprintw(window, m_position.y+1, m_position.x, "Hi-Score %d", m_high_score);
}

void
Score::reset() {
    m_high_score = m_score > m_high_score ? m_score : m_high_score;
    m_score = 0;
}
