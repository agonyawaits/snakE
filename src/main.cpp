#include "Game.hpp"
#include "Window.hpp"
#include <ncurses.h>
#include <random>
#include <ctime>

void setupTerminal();
void finalizeTerminal();

int main() {
    srand(time(nullptr));
    setupTerminal();

    Window w(20, 40, Vector2i(0, 1));
    Game g(w);

    while(!g.isOver()) {
        g.draw();
        g.update();
    }

    finalizeTerminal();
}

void setupTerminal() {
    initscr();
    noecho();
    curs_set( 0 );
    halfdelay( 1 );
}

void finalizeTerminal() {
    endwin();
}
