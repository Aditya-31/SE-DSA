#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define MAX 30

class String
{
		char name[MAX];
		char pizzas[MAX+MAX];
		int noOfPizza;
		int bill;
		int orderNo;
		friend class Queue;
	public:
		String()
		{
			strcpy(name,"");
			strcpy(pizzas,"");
			noOfPizza=bill=0;
		}
		void takeOrder()
		{
			cout<<"Your Good Name(end with a '+'):";
			cin.getline(name,MAX,'+');
			cout<<"No of Pizzas you wish to have: ";
			cin>>noOfPizza;
			bill=noOfPizza*100;
			cout<<"\nOrders(end with a '+'):";
			cin.getline(pizzas,MAX+MAX,'+');
			cout<<"\nYour Bill is Rs."<<bill<<endl;
			cout<<"Employee Use:\nOrderNo:";
			cin>>orderNo;
			cout<<"Please remember this order ID:"<<orderNo<<endl;
		}
		void order()
		{
			cout<<"\nName:"<<name<<endl;
			cout<<"Order No.:"<<orderNo<<endl;
			cout<<"Bill(in Rs.):"<<bill<<endl;
		}
};
class Queue
{
		String arr[MAX];
		int size;
		int front,rear;
	public:
		Queue(int n)
		{
			front=rear=-1;
			size=n;
		}
		int isFull(){return ((front)&&(rear==size-1)&&(front==(rear+1)%size));}
		int isEmpty(){return front==rear;}
		void insertAtRear(String temp)
		{
			if(!isFull())
			{
				arr[++rear]=temp;
				//cout<<arr[rear];
			}
			else
				cout<<"\nTask can't be inserted (QUEUE is FULL) "<<endl;
		}
		String deleteAtFront()
		{
			if(!isEmpty())
				return arr[++front];
			else
				cout<<"\nDeletion isn't possible (QUEUE is EMPTY)"<<endl;
		}
		
		int frontValue()
		{return front;}
		
		String getRear();
};

String Queue::getRear()
{
	if(!isEmpty())
		return arr[rear];
	else
		cout<<"\nNo Upcoming Order Available"<<endl;
}
int main()
{
	cout<<"Enter the size of required Queue:\t";
	int n;
	cin>>n;
	Queue Q1(n);
	char ch;
	String x,temp;
	do
	{   
		 cout<<"\n 1. Take Order\n 2.Complete Order\n 3.Display Upcoming Order\n 3.Exit\n Enter your choice:";
		 cin>>ch;
		switch(ch)
		{  case '1':
				 if (!Q1.isFull())
				  { 
				  	x.takeOrder();
					Q1.insertAtRear(x);
				  }
			     else
					 cout<< "Can't Take More Orders";
			     break;
		  
		  case '2':
		  		if(!Q1.isEmpty())
				{   
					cout<<"\n Completed Order:";
				   	temp=Q1.deleteAtFront();
				   	temp.order();
				   	cout<<"\n Thanks For Visiting"<<endl;
				}
				else
					cout<<"\n No Ongoing Order!";
			    break;
		 
		 case '3': 
		 		if (!Q1.isEmpty())
			   {  
			   		cout<<"\n Upcoming Orders:";
				  	temp=Q1.getRear();
				  	temp.order();
			   }
			   else
				    cout<<"\n No Ongoing Orders Available";
			  break;
		 
		 case '4':
		 		cout<<"\n Exit"<<endl;
		 		break;
		}
	}while(ch!='4');		
	return 0;
}
/*
OUTPUT:
unix@unix-dx2480-MT:~$ cd SEA19
unix@unix-dx2480-MT:~/SEA19$ g++ pizza.cpp
unix@unix-dx2480-MT:~/SEA19$ ./a.out
Enter the size of required Queue:	5

 1. Take Order
 2.Complete Order
 3.Display Upcoming Order
 3.Exit
 Enter your choice:1
Your Good Name(end with a '+'):Aditya Gade+
No of Pizzas you wish to have: 3

Orders(end with a '+'):pizza1 pizza2 pizza3+

Your Bill is Rs.300
Employee Use:
OrderNo:123
Please remember this order ID:123

 1. Take Order
 2.Complete Order
 3.Display Upcoming Order
 3.Exit
 Enter your choice:3

 Upcoming Orders:
Name:
Aditya Gade
Order No.:123
Bill(in Rs.):300

 1. Take Order
 2.Complete Order
 3.Display Upcoming Order
 3.Exit
 Enter your choice:2

 Completed Order:
Name:
Aditya Gade
Order No.:123
Bill(in Rs.):300

 Thanks For Visiting

 1. Take Order
 2.Complete Order
 3.Display Upcoming Order
 3.Exit
 Enter your choice:4

 Exit
unix@unix-dx2480-MT:~/SEA19$ 
*/
