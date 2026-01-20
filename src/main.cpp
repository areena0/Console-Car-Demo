#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

using namespace std;

// wav sound effects
static void playPop() {
    PlaySound(TEXT("sounds\\pop.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

static void playExit() {
    PlaySound(TEXT("sounds\\exit.wav"), NULL, SND_FILENAME | SND_SYNC);
}

// hide cursor
void hideCursor() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(h, &info);
    info.bVisible = false;
    SetConsoleCursorInfo(h, &info);
}

// moving cursor to top-left
void resetCursor() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 0, 0 };
    SetConsoleCursorPosition(h, pos);
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    hideCursor();

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    const int carWidth = 17;
    const int carHeight = 4;

    int x = 10;
    int y = 5;

    while (true) {
        // input
        if (_kbhit()) {
            int key = _getch();

            if (key == 224 || key == -32) {
                key = _getch();

                if (key == 72) y--;      // Up
                if (key == 80) y++;      // Down
                if (key == 75) x--;      // Left
                if (key == 77) x++;      // Right

                playPop();
            }

            if (key == 'x' || key == 'X') {
                resetCursor();
                cout << "Shifting to park...\n";
                playExit();   // blocks until sound finishes
                exit(0);
            }
        }

        // CLAMPS
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x > consoleWidth - carWidth)  x = consoleWidth - carWidth;
        if (y > consoleHeight - carHeight) y = consoleHeight - carHeight;

        // FRAME BUILDING
        string frame;
        frame.reserve(consoleWidth * consoleHeight);

        for (int row = 0; row < consoleHeight; row++) {
            for (int col = 0; col < consoleWidth; col++) {
                bool draw = false;

                if (row == y && col >= x && col < x + carWidth) {
                    frame += "    _____"[col - x];
                    draw = true;
                }
                else if (row == y + 1 && col >= x && col < x + carWidth) {
                    frame += "___/     |____"[col - x];
                    draw = true;
                }
                else if (row == y + 2 && col >= x && col < x + carWidth) {
                    frame += "|_____________|"[col - x];
                    draw = true;
                }
                else if (row == y + 3 && col >= x && col < x + carWidth) {
                    frame += "  O          O"[col - x];
                    draw = true;
                }

                if (!draw)
                    frame += ' ';
            }
            frame += '\n';
        }


        //RENDERING
        resetCursor();
        cout << frame;

        Sleep(33); // ~30 FPS
    }
}
