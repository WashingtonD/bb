#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include <iostream>
#include "ball.h"
#include "brick.h"
#include "platform.h"
#include <windows.h>

using namespace std;

class Board
{
    int wd;
    int hg;
    char edge;
    Ball* b;
    Brick* br;
    int sz;
    char op;
    Platform* pl;
public:
    Board(char ed, int h, int w, Ball* ball, Brick* brik, int size, Platform* plat);
    virtual ~Board() {}
    friend ostream& operator<<(ostream& o, Board& b);
    bool checkbr(int i, int j);
    bool checkal(int i, int j);
    bool checkpl(int x, int y);
    void death(int i,int j);
    int mru();
    int mrd();
    int mlu();
    int mld();
    int cm(int x);
    void mright();
    void mleft();
    void cursor()
    {
        COORD cpos;
        cpos.X = 0;
        cpos.Y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cpos);
    }

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    cursorInfo.dwSize = 20;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}
};







#endif // BOARD_H_INCLUDED
