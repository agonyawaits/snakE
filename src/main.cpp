#include <ctime>
#include <random>
#include <ncurses.h>
#include "v2.h"
#include "game.h"
#include "window.h"

int main() {
    srand(time(nullptr));

    Window window;
    Game game(window);

    return 0;
}
