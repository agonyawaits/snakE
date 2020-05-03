#include <ncurses.h>
#include "Direction.hpp"
#include "Snake.hpp"
#include "Object.hpp"
#include "Board.hpp"
#include <random>
#include <ctime>

void setupTerminal();
void finalizeTerminal();

int main() {
    srand(time(nullptr));
    setupTerminal();
    Board b(20, 40, Vector2i(0, 1));

    while(b.live()) {
        b.update();
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
