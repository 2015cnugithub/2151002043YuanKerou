#include<graphics.h>
#include<conio.h>

enum Type  {CIRCLE,RECTANGLE,TRIANGLE};


class FigureLink;

enum TYPE {FCIRCLE,FRECTANGLE,FTRIANGLE};

class Figure
{
public:
	friend class FigureLink;
	Figure *ptr;
	Figure *next;

	TYPE t;
	int x,y;

	
public:
	Figure(){}
	~Figure() {}
	
	Figure(int cx,int cy){x=cx;y=cy;}

	virtual void operator()(int style,int width,int Incol,int pattern,int fcol)=0;
	virtual void operator()(int Incol,int pattern,int fcol)=0;
	virtual void operator()(int dx,int dy)=0;

	virtual void Insert()=0;

};

class F_Circle:public Figure
{
public:
	F_Circle(){};
	~F_Circle(){};
	F_Circle(int x,int y,int d):Figure(x,y){r=d; t=FCIRCLE;};
		
	//set the picture 
	void operator()(int style,int width,int Incol,int pattern,int fcol)
	{
		setlinestyle(style,width);	//line style and with
		setlinecolor(Incol);		//line color
		setfillstyle(pattern);		//fill pattern
		setfillcolor(fcol);			//fill color

		circle(x,y,r);				//draw circle 
	};

	//erase the picture
	void operator()(int Incol,int pattern,int fcol)
	{
		setlinecolor(Incol);
		setfillstyle(pattern);
		setfillcolor(fcol);

		circle(x,y,r);
	};

	//change the location
	void operator()(int dx,int dy)
	{
		x=x+dx;
	};

	int get_X(){return x;}
	int get_Y(){return y;} 
	int get_R(){return r;}
	TYPE get_T(){return t;}
	void Insert()
	{		
		ptr=new F_Circle(x,y,r);
		ptr->next=NULL;
	};

private:
	int r;	
};

class F_Rectangle:public Figure
{
public:
	F_Rectangle(){};
	~F_Rectangle(){};
	F_Rectangle(int x,int y,int len,int wid):Figure(x,y){l=len;w=wid;t=FRECTANGLE;}

	//set the picutre
	void operator()(int style,int width,int Incol,int pattern,int fcol)
	{
		setlinestyle(style,width);	//line style and with
		setlinecolor(Incol);		//line color
		setfillstyle(pattern);		//fill pattern
		setfillcolor(fcol);			//fill color		

		rectangle(x,y,x+l,y+w);
	};

	//erase the picture
	void operator()(int Incol,int pattern,int fcol)
	{
		setlinecolor(Incol);
		setfillstyle(pattern);
		setfillcolor(fcol);

		rectangle(x,y,x+l,y+w);
	};

	//change the location
	void operator()(int dx,int dy)
	{
		x=x+dx;
	};

	int get_X(){return x;}
	int get_Y(){return y;}
	int get_Length(){return l;}
	int get_Width(){return w;}
	TYPE get_T(){return t;}

	void Insert(){ptr=new F_Rectangle(x,y,l,w);ptr->next=NULL;}
private:
	int l;
	int w;
};

class F_Triagnle:public Figure
{
public:
	F_Triagnle(){};
	~F_Triagnle(){};
	F_Triagnle(int xx1,int yy1,int xx2,int yy2,int xx3,int yy3 ):Figure(xx1,yy1){x2=xx2;x3=xx3;y2=yy2;y3=yy3;t=FTRIANGLE;}

	//set the picutre
	void operator()(int style,int width,int Incol,int pattern,int fcol)
	{
		setlinestyle(style,width);	//line style and with
		setlinecolor(Incol);		//line color
		setfillstyle(pattern);		//fill pattern
		setfillcolor(fcol);			//fill color

		int pt[6]={x,y,x2,y2,x3,y3};
		polygon((POINT*)pt,3);
	};

	//erase the picture
	void operator()(int Incol,int pattern,int fcol)
	{
		setlinecolor(Incol);
		setfillstyle(pattern);
		setfillcolor(fcol);

		int pt[6]={x,y,x2,y2,x3,y3};
		polygon((POINT*)pt,3);
	};

	//change the location
	void operator()(int dx,int dy)
	{
		x=x+dx;// the vehicle runs according to x, it's a horizan line not verticle one
		x2=x2+dx;
		x3=x3+dx;
	};

	int get_X(){return x;}
	int get_Y(){return y;}
	int get_X2(){return x2;}
	int get_Y2(){return y2;}
	int get_X3(){return x3;}
	int get_Y3(){return y3;}
	TYPE get_T(){return t;}

	void Insert(){ptr = new F_Triagnle(x,y,x2,y2,x3,y3);ptr->next=NULL;}
private:
	int x2,y2;
	int x3,y3;
};

class FigureLink 
{
public:
	FigureLink (){head=0;}
	~FigureLink (){};
	void fInsert(Figure * Figure_Node){	
		Figure_Node->next=NULL;
		Figure_Node->Insert();
		if(head)
		{		
			Figure_Node->ptr->next=head;
			head=Figure_Node->ptr;
		}
		else	
			head=Figure_Node->ptr;
	}
	void Init()//first show the vehicle
	{
		Figure *p=head;
		while(p)
		{
			p->operator()(PS_SOLID,1,WHITE,SOLID_FILL,BLACK);			
			p=p->next;
		}
	}
	void Hide()
	{
		Figure *p=head;
		while(p)
		{
			p->operator()(PS_SOLID,1,BLACK,SOLID_FILL,BLACK);			
			p=p->next;
		}
	}
	void Change(int dx,int dy)//second change its position or called move
	{
		Figure *p=head;
		int speed=dx;
		
		while(p->x<870&&speed>=0){			
			while(p)
			{
				p->operator()(BLACK,SOLID_FILL,BLACK);
				p->operator()(speed,dy);
				p->operator()(PS_SOLID,1,WHITE,SOLID_FILL,BLACK);				
				p=p->next;
			}	
			Sleep(100);
			
			if(kbhit())				
			{
				int choice=getch();//check speed up or down or pause
				
				if(choice==61||choice==43)//+/=
					speed+=5;
				else
					if(choice==45)//-
						speed-=5;
				if(choice==80||choice==112)// P p
				{
					if(speed==0) speed=5;
					else		 speed=0;
				}
				if(choice==69||choice==101)//E e end
					speed=-1;//stop and never run				
			}
			p=head;
		}
	}
	
private:
	Figure *head;
};





