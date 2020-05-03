#include "Window.hpp"
#include "Vector2.hpp"
#include <ncurses.h>
#include <random>

Window::Window(const Vector2u& size, const Vector2i& position)
    : m_size(size), m_window(newwin(m_size.y(), m_size.x(), position.y(), position.x()))
{
    keypad(m_window, TRUE);
}

Window::~Window() {
    delwin(m_window);
}

int Window::height() const {
    return m_size.y();
}

int Window::width() const {
    return m_size.x();
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
        rand() % (m_size.x()-2) + 1,
        rand() % (m_size.y()-2) + 1
    );
}
