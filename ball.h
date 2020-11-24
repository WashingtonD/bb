#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include <iostream>

using namespace std;

class Ball
{
    char app;
    int px;
    int py;
    bool fixed;
public:
    Ball(char a = '@', int x = 0, int y = 0, bool f = true) : app(a), px(x), py(y), fixed(f) {}
    virtual ~Ball() {}
    friend ostream& operator<<(ostream& o, Ball& b)
    {return o << b.app;}
    int getx() {return px;}
    int gety() {return py;}
    void setps(int x, int y) {px = x; py =y;}
};



#endif // BALL_H_INCLUDED
