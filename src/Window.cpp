#include "Window.hpp"
#include "Vector2.hpp"
#include <ncurses.h>
#include <random>
#include <unistd.h>

Window::Window(const int& h, const int& w, const Vector2i& position)
    : m_height(h), m_width(w),
    m_window(newwin(m_height, m_width, position.y(), position.x()))
{
    keypad(m_window, TRUE);
}

Window::~Window() {
    delwin(m_window);
}

int Window::h() const {
    return m_height;
}

int Window::w() const {
    return m_width;
}

void Window::clear() const {
    wclear(m_window);
}

void Window::drawBorder() const {
    box(m_window, 0, 0);
}

void Window::drawObject(const Object& object, const chtype symbol) const {
    object.draw(m_window, symbol);
}

void Window::drawSnake(const Snake& snake) const {
    snake.draw(m_window);
}

int Window::getInput() const {
    return wgetch(m_window);
}

Vector2i Window::randomPosition() const {
    return Vector2i(
        rand() % (m_width-2) + 1,
        rand() % (m_height-2) + 1
    );
}
