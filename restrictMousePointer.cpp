/*
    Q5.	Write a C/C++ graphics program that restricts mouse pointer in a circle i.e.
    you can't move mouse out of a circle. When you try to bring mouse pointer outside the circle,
    mouse pointer is moved to its previous location which is inside the circle.
    Software Used: CodeBlocks EP
*/

#include<graphics.h>
#include<conio.h>
#include<math.h>

int main()
{
    //Objective : restrict mouse pointer in a circle

    int gd = DETECT, gm, z, tempx, tempy;
    initgraph(&gd, &gm, "");

    circle(getmaxx()/2,getmaxy()/2,100);   // draws a circle with centre as centre of console, of radius 100
    POINT p;

    tempx = getmaxx()/2;    //initializing tempx
    tempy = getmaxy()/2;    //initializing tempy

    while(!kbhit())     //until a keyboard key is pressed
    {
        GetCursorPos(&p);    //gets current position of cursor
        z = pow((p.x - getmaxx()/2 - 4.5),2)+ pow((p.y - getmaxy()/2 - 25.2),2);    // to check the condition if current position of cursor lies outside the circle

        if(z > 10000)      // where 10000 is square of radius 100
        {
            SetCursorPos(tempx,tempy);      // sets cursor position to previous cursor position if cursor goes outside the circle
        }

    tempx = p.x;    // stores current x coordinate of position of cursor
    tempy = p.y;    // stores current y coordinate of position of cursor

    }

   getch();
   closegraph();
   return 0;
}
