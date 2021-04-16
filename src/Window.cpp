#include "Window.hpp"
#include "Vector2.hpp"
#include "IDrawable.hpp"
#include "Input.hpp"
#include "Color.hpp"
#include <ncurses.h>

#define GREEN_ON_BLACK  1
#define RED_ON_BLACK    2
#define YELLOW_ON_BLACK 3

Window::Window(const Vector2i& size, const Vector2i& position)
    : m_size(size), m_window(newwin(m_size.y(), m_size.x(), position.y(), position.x()))
{
    keypad(m_window, TRUE);
    wattron(m_window, A_BOLD);
    init_pair(GREEN_ON_BLACK, COLOR_GREEN, COLOR_BLACK);
    init_pair(RED_ON_BLACK, COLOR_RED, COLOR_BLACK);
    init_pair(YELLOW_ON_BLACK, COLOR_YELLOW, COLOR_BLACK);
}

Window::~Window() {
    delwin(m_window);
}
void Window::clear() const {
    wclear(m_window);
}

Input Window::input() const {
    return Input(wgetch(m_window));
}

Vector2i Window::size() const {
    return m_size;
}

void Window::render(const IDrawable& drawable) const {
    drawable.draw(m_window);
}

void Window::render(const IDrawable& drawable, const Color& color) const {
    switch (color) {
        case Color::GREEN:
        {
            wattron(m_window, COLOR_PAIR(GREEN_ON_BLACK));
            drawable.draw(m_window);
            wattroff(m_window, COLOR_PAIR(GREEN_ON_BLACK));
        } break;

        case Color::RED:
        {
            wattron(m_window, COLOR_PAIR(RED_ON_BLACK));
            drawable.draw(m_window);
            wattroff(m_window, COLOR_PAIR(RED_ON_BLACK));
        } break;

        case Color::YELLOW:
        {    
            wattron(m_window, COLOR_PAIR(YELLOW_ON_BLACK));
            drawable.draw(m_window);
            wattroff(m_window, COLOR_PAIR(YELLOW_ON_BLACK));
        } break;

        default:
        {
            drawable.draw(m_window);
        } break;
    }
}
