#include "board.h"
#include "ball.h"
#include "brick.h"
#include "platform.h"
#include <conio.h>

int main()
{
//bool f = true;
//while(true)
//{
//if(f == true)
//{
Ball* bal = new Ball('@',14,12,true);
Brick* br = new Brick[9];
Platform* pl = new Platform('x',12,13,14,15,13);
br[0] = Brick('o',2,3,1);
br[1] = Brick('o',5,6,1);
br[2] = Brick('o',8,9,1);
br[3] = Brick('o',11,12,1);
br[4] = Brick('o',14,15,1);
br[5] = Brick('o',17,18,1);
br[6] = Brick('o',20,21,1);
br[7] = Brick('o',23,24,1);
br[8] = Brick('o',26,27,1);
Board boar('#',15,30,bal,br,9,pl);
cout << boar;
int x = 1;
boar.ShowConsoleCursor(false);
char q;
q = _getch();
if(q == ' ')
while(true)
{
   if(x == 10)
    {
    break;
    }
   x = boar.cm(x);
}
system("Pause");
cout << "GAME OVER!" << endl;
system("Pause");
}
