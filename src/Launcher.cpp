#include "Launcher.hpp"
#include "Window.hpp"
#include "Game.hpp"

Launcher::Launcher(const Vector2i& windowSize, const Vector2i& windowPos)
{
    initscr();
    noecho();
    curs_set(0);
    halfdelay(1);
    start_color();

    Window window(windowSize, windowPos);
    Game game(window);
    game.execute();
}

Launcher::~Launcher() {
    endwin();
}
