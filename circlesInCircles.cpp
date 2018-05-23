/*
    Q4.	Write a C/C++ graphics program to draw circles in circles in two different colors.
    Software Used: CodeBlocks EP
*/

#include<graphics.h>
#include<conio.h>

int main()
{
   //Objective: to draw circles in circles in two different colours

   int gd = DETECT, gm, x, y, color, angle = 0;
   struct arccoordstype a;       //object a has arc coordinates

   initgraph(&gd, &gm, "");
   delay(200);

   while(angle<=360)            //until arcs cover circular path
   {
        /*
            Approach: drawing red circles and green circles
                      along the two arcs (smaller and bigger) respectively.
        */

        //drawing smaller arc wih radius 100
        setcolor(BLACK);
        arc(getmaxx()/2,getmaxy()/2,angle,angle+2,100);

        //drawing red circle
        setcolor(RED);
        // getting coordinates of arc (along which red circle is drawn) in a
        getarccoords(&a);
        // a circle of radius 25
        circle(a.xstart,a.ystart,25);

        //drawing bigger arc wih radius 150
        setcolor(BLACK);
        arc(getmaxx()/2,getmaxy()/2,angle,angle+2,150);
        // getting coordinates of arc (along which green circle is drawn) in a
        getarccoords(&a);

        //drawing green circle
        setcolor(GREEN);
        circle(a.xstart,a.ystart,25);

        angle = angle+5;
        delay(50);
   }

   getch();
   closegraph();
   return 0;
}
