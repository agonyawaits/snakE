#include <ncurses.h>
#include "Direction.hpp"
#include "Snake.hpp"
#include "Object.hpp"

int main() {
    initscr();
    noecho();
    curs_set( 0 );
    halfdelay( 1 );
    WINDOW* win = newwin(20, 40, 1, 0);
    keypad(win, TRUE);

    Snake obj(Vector2i(5,10));
    Object obj1(Vector2i(10,11));
    obj.extend();
    obj.extend();
    obj.extend();
    obj.extend();
    obj.extend();
    obj.extend();
    obj.extend();
    obj.extend();
    obj.extend();
    obj.extend();
    obj.extend();
    obj.extend();
    while (wgetch(win) != 'c') {
        wclear(win);
        box(win, 0, 0);

        obj.move(Direction::RIGHT);
        obj.draw(win);
        obj1.draw(win, '@');
    }

    while (wgetch(win) != 'c') {
        wclear(win);
        box(win, 0, 0);

        obj.move(Direction::DOWN);
        obj.draw(win);
        obj1.draw(win, '@');
    }

    while (wgetch(win) != 'c') {
        wclear(win);
        box(win, 0, 0);

        obj.move(Direction::LEFT);
        obj.draw(win);
        obj1.draw(win, '@');
    }

    while (wgetch(win) != 'c') {
        wclear(win);
        box(win, 0, 0);

        obj.move(Direction::UP);
        obj.draw(win);
        obj1.draw(win, '@');
    }

    delwin( win );
    endwin();
}
