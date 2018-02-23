/*
    PROGRAM TO IMPLEMENT CIRCLE DRAWING ALGORITHM
    WRITTEN BY: ANJALI BANSAL
*/

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>

//Functions Definitions

void circlepoints(int x,int y,int value) {
	int a=325;
	int b=225;

	putpixel(x+a,y+b,value);
	putpixel(y+a,x+b,value);
	putpixel(y+a,-x+b,value);
	putpixel(x+a,-y+b,value);
	putpixel(-x+a,-y+b,value);
	putpixel(-y+a,-x+b,value);
	putpixel(-y+a,x+b,value);
	putpixel(-x+a,y+b,value);
}

void midpointcircle(int radius,int value) {
	int x=0;
	int y=radius;
	int d=1-radius;

	circlepoints(x,y,value);

	while(y>x) {
		if(d<0) {
			d+=2*x+3;
		}
		else {
			d+=2*(x-y)+5;
			y--;
		}
		x++;
		circlepoints(x,y,value);
	}
}


int main() {
    clrscr();
    int graphdriver = DETECT;
    int graphmode;
	int radius,value;

	cout<<"\n *** Circle Algorithm *** ";
	cout<<"\n\n Enter radius of circle :";
	cin>>radius;
	cout<<"\n Enter a value(0-20) for pixel color:";
	cin>>value;

    initgraph(&graphdriver, &graphmode, "C:\\TURBOC3\\BGI");
	midpointcircle(radius,value);

	getch();
	closegraph();
    restorecrtmode();
    return 0;
}
