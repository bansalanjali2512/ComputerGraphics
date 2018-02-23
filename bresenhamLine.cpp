/*
    PROGRAM TO IMPLEMENT BRESENHAM LINE DRAWING ALGORITHM
    WRITTEN BY: ANJALI BANSAL
*/

#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>


void bresenhamLine(int x1, int y1, int x2, int y2)
{
	int x,y;
	int dx,dy;
	int p,xend;

	dx=abs(x1-x2);
	dy=abs(y1-y2);
	p=2*(dy-dx);

	if(x1>x2) {
		x=x2;
		y=y2;
		xend=x1;
	}
	else {
		x=x1;
		y=y1;
		xend=x2;
	}

    putpixel(x,y,5);
    while(x<xend) {
        x++;
        if(p<0) {
            p=p+2*dy;
        }
        else {
            y++;
            p=p+2*(dy-dx);
        }
        putpixel(x,y,1);
    }
}


int main()
{
    clrscr();
    int graphdriver = DETECT;
    int graphmode;
    int x0,y0,x1,y1;

    cout<<"\n *** Bresenham Line Algorithm *** ";
    cout<<"\n\n Enter the first point coordinates(x0,y0): ";
    cin>>x0>>y0;
    cout<<"\n Enter the second point coordinates(x1,y1): ";
    cin>>x1>>y1;

    initgraph(&graphdriver, &graphmode, "C:\\TURBOC3\\BGI");
    bresenhamLine(x0,y0,x1,y1);

    getch();
    closegraph();
    restorecrtmode();
    return 0;
}
