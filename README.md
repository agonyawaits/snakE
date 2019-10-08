Snake game written on C++ for Unix Terminal
-------------------------------------------
To launch the game:
1) Download the executable file /src/snake_exec.<br/>2) Execute the following command in terminal: "chmod +x $YOUR_PATH$/snake_exec".<br/>3) Run and enjoy :).

OR

You can create an executable yourself:
1) First, you need to install ncurses ( i/o lib for unix )
```bash
$ brew install ncurses
```
2) Clone repository
```bash
$ git clone https://github.com/agonyawaits/snake
```
3) Compile and run:
```bash
$ g++ Apple.cpp Desk.cpp Game.cpp Snake.cpp main.cpp -lncurses -std=c++17
$ ./a.out
```
