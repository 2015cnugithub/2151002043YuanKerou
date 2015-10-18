#include<iostream>
#include<string>
using namespace std;
class Worker
{
public:
	Worker();
	~Worker();
	Worker(string,int,char,double);
	virtual void Compute_pay(double hours)=0;//count the wage
	friend ostream& operator<<(ostream& out,Worker &worker);

	void Name();

	string get_name(){return name;}
	int get_age(){return age;}
	char get_sex(){return sex;}
	double get_pay_per_hour(){return pay_per_hour;}
	//Worker &operator=(const Worker &w);
private:
	string name;
	int age;
	char sex;
	double pay_per_hour;
};
Worker::Worker()
{
}
Worker::Worker(string n,int a,char s,double p)
{
	name = n;
	age = a;
	sex = s;
	pay_per_hour=p;
}
Worker::~Worker()
{
}
ostream& operator<<(ostream &out,Worker &worker)
{
	out<<"name:"<<worker.get_name()<<"  age :"<<worker.get_age()<<"  sex :"<<worker.get_sex()<<
		 "  pay/hour:"<<worker.get_pay_per_hour()<<endl;
	return out;
}

void Worker::Name()//display
{
	cout<<this->name;
}
/*Worker &Worker::operator=(const Worker &w){
	if(this==&w) return *this;
	delete name;
	name= new char[strlen(w.name)+1];
	strcpy(name,w.name);
	return *this;

}*/
class HourlyWorker:public Worker
{
public:
	HourlyWorker();
	HourlyWorker(string n,int a,char s,double p);
	~HourlyWorker();
	void Compute_pay(double hours);
};
HourlyWorker::HourlyWorker():Worker()
{
}
HourlyWorker::HourlyWorker(string n,int a,char s,double p):Worker(n,a,s,p)
{
}
HourlyWorker::~HourlyWorker()
{
}
void HourlyWorker::Compute_pay(double hours)
{	
	double wages;
	if(hours>40){
		wages=get_pay_per_hour()*40+1.5*get_pay_per_hour()*(hours-40);
	}
	else{
		wages=get_pay_per_hour()*hours;
	}
	cout<<"Total wages/week:"<<wages<<endl;
}



class SalariedWorker:public Worker
{
public:
	SalariedWorker();
	SalariedWorker(string n,int a,char s,double p);
	~SalariedWorker();
	void Compute_pay(double hours);
};
SalariedWorker::SalariedWorker():Worker()
{
}
SalariedWorker::SalariedWorker(string n,int a,char s,double p):Worker( n,a,s,p)
{
}
SalariedWorker::~SalariedWorker()
{
}
void SalariedWorker::Compute_pay(double hours)
{
	double wages;
	if(hours>=35){
		wages=get_pay_per_hour()*40;
	}
	else{
		wages=get_pay_per_hour()*hours+0.5*get_pay_per_hour()*(35-hours);
	}
	cout<<"Total wages/week:"<<wages<<endl;
}

int main()
{
	Worker * workers[5];

	int i;	
	for(i=0;i<5;i++){// the array is worker[0]-worker[4]
		string name;
		int age;
		char sex=(char)malloc(sizeof(char));
		double pay_per_hour;

	   cout<<"Please input "<<i+1<<"th worker"<<endl;
	        cout<<"name                           :";
	   cin>>name;
	        cout<<"age                            :";
	   cin>>age;
	        cout<<"sex(f for female or m for male):";
	   cin>>sex;
	   if(i<3)
			cout<<"pay/hour(10, 20 or 40/hour)    :";
	   else
		    cout<<"pay/hour  (30 or 50/hour)      :";
	   cin>>pay_per_hour;
	   if(i<3){		   
		   workers[i]=new HourlyWorker(name,age,sex,pay_per_hour);
		   }
	   else
	   {
		   workers[i]=new SalariedWorker (name,age,sex,pay_per_hour);
	   }
		cout<<endl; 
	}
	workers;
	cout<<"Now you have create 5 workers, the first three are hourlyworkers, the others are salariedworker"<<endl;
	for(i=0;i<5;i++){	
	    cout<<"the "<<i+1<<"th worker's name:";
		workers[i]->Name(); //cout<<*workers[i];
		cout<<endl;
	}
	cout<<endl;

	cout<<"Now you can choose one worker to see his or her wages/week"<<endl;
	cout<<"IF YOU WANT TO EXIT, PLEASE INPUT 0"<<endl;
	int number;
	double hours;
	cout<<"Please input a number (int) to get the worker's wages :";
	cin>>number;
	while(number!=0){
		if(number<6&&number>0)		
		{
			cout<<"Please input the total hours the worker has worked for:";
			cin>>hours;
			workers[number-1]->Compute_pay(hours);	
			cout<<endl;			
		}
		else
		{cout<<"Please input a number among 1 and 5"<<endl;}

		cout<<"Please input a number (int) to get the worker's wages :";
		cin>>number;
	}

	cout<<endl;
	cout<<"Now testing the operateor <<"<<endl;
	for(i=0;i<5;i++){	
	    cout<<*workers[i];
		cout<<endl;
	}
	system("pause");
	
	return 0;
}

