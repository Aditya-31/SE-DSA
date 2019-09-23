#include<iostream>
#include<string.h>
using namespace std;
#define MAX 30

class String
{
	char task[MAX];
	friend class Queue;
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
		int isFull(){return rear==size-1;}
		int isEmpty(){return front==rear;}
		void insertAtRear(char *a)
		{
			if(!isFull())
				strcpy(arr[++rear].task,a);
			else
				cout<<"\nTask can't be inserted (QUEUE is FULL) "<<endl;
		}
		void deleteAtFront()
		{
			if(!isEmpty())
				cout<<arr[front--].task<<endl;
			else
				cout<<"\nDeletion isn't possible (QUEUE is EMPTY)"<<endl;
		}
		
		int frontValue()
		{return front;}
		
		void getFront();
		
		void display(int temp)
		{
			if(!isEmpty())
			{
				while(temp!=rear+1)
				{
					cout<<arr[temp++].task;
					display(temp);
				}
				return;
			}
			else
				cout<<"Cant display an Empty Queue!!!"<<endl;			
		}
};

void Queue::getFront()
{
	if(!isEmpty())
		cout<<arr[front].task<<endl;
	else
		cout<<"\nNo Front Available (QUEUE is EMPTY)"<<endl;
}
int main()
{
	cout<<"Enter the size of required Queue:\t";
	int n;
	cin>>n;
	Queue Q1(n);
	char ch;
	char x[MAX];
	do
	{   
		 cout<<"\n 1. Insert task\n 2.Delete Task\n 3.Display To-Do List\n 4.Exit\n Enter your choice:";
		 cin>>ch;
		switch(ch)
		{  case '1':
				 if (!Q1.isFull())
				  { 
				  	cout<<"\n Enter Task:";
					cin.getline(x,MAX,'+');
					Q1.insertAtRear(x);
				  }
			     else
					 cout<< "Queue is overflow";
			     break;
		  
		  case '2':
		  		if(!Q1.isEmpty())
				{   cout<<"\n Deleted Task:";
				   Q1.deleteAtFront();
				}
				else
					cout<<"\n Queue is underflow";
			    break;
		 
		 case '3': 
		 		if (!Q1.isEmpty())
			   {  cout<<"\n Queue contains:";
				  Q1.display(Q1.frontValue());
			   }
			   else
				    cout<<"\n Queue is empty";
			  break;
		 
		 case '4':
		 		cout<<"\n Exit";
		 		break;
		}
	}while(ch!='4');		
	return 0;
}
