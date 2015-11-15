
#include "Figure.cpp"

class Vehicle
{
public:
	virtual void Draw()=0;
	virtual void Hide()=0;
	virtual void Move(int x ,int y)=0;
	FigureLink contents;
};

class Car:public Vehicle
{
public:
	Car(){		
	};
	~Car(){};
	Car(int d){
	  F_Circle cir1(55+1.75*d,600-d/2-2,d/2);
	  F_Circle cir2(55+6.25*d,600-d/2-2,d/2);
	  F_Rectangle rect1(55,600-2*d-2,8*d,d);	  
	  F_Triagnle tri1(55+1.25*d,600-2*d-2,55+2.25*d,600-2*d-2,55+2.25*d,600-3*d-2);
	  F_Rectangle rect2(55+2.25*d,600-3*d-2,3.5*d,d);
	  F_Triagnle tri2(55+5.75*d,600-2*d-2,55+6.75*d,600-2*d-2,55+5.75*d,600-3*d-2);

	  contents.fInsert(&cir1);
	  contents.fInsert(&cir2);
	  contents.fInsert(&rect1);	  
	  contents.fInsert(&tri1);
	  contents.fInsert(&rect2);
	  contents.fInsert(&tri2);
	  
	}
	void Draw(){	
	  contents.Init();
	};
	void Move(int dx,int dy){
		contents.Change(dx,dy);
	};
	void Hide(){contents.Hide();}
};

class Truck:public Vehicle
{
public:
	Truck(){}
	~Truck(){}
	Truck(int d){
		F_Rectangle rect1(55,600-5*d-2,9*d,4*d);
		F_Rectangle rect2(55+9*d+2,600-4*d-2,2*d,3*d);

		F_Circle cir1(55+d,600-d/2-1,d/2);
		F_Circle cir2(55+2.25*d,600-d/2-1,d/2);
		F_Circle cir3(55+6.75*d,600-d/2-1,d/2);
		F_Circle cir4(55+8*d,600-d/2-1,d/2);
		F_Circle cir5(55+10*d+2,600-d/2-1,d/2);

		contents.fInsert(&rect1);		
		contents.fInsert(&cir1);
		contents.fInsert(&cir2);
		contents.fInsert(&cir3);
		contents.fInsert(&cir4);
		contents.fInsert(&rect2);
		contents.fInsert(&cir5);//change the order in case the line is discovered by black brush
	}
	void Draw(){contents.Init();}
	void Move(int dx,int dy){contents.Change(dx,dy);}
	void Hide(){contents.Hide();}
};