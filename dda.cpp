/*
    PROGRAM TO IMPLEMENT DDA LINE ALGORITHM
    WRITTEN BY: ANJALI BANSAL
*/

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void ddaLine(int x0, int y0, int x1, int y1) {
    int dx = x1-x0;
    int dy = y1-y0;
    double m=dy/dx;
    double y=y0;
    int x;

    for(x=x0;x<=x1;x++) {
        putpixel(x,y,RED);
        y+=m;
    }
}


int main() {
    clrscr();
    int graphdriver = DETECT;
    int graphmode;
    int x0,y0,x1,y1;

    cout<<"\n *** DDA Line Algorithm *** ";
    cout<<"\n\n Enter the first point coordinates(x0,y0): ";
    cin>>x0>>y0;
    cout<<"\n Enter the second point coordinates(x1,y1): ";
    cin>>x1>>y1;

    initgraph(&graphdriver, &graphmode, "C:\\TURBOC3\\BGI");
    ddaLine(x0,y0,x1,y1);

    getch();
    closegraph();
    restorecrtmode();
    return 0;
}
