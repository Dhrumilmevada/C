#include<graphics.h>
//#include<conio.h>
//#include<dos.h>
     
int main()
{
   int gd = DETECT, gm;
     
   initgraph(&gd, &gm, "C:\\TC\\BGI");
	

	setlinestyle(SOLID_LINE,0,2);
	line(200,200,250,200);
		setcolor(RED);
   circle(100,100,70);   
	floodfill(100,100,WHITE);  
   getch();
   closegraph();
   return 0;
}


