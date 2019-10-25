//  main.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include <iostream>
#include "include/Game.h"
#include <random>
#include <ctime>

int main() {
    srand( time( nullptr ) );

    Game game;
    game.launch();

    return 0;
}
