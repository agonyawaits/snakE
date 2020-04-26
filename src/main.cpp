//  main.cpp
//  snake
//  Copyright © 2019 Nikita Tokariev. All rights reserved.
#include "Game.h"
#include <random>
#include <ctime>

int main( int argc, const char** argv ) {
    srand( time( nullptr ) );

    return argc < 3 ?
        Game::run() :
        Game::run( std::atoi( argv[ 1 ] ), std::atoi( argv[ 2 ] ) );
}
