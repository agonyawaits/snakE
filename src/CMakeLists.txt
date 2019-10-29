cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_FLAGS "-std=c++2a -lncurses")

project(snake)

add_executable(
	snake
	main.cpp
	Apple.cpp
	Snake.cpp
	Desk.cpp
	Game.cpp
)
