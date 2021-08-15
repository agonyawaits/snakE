#include "Launcher.hpp"
#include <ctime>
#include <random>

#define WINDOW_HEIGHT 20
#define WINDOW_WIDTH 60

int main() {
    srand(time(nullptr));

    Launcher l(Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT), Vector2i());

    return 0;
}
