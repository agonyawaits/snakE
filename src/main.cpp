#include "v2.h"
#include "game.h"
#include "window.h"
#include <ctime>
#include <random>

int main() {
    srand(time(nullptr));

    Window window({ 0, 0 });
    Game game(window);

    return 0;
}
