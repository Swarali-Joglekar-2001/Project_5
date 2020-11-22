#include<iostream>
using namespace std;
class Time
{
	private:
		int hours,minutes,seconds,total_sec;
	public:
		void accept_time();
		void conversion();
		void display();
		int no_of_digits(int );
		
};

void Time:: accept_time()
{
	cout<<"Enter time: Hours? ";
	cin>>hours;
	cout<<" Minutes? ";
	cin>>minutes;
	cout<<" Seconds? ";
	cin>>seconds;	
	display(); //call display function
}

void Time::display()
{
	cout<<"The time is=";
	
	//If user enters hours or minutes or seconds in 1 digit, then I want 0 before it while printing.
	// For example: 1 hour,2 minutes,8 seconds should look like 01:02:08
	//That's why I have written function no_of_digits to find number of digits
	
	
	if(no_of_digits(hours)==1)  
	    cout<<"0"<<hours<<":";
	else
		cout<<hours<<":";
		
	if(no_of_digits(minutes)==1)
		cout<<"0"<<minutes<<":";
	else
		cout<<minutes<<":";
		
	if(no_of_digits(seconds)==1)
		cout<<"0"<<seconds;
	else
		cout<<seconds;
	
	cout<<"\n";
	conversion();  //Call conversion function	
}

void Time::conversion()
{
	total_sec=(hours*3600)+(minutes*60)+seconds;  //1 hour=3600 seconds, 1 minute=60 seconds
	cout<<"Time in total seconds: "<<total_sec;	
}

int Time::no_of_digits(int x)
{
	int count=0;
	while(x!=0)
	{
		x=x/10;
		count++;  //count will contain no. of digits
		
	}
	
	if(count==1||x==0)  //If user enters 0 hours or minutes or seconds(i.e. x=0), then I want it as 00.
		return 1;
	else
		return 0;
	
}


int main()
{
  Time t;
  t.accept_time();
  return 0;	
}
