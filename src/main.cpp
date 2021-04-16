#include "Terminal.hpp"
#include <ctime>
#include <random>

int main() {
    srand(time(nullptr));

    Terminal t(Vector2i(60, 20));
    t.snake();
}
