#include <stdio.h>
#include <math.h>
#include <Windows.h>
#define PI 3.14159226535897
void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}
void printBomb(int isExploded)
{
    if (isExploded)
    {
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!!BAM!!");
        printf("\x1b[B\x1b[7D^^^^^^^");
    }
    else
        printf("(  b  )");
}
int main()
{
    int rpt = 0, dir = 1, cnt = 0, tms = 2, addcnt = 0, x = 14, y = 9;
    moveCursor(x, y);
    printf("*");
    while (rpt < 12)
    {
        while (cnt < tms)
        {
            if (dir == 1)
            {
                y += 1;
            }
            else if (dir == 2)
            {
                x += 1;
            }
            else if (dir == 3)
            {
                y -= 1;
            }
            else //dir==4
            {
                x -= 1;
            }
            moveCursor(x, y);
            printf("#");
            Sleep(10);
            cnt++;
        }
        cnt = 0;
        if (dir == 4)
        {
            dir = 1;
        }
        else
        {
            dir++;
        }
        addcnt++;
        if (addcnt == 2)
        {
            tms += 2;
            addcnt = 0;
        }
        rpt++;
    }
    moveCursor(x - 7, y);
    printBomb(0);
    //////////////////////////////////////////////////
    int xx = 14, yy = 9;
    rpt = 0;
    dir = 1;
    cnt = 0;
    tms = 2;
    addcnt = 0;
    x = 14;
    y = 9;
    moveCursor(x, y);
    printf("*");
    while (rpt < 12)
    {
        while (cnt < tms)
        {
            if (dir == 1)
            {
                y += 1;
            }
            else if (dir == 2)
            {
                x += 1;
            }
            else if (dir == 3)
            {
                y -= 1;
            }
            else //dir==4
            {
                x -= 1;
            }
            moveCursor(x, y);
            printf("*");
            moveCursor(xx, yy);
            printf(" ");
            Sleep(200);
            cnt++;
            xx = x;
            yy = y;
        }
        cnt = 0;
        if (dir == 4)
        {
            dir = 1;
        }
        else
        {
            dir++;
        }
        addcnt++;
        if (addcnt == 2)
        {
            tms += 2;
            addcnt = 0;
        }
        rpt++;
    }
    moveCursor(8, 3);
    printf(" ");
    moveCursor(x - 7, y);
    printBomb(1);
    moveCursor(10, 20);
    return 0;
}