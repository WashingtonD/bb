#include "board.h"
#include <conio.h>

Board::Board(char ed, int h, int w, Ball* ball, Brick* brik, int size, Platform* plat)
{
    edge = ed;
    hg = h;
    wd = w;
    b = ball;
    br = brik;
    sz = size;
    pl = plat;
    op = ' ';
}
bool Board::checkbr(int i, int j)
{
    for(int k=0;k<sz;k++)
    {
        if((br[k].getx() == i || br[k].getxx() == i) && br[k].gety() == j)
           {
               return true;
           }
    }
return false;
}

bool Board::checkal(int i, int j)
{
    for(int k=0;k<sz;k++)
    {
        if((br[k].getx() == i || br[k].getxx() == i) && br[k].gety() == j)
           {
               if(br[k].getal() == true)
               {
                   return true;
               }
           }
    }
return false;
}
void Board::mright()
{
    if(pl->getx4()+1 != wd-1)
    {
    pl->setx1(pl->getx1()+1);
    pl->setx2(pl->getx2()+1);
    pl->setx3(pl->getx3()+1);
    pl->setx4(pl->getx4()+1);
    }
}
void Board::mleft()
{
    if(pl->getx1()-1 != 0)
    {
        pl->setx1(pl->getx1()-1);
        pl->setx2(pl->getx2()-1);
        pl->setx3(pl->getx3()-1);
        pl->setx4(pl->getx4()-1);
    }
}

bool Board::checkpl(int x,int y)
{
    if(y == pl->gety() && (x == pl->getx1() || x == pl->getx2() || x == pl->getx3() || x == pl->getx4()))
        return true;
return false;
}

void Board::death(int i, int j)
{
    for(int k=0;k<sz;k++)
    {
        if((br[k].getx() == i || br[k].getxx() == i) && br[k].gety() == j)
           {
               if(br[k].getal() == true)
               {
                  br[k].setal(false);
               }
           }
    }
}

ostream& operator<<(ostream& o, Board& b)
{
    for(int j=0;j<b.hg;j++)
    {
        for(int i=0;i<b.wd;i++)
        {
            if(i ==0 || j == 0 || i == b.wd -1 || j == b.hg-1)
            {
                o << b.edge;
            }
            else if(b.checkbr(i,j) && b.checkal(i,j))
            {
                o << b.br->getapp();
            }
            else if((j == b.pl->gety()) && (i == b.pl->getx1() || i == b.pl->getx2() || i == b.pl->getx3() || i == b.pl->getx4()))
            {
                o << b.pl->getap();
            }
            else if(i == b.b->getx() && j == b.b->gety())
            {
                o << *(b.b);
            }
            else
                o << ' ';
        }
o << endl;
    }
return o;
}                                     /// 1 = u+r, 2 = u+l, 3 = d+r, 4 = d+l;
int Board::mld()
{
    if(b->getx()-1 != 0 && b->gety()+1 != (hg-1)
       && (checkbr((b->getx()-1),(b->gety()+1)) != true || checkal(b->getx()-1,b->gety()+1) != true)
       &&  checkpl(b->getx()-1,b->gety()+1) != true)
        {
       if(GetAsyncKeyState(VK_LEFT))
        mleft();
       if(GetAsyncKeyState(VK_RIGHT))
        mright();
           Sleep(50);
           b->setps(b->getx()-1,b->gety()+1);
           return 0;
        }
    else if(b->gety()+1 == hg-1)
        return 10;
    else if(b->getx()-1 == 0 && b->gety()+ 1 == (hg-1))
        return 10;
    else if(b->getx()-1 == 0)
        return 3;
    else if(b->gety()+1 == pl->gety() && (b->getx()-1 == pl->getx1() || b->getx()-1 == pl->getx2()))
        return 2;
    else if(b->gety()+1 == pl->gety() && (b->getx()-1 == pl->getx3() || b->getx()-1 == pl->getx4()))
        return 1;
    else if(checkbr((b->getx()-1),(b->gety()+1)) == true && checkal(b->getx()-1,b->gety()+1) == true)
    {
        death(b->getx()-1,b->gety()+1);
        return 1;
    }
}
int Board::mrd()
{
    if(b->getx()+1 != (wd-1) && b->gety()+1 != (hg-1)
       && (checkbr((b->getx()+1),(b->gety()+1)) != true || checkal(b->getx()+1,b->gety()+1) != true)
       && checkpl(b->getx()+1,b->gety()+1) != true)
        {
        if(GetAsyncKeyState(VK_LEFT))
        mleft();
       if(GetAsyncKeyState(VK_RIGHT))
        mright();
        Sleep(50);
        b->setps(b->getx()+1,b->gety()+1);
        return 0;
        }
    else if(b->getx()+1 == (wd-1) && b->gety()+1 == (hg-1))
        return 10;
    else if(b->getx()+1 == (wd-1))
        return 4;
    else if (b->gety()+1 == pl->gety() && (b->getx()+1 == pl->getx3() || b->getx()+1 == pl->getx4()))
        return 1;
    else if (b->gety()+1 == pl->gety() && (b->getx()+1 == pl->getx1() || b->getx()+1 == pl->getx2()))
        return 2;
    else if(b->gety()+1 == (hg-1))
            return 10;
    else if(checkbr((b->getx()+1),(b->gety()+1)) == true && checkal(b->getx()+1,b->gety()+1) == true)
    {
        death(b->getx()+1,b->gety()+1);
        return 2;
    }
}
int Board::mlu()
{
    if(b->getx()-1 != 0 && b->gety()-1 != 0 && (checkbr((b->getx()-1),(b->gety()-1)) != true || checkal(b->getx()-1,b->gety()-1) != true))
    {
        if(GetAsyncKeyState(VK_LEFT))
        mleft();
        if(GetAsyncKeyState(VK_RIGHT))
        mright();
        Sleep(50);
        b->setps(b->getx()-1,b->gety()-1);
        return 0;
    }
    else if(b->getx()-1 == 0 && b->gety()-1 == 0)
        return 3;
    else if(b->getx()-1 == 0)
        return 1;
    else if(b->gety()-1 == 0)
        return 4;
    else if(checkbr((b->getx()-1),(b->gety()-1)) == true && checkal(b->getx()-1,b->gety()-1) == true)
    {
        death(b->getx()-1,b->gety()-1);
        return 3;
    }
}
int Board::mru()
{
    if(b->getx()+1 != (wd-1) && b->gety()-1 != 0 && (checkbr((b->getx()+1),(b->gety()-1)) != true || checkal(b->getx()+1,b->gety()-1) != true))
    {
        if(GetAsyncKeyState(VK_LEFT))
        mleft();
       if(GetAsyncKeyState(VK_RIGHT))
        mright();
        Sleep(50);
        b->setps(b->getx()+1,b->gety()-1);
        return 0;
    }
    else if(b->getx()+1 == (wd-1) && b->gety()-1 == 0)
        return 4;
    else if(b->getx()+1 == (wd-1))
        return 2;
    else if(b->gety()-1 == 0)
        return 3;
    else if(checkbr((b->getx()+1),(b->gety()-1)) == true && checkal(b->getx()+1,b->gety()-1) == true)
    {
        death(b->getx()+1,b->gety()-1);
        return 4;
    }
}
/// 1 = u+r, 2 = u+l, 3 = d+r, 4 = d+l;
int Board::cm(int x)
{
int q = 0;
if(x == 1)
{
    while(true)
    {
       cursor();
       q = mru();
      cout << *this;
       if(q != 0)
        break;
    }
}
else if(x == 2)
{
    while(true)
    {
        cursor();
        q = mlu();
       cout << *this;
        if(q != 0)
            break;
    }
}
else if(x == 3)
{
    while(true)
    {
        cursor();
        q = mrd();
       cout << *this;
        if(q != 0)
            break;
    }
}
else if(x == 4)
{
    while(true)
    {
    cursor();
    q = mld();
    cout << *this;
       if(q!=0)
        break;
    }
}

if(q == 10)
    return 10;
return q;
}



