#include <iostream>
#include<conio.h>
#include<iomanip>
#include<ctime>
#include<fstream>
using namespace std;

class Admin
{
  string username, uname;
  string password, upwd;
  char pass1[10], ch;
  int i;
public:
   Admin()
		{
			username="Admin";
			password="Admin@123";
		}
		void retrieve()
		{
			cout<<"Enter Username";
			cin>>uname;
			cout<<"\nEnter Password";
		    ch = getch();
		    i = 0;
	    	while (ch!=13)
	     	{
		    	if(ch!=8 && ch!=13){
		    	putch('*');
pass1[i]=ch;
		    	i++;
			    ch=getch();
		    }
		   }
		pass1[i] = '\0';
    	}
		void check()
		{
			if(uname==username)
			{
				if(pass1==password)
				{
					cout<<"\nPassword matched";
					
				}
				else
				{
					cout<<"\nInvalid Password";
					return ;
				}
			}
			else
			{
				cout<<"\nInvalid Username";
				return ;
			}
		}
};


class Train
{
public:
  int train_no;
  char name[10];
  char from[10];
  char to[10];
  int c1fare;
 int c2fare;


    Train ()
  {
    c1fare = 1000;
    c2fare = 80;
  }

public:
  void entertrain ()
  {
    cout << "Enter the train no";
    cin >> train_no;
    cout << "Enter the train name ";
    cin >> name;
    cout << "Enter train from ";
    cin >> from;
    cout << "Enter train to ";
    cin >> to;

  }

friend void display();//friend function to display details

};


void display (Train t)
  {
    cout << endl << t.train_no << "  \t\t  " <<t.name << " \t\t  " <<t.from << "  \t\t  " <<t.to <<
      "  \t\t  " << t.c1fare << "\t\t  " <<t.c2fare << endl;
  }
void flwrite()
{
	ofstream fop;
	fop.open("Traindetails.txt",ios::app);
	Train T;
T.entertrain();
	fop.write((char *)&T,sizeof(T));
	fop.close();
}
void flshow()
{
	ifstream fip;
	Train T;
	fip.open("Traindetails.txt",ios::binary);
      cout <<
	"Train_no\tTrain name\tTrain from\tTrain to\tFirstclass\tSecondclass\t ";
	while(fip.read((char *)&T,sizeof(T))!=NULL)
		{
			display(T);
		}

	fip.close();
}


//function overloading
void print(int a){
 cout << "\n The amount is rs " << a;	
}
void print(float a){
 cout << "\n The amount is rs " << a;	
}

class booktkt
{
protected:
  string psgnr_name;
  int seat_type;
  int age;
  int cls;
  int amt;
  float at;
public:
 void enterdetails ()
  {

    cout << "Enter name of passenger " << " ::";
    cin >> psgnr_name;
    cout << "Enter Age ";
    cin >> age;
    cout << "Select seat preference\n1:: Lower \n2:: Middle \n3:: Upper \n";
    cin >> seat_type;

  }
  public:
  void details ()
  {
    cout << psgnr_name << "  \t" << seat_type << " \t" << age << " \n";
  }
//Function Overriding

    virtual void printt() {
        cout << "THANK YOU FOR USING INDIAN RAILWAYS " << endl;
    }

};
//class template
template <typename T>
class Check
{
	private:
		T avaiable;
	public:
	void setData(T x)
	{
		avaiable = x;
	}
	T getData()
	{
		return avaiable;
	}

};

//Inheritance
class Payment:public booktkt{
public:
	void printt() {
	time_t now = time (0);
    tm *ltm = localtime (&now);
    cout << "\nDate of cancellation  " << 1900 + ltm->tm_year << "-" << 1 +ltm->tm_mon << "-" << ltm->tm_mday << endl;
    }
    //Exception Handling
 /*   int c1;
void getdata()
{
	cout<<"Enter the value of c1 class : ";
	cin>>c1; 
}
void exception()
{
	
	try
	{
		if(c1 == 100)
		{
			throw c1;
		}
	}
	catch(int c1)
	{
		cout<<"Fault in Bill generation ";
	}
}*/
  void payment (int n,int cls)
  {
    int c1fare = 1000;
    float c2fare = 800.5443;
try{
   if(cls!=1 || cls!=2){
   	   throw "invalid";
   }
   else{
   
    if (cls == 1)
 {
	cout << "\nFirst class";
	amt = c1fare * n;
	    print(amt);
      }
    if (cls == 2)
      {
	cout << "\nSecond class";
	at = c2fare * n;
	print(at);
      }
}
}
catch(...){
	cout<<"Fault in Bill generation";
}

 

    time_t now = time (0);
    tm *ltm = localtime (&now);
    cout << "\nDate of payment  " << 1900 + ltm->tm_year << "-" << 1 +
      ltm->tm_mon << "-" << ltm->tm_mday << endl;

    cout << "\n--------------THANK YOU--------------------\n\n";
  }

};


//Operator Overloading
class cancel
{
	public:
		int n2;
		char ch;
	private:
		
		int fare1;
		int fare2;
public:
	cancel()
	{
		fare1=0;
		fare2=0;
	}
	cancel(int fine1,int fine2)
	{
		fare1=fine1;
		fare2=fine2;
	}
 
 int canceltkt ()
 {
 	
 cout << "Enter your PNR no.";
 cin >> n2;
 cout << "\nAre you sure you want to cancel ticket \n Y \n N\n";
 cin >> ch;
 if (ch == 'Y' || ch == 'y')
 {
cout << "\nThe Ticket is cancelled you will get refund in 24hrs\n ";
return 0;
 }
 else
 {
return 1;
 }
 }
 cancel operator -(cancel c)
 {
 	cancel temp;
 	temp.fare1=fare1-c.fare1;
 	temp.fare2=fare2-c.fare2;
 	//return temp;
 	cout<<"Deducted GST amount : "<<" Class 1: "<< temp.fare1 <<" Class 2: "<< temp.fare2 <<endl;
 }
 
};

int main(){
	
	int n,n1,a1,pas;//n is for choice n1 for no. of trains
	Admin a;
	Train T;
   booktkt b[50];
  booktkt b1;
  
  //class template
  	Check<int>obj1;
	obj1.setData(15);
	Check <double>obj2;
	obj2.setData(9.42322);
	
	
  cancel c;
  cancel c1(1000,800);
 	cancel c2(10,5);
 	cancel c3;
  Payment p;
  
  booktkt* bt=&p;

  int  cls;
	 cout <<
    "\n-------------WELCOME TO RAILWAY RESERVATION SYSTEM---------------";
  cout <<
    "\nMENU \n 1:: ADMIN MODE \n 2:: TRAIN DETAILS \n 3:: BOOK TICKET \n 4:: CANCEL TICKET \n 5:: QUIT\n\n";
  cout << "Enter choice: ";
  cin>>n;
  
  switch(n){
  
    case 1:
      a.retrieve();
      a.check ();
      cout << "\nEnter the no. of trains you want to enter :: ";
      cin >> n1;

	flwrite();
      break;
    case 2:

      flshow();
      cout<<"Train Booking taxes is: "<<obj1.getData()<<endl;
	
      break;
     
    case 3:
        cout << "Enter train number";       
        cin >> a1;
        cout << "Enter no.of passenger";
        cin >> pas;
        cout << "Enter class\n 1 Firstclass\n 2 Second class \n";
        cin >> cls;
      //  p.getdata();
       // p.exception();
  
      for (int i = 0; i < pas; i++)
	{
	  b[i].enterdetails ();
	}
      cout << "---------Booking Details----------\n";
      cout << "Name      type      age\n";
      for (int i = 0; i < pas; i++)
	{
	  	b[i].details();
	}
	 
      p.payment(pas,cls);
      
      
      break;
    case 4:
      c3=c1-c2;
      if (c3.canceltkt () == 1)
	{
	  main ();
	}

      bt->printt();
      break;
    case 5:
      return 0;
    default:
      cout << "invalid choice";
    }    
    
    main();     
}
