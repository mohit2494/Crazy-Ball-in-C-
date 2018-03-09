#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<alloc.h>
#include<stdio.h>
#include<process.h>

char *ball1,*ball2,*ball3,*ball4,*buff,*buff1;//TO STORE THE FRAMES OF THE BALL
int x=50,y=50,xdirn=1,ydirn=1;//initial coordinates and directions
int count=1,firstcount=1;

void init()
{
     int gd=DETECT,gm;
     initgraph(&gd,&gm,"C:\\TC\\BGI");

}

void tellsteps()
{

	textbackground(WHITE);
	textcolor(RED+BLINK);
	printf("\n\n\n\t\t------------------------------------------------");
	printf("\n\t\t|");
	textcolor(GREEN+BLINK);
	printf("PRESS ENTER TO CHANGE BALL COLOR AND S TO STOP");
	textcolor(RED+BLINK);
	printf("|");
	textcolor(GREEN+BLINK);
	printf("\n\t\t------------------------------------------------");

	gotoxy(300,450);
	printf("\n\n\n\n\n\t\t\tpress enter to continue");




}



initialise(int x)
{


	setcolor(BLUE);//SET COLOR TO BLUE
	setlinestyle(3,0,3);//SET LINE STYLE TO DOTTED
	rectangle(10,21,629,466);//DOTTED RECTANGLE 1


	setlinestyle(0,0,3);//SET LINE STYLE TO SOLID
	rectangle(13,24,626,463);//INNER SOLID RECTANGLE
	rectangle(0,0,639,478);//OUTER SOLID RECTANGLE 2

	line(16,0,16,479);//LEFT LINE TO RESTRICT GREEN COLOR
	line(626,0,626,479);//RIGHT LINE TO RESTRICT GREEN COLOR
	delay(x);

	setfillstyle(SOLID_FILL,LIGHTGREEN);//TO FILL BOUNDARY COLOR
	floodfill(4,4,BLUE);
	delay(x);
	floodfill(633,4,BLUE);
	delay(x);
	floodfill(20,475,BLUE);
	delay(x);
	setfillstyle(SOLID_FILL,YELLOW);
	delay(x);
	floodfill(30,4,BLUE);//ALL COLORS FILLED ON BOUNDARY

	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);//SETTEXTSTYLE
	delay(x);
	outtextxy(250,-4,"CRAZY BALL");//PRINT CRAZY BALL

 return 1;
}

void calculate(int linecolor,int fillcolor)
{

	//BALL FRAME 1
	setlinestyle(SOLID_LINE,0,3);
	setcolor(WHITE);
	circle(100,100,30);
	setfillstyle(SOLID_FILL,fillcolor);
	floodfill(100,100,WHITE);
	setlinestyle(DASHED_LINE,0,3);
	setcolor(linecolor);
	line(70,100,129,100);//MIDDLE LINE
	line(75,85,124,85);//UPPER LINE
	line(75,115,124,115);//LOWER LINE
	ball1=(char*)malloc(imagesize(65,65,135,135));
	getimage(65,65,135,135,ball1);



	//BALL FRAME 2
	setlinestyle(SOLID_LINE,0,3);
	setcolor(WHITE);
	circle(200,200,30);
	setfillstyle(SOLID_FILL,fillcolor);
	floodfill(200,200,WHITE);
	setlinestyle(DASHED_LINE,0,3);
	setcolor(linecolor);
	line(175,185,224,215);
	line(183,173,228,199);
	line(167,197,218,228);
	ball2=(char*)malloc(imagesize(165,165,235,235));
	getimage(165,165,235,235,ball2);



	//BALL FRAME 3
	setlinestyle(SOLID_LINE,0,3);
	setcolor(WHITE);
	circle(300,300,30);
	setfillstyle(SOLID_FILL,fillcolor);
	floodfill(300,300,WHITE);
	setlinestyle(DASHED_LINE,0,3);
	setcolor(linecolor);
	line(300,270,300,330);
	line(287,275,287,325);
	line(313,275,313,325);
	ball3=(char*)malloc(imagesize(265,265,335,335));
	getimage(265,265,335,335,ball3);



	//BALL FRAME 4
	setlinestyle(SOLID_LINE,0,3);
	setcolor(WHITE);
	circle(400,400,30);
	setfillstyle(SOLID_FILL,fillcolor);
	floodfill(400,400,WHITE);
	setlinestyle(DASHED_LINE,0,3);
	setcolor(linecolor);
	line(413,375,387,425);
	line(400,370,375,415);
	line(398,433,425,380);
	ball4=(char*)malloc(imagesize(365,365,435,435));
	getimage(365,365,435,435,ball4);


}

main()
{
	clrscr();
	tellsteps();
	getch();
	init();
	calculate(GREEN,RED);
	getch();
	cleardevice();
	initialise(1000);

	int colors[]={GREEN,CYAN,LIGHTGREEN,LIGHTCYAN};
	int colorsback[]={RED,LIGHTGRAY,BROWN};
	int index=0,index1=0;

	while(1)//infinite loop
	{
		if(kbhit())
		{
			char c=getch();
			if(c=='\r')
			{
				cleardevice();
				index++;
				if(index==4)
				{
				     index=0;
				     index++;
				     index1++;
				     if(index1==2)
				     {
					index1++;
				     }
				}
				free(ball1);
				free(ball2);
				free(ball3);
				free(ball4);
				free(buff);
				free(buff1);
				calculate(colors[index],colorsback[index1]);
				cleardevice();
				initialise(10);
				x=50;y=50;
				xdirn=1;ydirn=1;
				firstcount=1;
				getch();


			}
			else if(c=='s'||c=='S')
			{
				nosound();
				closegraph();
				restorecrtmode();
				printf("thank you :)");
				getch();
				exit(0);
			}
		}
		putimage(x,y,ball1,XOR_PUT);
		if(firstcount==1)
		{
			putimage(50,50,ball1,XOR_PUT);
			firstcount=0;
		}
		delay(3);
		x=x+(xdirn*(10));
		y=y+(ydirn*(6));
		putimage(x,y,ball1,XOR_PUT);

		//check if ball touches horizontal boundaries
		if(x>getmaxx()-50||x<50)
		{

			//sound(100);
			delay(10);
			nosound();
			xdirn*=-1;
		}
		//check if the ball touches the vertical surfaces
		if(y>getmaxy()-50||y<50)
		{
			//sound(100);
			delay(10);
			nosound();
			ydirn*=-1;
		}

	}
}