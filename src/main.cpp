#include "v2.h"
#include "game.h"
#include "window.h"
#include <ctime>
#include <random>

#define WINDOW_HEIGHT 50
#define WINDOW_WIDTH 170

// TODO: Add menu
//////////////////////////////////////////////////
//                                              //
//                                              //
//                                              //
//                                              //
//                                              //
//                    Play                      //
//                 Borders: Off                 //
//                    Exit                      //
//                                              //
//                                              //
//                                              //
//                                              //
//////////////////////////////////////////////////

int main() {
    srand(time(nullptr));

    Window window({ WINDOW_WIDTH, WINDOW_HEIGHT}, { 0, 0 });
    Game game(window);

    return 0;
}
