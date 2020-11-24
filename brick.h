#ifndef BRICK_H_INCLUDED
#define BRICK_H_INCLUDED
#include <iostream>

using namespace std;

class Brick
{
   char app;
   int x1;
   int x2;
   int y;
   bool alive;
   public:
        Brick(char a = 'o', int x = 1, int xx = 2, int y = 1, bool al = "true") : app(a), x1(x), x2(xx), y(y), alive(al) {}
        int getx() {return x1;}
        int getxx() {return x2;}
        int gety() {return y;}
        char getapp() {return app;}
        bool getal() {return alive;}
        void setal(bool f) {alive = f;}
};




#endif // BRICK_H_INCLUDED
