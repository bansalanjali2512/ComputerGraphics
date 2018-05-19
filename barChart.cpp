/*
    Q2. To draw a bar chart
    Software Used: CodeBlocks EP
*/
#include<iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    outtextxy(280,0,"BAR GRAPH");
    setlinestyle(SOLID_LINE,0,2);

    // To Draw Co-ordinate Axis
    line(90,410,90,50);
    line(90,410,590,410);
    line(85,60,90,50);
    line(95,60,90,50);
    line(585,405,590,410);
    line(585,415,590,410);

    outtextxy(65,60,"Y");
    outtextxy(570,420,"X");
    outtextxy(70,415,"O");

    /* Draw bars on screen */
    setfillstyle(XHATCH_FILL,3);
    bar(150,180,200,410);
    setfillstyle(LTBKSLASH_FILL,5);
    bar(225,80,275,410);
    setfillstyle(CLOSE_DOT_FILL,2);
    bar(300,140,350,410);
    setfillstyle(LTSLASH_FILL,6);
    bar(375,170,425,410);
    setfillstyle(WIDE_DOT_FILL,4);
    bar(450,155,500,410);

   getch();
   closegraph();
   return 0;
}
