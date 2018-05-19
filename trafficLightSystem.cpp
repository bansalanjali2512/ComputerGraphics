/*
    Q1.	Write a C/C++ graphics program to implement traffic light system.
    On Output screen there has to be one car and one traffic light signal.
    Initially the colour of traffic light is green and car should be in moving position,
    but when you type ‘R/r’ or ‘Y/y’ (red or yellow) on keyboard colour of traffic light
    has to be change into red or yellow respectively and car should stop
    until you press ‘G/g’ for green light again.
    Software Used: CodeBlocks EP
*/

#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void drawCar(int i)
{
    /*
        Objective : to draw car
        Input Parameters:
            i : for x-coordinate movement
        Return Value : none
    */

    // Road
    line(0,390,639,390);

    // Car Body
    line(50+i,370,90+i,370);
    arc(110+i,370,0,180,20);
    line(130+i,370,220+i,370);
    arc(240+i,370,0,180,20);
    line(260+i,370,300+i,370);
    line(300+i,370,300+i,350);
    line(300+i,350,240+i,330);
    line(240+i,330,200+i,300);
    line(200+i,300,110+i,300);
    line(110+i,300,80+i,330);
    line(80+i,330,50+i,340);
    line(50+i,340,50+i,370);

    // Car Windows
    line(165+i,305,165+i,330);
    line(165+i,330,230+i,330);
    line(230+i,330,195+i,305);
    line(195+i,305,165+i,305);

    line(160+i,305,160+i,330);
    line(160+i,330,95+i,330);
    line(95+i,330,120+i,305);
    line(120+i,305,160+i,305);

    // Wheels
    circle(110+i,370,17);
    circle(240+i,370,17);
}


int main()
{
    //Objective: To implement traffic light system

    int gd=DETECT, gm;
    initgraph(&gd, &gm, "");

    char choice='g';    // initializing traffic light choice to green
    int i=0;
    while(1)
    {
        if( i == 600 )
            i = 0;
        cleardevice();
        setcolor(7);

        // Drawing Traffic Light Body
        rectangle(570, 70, 630, 230);
        rectangle(594,230, 603, 390);
        circle(600, 100, 22);                                       // Red Light
        circle(600, 150, 22);                                       // Yellow Light
        circle(600, 200, 22);                                       // Green Light

        if(GetAsyncKeyState('r') || GetAsyncKeyState('R')) {        //IF R OR r is pressed
            setfillstyle(SOLID_FILL,RED);                           //fill red color in traffic light
            floodfill(590, 100, 7);
            drawCar(i);
            getch();                                                //car stops and waits until user presses a key
        }
        else if(GetAsyncKeyState('y') || GetAsyncKeyState('Y')) {   //IF Y OR y is pressed
            setfillstyle(SOLID_FILL,YELLOW);                        //fill yellow color in traffic light
            floodfill(600, 150, 7);
            drawCar(i);
            getch();                                                //car stops and waits until user presses a key
        }

        // otherwise keep the car moving
        setfillstyle(SOLID_FILL,GREEN);                             //colors green light
        floodfill(590, 200, 7);
        drawCar(i);
        ++i;
        delay(10);
    }
    getch();
    closegraph();
    return 0;
}
