#include "Terminal.hpp"
#include <ctime>
#include <random>

int main() {
    srand(time(nullptr));

    Terminal terminal(Vector2i(40, 20));
    terminal.runGame();

    return 0;
}
