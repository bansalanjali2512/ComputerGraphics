/*
    Q3. Write a C/C++ graphics program to draws a smiling face which appears at random position on screen.
    Software Used: CodeBlocks EP
*/


#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

using namespace std;

int main() {

    // Objective : To display Smiley at random position

    int gd = DETECT, gm;
    initgraph(&gd,&gm,"");

    int randomPositionX = 0;    //initializing random position of x
    int randomPositionY = 0;    //initializing random position of y
    int min = 40;
    int maxX = (getmaxx()-40);
    int maxY = (getmaxy()-40);
    int rangeX = maxX - min + 1;
    int rangeY = maxY - min + 1;

    setcolor(BLUE);
    while(1) {
        randomPositionX = rand() % rangeX + min;    //setting random position of x coordinate in range
        randomPositionY = rand() % rangeY + min;    //setting random position of y coordinate in range

        // filling yellow color in smiley
        setfillstyle(SOLID_FILL,YELLOW);
        fillellipse(randomPositionX,randomPositionY,40,40);

        // drawing eyes
        setfillstyle(SOLID_FILL,0);
        fillellipse((randomPositionX-12),(randomPositionY-15),4,7);     //left eye
        fillellipse((randomPositionX+12),(randomPositionY-15),4,7);     //right eye

        // drawing smile
        arc(randomPositionX,randomPositionY,225,315,20);

        delay(500);
        cleardevice();
    }

    getch();
    closegraph();
    return 0;
}
