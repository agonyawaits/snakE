#include "Terminal.hpp"
#include "Window.hpp"
#include "Game.hpp"

Terminal::Terminal(const Vector2i& size)
    : m_size(size)
{
    initscr();
    noecho();
    curs_set(0);
    halfdelay(1);
}

Terminal::~Terminal() {
    endwin();
}

void Terminal::runGame() const {
    Window window(m_size, Vector2i());
    Game game(window);
    game.execute();
}
