#include "Game.hpp"
#include "Window.hpp"
#include <ncurses.h>
#include <random>
#include <ctime>

void setupTerminal();
void finalizeTerminal(); // TODO: Think what to do with this two guys.

int main() {
    srand(time(nullptr));
    setupTerminal();

    Window w(Vector2i(40, 20), Vector2i(0, 1));
    Game g(w);
    g.execute();

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
