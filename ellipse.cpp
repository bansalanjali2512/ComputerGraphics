/*
    PROGRAM TO IMPLEMENT ELLIPSE DRAWING ALGORITHM
    WRITTEN BY: ANJALI BANSAL
*/

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>

//Functions Definitions

double sq(double x) {
	return x*x;
}

void ellipsepoint(int x,int y,int value) {
	double a=325;
	double b=225;
	putpixel(x+a,y+b,value);
	putpixel(x+a,-y+b,value);
	putpixel(-x+a,y+b,value);
	putpixel(-x+a,-y+b,value);
}

void midpointellipse(double a,double b,int value) {
	double d2;
	double x=0;
	double y=b;
	double d1=sq(b)-(sq(a)*b)+(0.25*sq(a));

	ellipsepoint(x,y,value);

	while((sq(a)*(y-5))>(sq(b)*(x+1))) {
		if(d1<0) {
			d1+=(sq(b)*(2*x+3));
		}
		else {
			d1+=(sq(b)*(2*x+3))+(sq(a)*(-2*y+2));
			y--;
		}
		x++;
		ellipsepoint(x,y,value);
	}

	d2=(sq(b)*(sq(x+0.5)))+(sq(a)*(sq(y-1)))-(sq(a)*sq(b));
	while(y>0) {
		if(d2<0) {
			d2+=(sq(b)*(2*x+2))+(sq(a)*(-2*y+3));
			x++;
		}
		else {
			d2+=(sq(a)*(-2*y+3));
		}
		y--;
		ellipsepoint(x,y,value);
	}
}


int main() {
    clrscr();
    int graphdriver = DETECT;
    int graphmode;
    double a,b,value;

    cout<<"\n *** Ellipse Algorithm *** ";
    cout<<"\n\n Enter length of semi major axis(a): ";
    cin>>a;
    cout<<"\n Enter length of semi minor axis(b): ";
    cin>>b;
    cout<<"\n Enter a value(0-20) for pixel color: ";
    cin>>value;

    initgraph(&graphdriver, &graphmode, "C:\\TURBOC3\\BGI");
	midpointellipse(a,b,value);

	getch();
	closegraph();
    restorecrtmode();
    return 0;
}
