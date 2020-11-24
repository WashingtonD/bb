#ifndef PLATFORM_H_INCLUDED
#define PLATFORM_H_INCLUDED

class Platform
{
    char app;
    //int lgt;
    int px1;
    int px2;
    int px3;
    int px4;
    int py;
public:
    Platform(char ap = 'x', int pzx1 = 1, int pzx2 = 2, int pzx3 = 3, int pzx4 = 4, int pzy = 8) : app(ap), px1(pzx1), px2(pzx2),px3(pzx3), px4(pzx4), py(pzy) {}
    virtual ~Platform() {}
    friend ostream& operator<<(ostream& o, Platform& p)
    {return o << p.app;}
    int getx1() {return px1;}
    int getx2() {return px2;}
    int getx3() {return px3;}
    int getx4() {return px4;}
    int gety() {return py;}
    char getap() {return app;}
    void setx1(int x) {px1 = x;}
    void setx2(int x) {px2 = x;}
    void setx3(int x) {px3 = x;}
    void setx4(int x) {px4 = x;}

};





#endif // PLATFORM_H_INCLUDED
