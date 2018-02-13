/*
  PROGRAM TO IMPLEMENT DDA ALGORITHM
*/

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void dda(int x0, int y0, int x1, int y1) {
  int dx = x1-x0;
  int dy = y1-y0;
  double m=dy/dx;
  double y=y0;
  int x;

  for(x=x0;x<=x1;x++)
  {
    putpixel(x,y,RED);
    y+=m;
  }
}

int main() {

  int graphdriver = DETECT;
  int graphmode;
  initgraph(&graphdriver, &graphmode, "C:\\TURBOC3\\BGI");

  int x0,y0,x1,y1;
  cout<<"Enter the first coordinate:";
  cin>>x0>>y0;
  cout<<"Enter the second coordinate:";
  cin>>x1>>y1;
  dda(x0,y0,x1,y1);

  getch();
  closegraph();
  restorecrtmode();
  return 0;
}
