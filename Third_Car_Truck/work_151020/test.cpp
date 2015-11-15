#include<graphics.h>
#include<conio.h>
#include<stdio.h>

#include "Vehicle.cpp"

using namespace std;
void main()
{
	initgraph(1000,800);//init the screen 
	outtext("1 Car  2 Truck  3 Exit");//original outtext(LPCTSTR str)

	//the structure
	line(50,50,50,650);
	line(50,50,950,50);
	line(950,50,950,650);
	line(50,650,950,650);

	//the tips
	outtextxy(55,55,"Press <S> key to strat moving");
	outtextxy(55,75,"Press <P> key to pause/continue moving ");
	outtextxy(55,95,"Press <E> key to end moving");
	outtextxy(55,115,"Press <+> key to speed up");
	outtextxy(55,135,"Press <-> key to speed down");

	//the car or truck
	line(50,602,950,602);
 
	Vehicle * v1=0,* v2=0;
	Car c(16);
	v1=&c;
	//v1->Draw();	
	Truck t(16);
	v2=&t;

	outtextxy(400,400,"press 1 or 2 or 3");
	int choice=getch();//press any key the close the screen OR the screen will close
	while(choice==51||choice==50||choice==49)//choice choose 3 exit
	{
		if(choice==49) //choice choose 1 car 
		{
			v2->Hide();
			v1->Draw();	
			//S 83;   s 115;   + 43;   - 45;   E 69;   e 101;   P 80;   p 112
			outtextxy(400,400,"                                            ");
			outtextxy(400,400,"press S or 2");
			choice=getch();
			if(choice==83||choice==115)
			{
				outtextxy(400,400,"                                            ");
				outtextxy(400,400,"press P or E or + or -");
				v1->Move(5,10);	
				outtextxy(400,400,"                                            ");
				outtextxy(400,400,"press 2 or 3");
				choice=getch();
				while(choice!=51&&choice!=50) 
				{
					outtextxy(400,400,"                                            ");
					outtextxy(400,400,"please press 2 or 3");
					choice=getch();
				}
			}
		}
		else 
			if(choice==50)// choice 2 truck
			{
				v1->Hide();
				v2->Draw();	
				outtextxy(400,400,"                                            ");
				outtextxy(400,400,"press S or 1");
				choice=getch();
				if(choice==83||choice==115)
				{
					outtextxy(400,400,"                                            ");
					outtextxy(400,400,"press P or E or + or -");
					v2->Move(5,10);	
					outtextxy(400,400,"                                            ");
					outtextxy(400,400,"press 1 or 3");
					choice=getch();
					while(choice!=51&&choice!=49) 
					{
						outtextxy(400,400,"                                            ");
						outtextxy(400,400,"please press 1 or 3");
						choice=getch();
					}
				}				
			}
			else
				break;
	}
	closegraph();
}
