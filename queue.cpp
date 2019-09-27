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
		int isFull(){return ((front)&&(rear==size-1)&&(front==(rear+1)%size));}
		int isEmpty(){return front==rear;}
		void insertAtRear(char a[])
		{
			if(!isFull())
				strcpy(arr[++rear].task,a);
				//cout<<arr[rear];
			else
				cout<<"\nTask can't be inserted (QUEUE is FULL) "<<endl;
		}
		void deleteAtFront()
		{
			if(!isEmpty())
				cout<<arr[++front].task<<endl;
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
					//display(temp);
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
		 		cout<<"\n Exit"<<endl;
		 		break;
		}
	}while(ch!='4');		
	return 0;
}
/*
OUTPUT:
unix@unix-dx2480-MT:~$ cd SEA19
unix@unix-dx2480-MT:~/SEA19$ g++ queue.cpp
unix@unix-dx2480-MT:~/SEA19$ ./a.out
Enter the size of required Queue:	5

 1. Insert task
 2.Delete Task
 3.Display To-Do List
 4.Exit
 Enter your choice:1

 Enter Task:Task1+

 1. Insert task
 2.Delete Task
 3.Display To-Do List
 4.Exit
 Enter your choice:1

 Enter Task:Task2+

 1. Insert task
 2.Delete Task
 3.Display To-Do List
 4.Exit
 Enter your choice:1

 Enter Task:Task3+

 1. Insert task
 2.Delete Task
 3.Display To-Do List
 4.Exit
 Enter your choice:3

 Queue contains:
Task1
Task2
Task3
 1. Insert task
 2.Delete Task
 3.Display To-Do List
 4.Exit
 Enter your choice:2

 Deleted Task:
Task1

 1. Insert task
 2.Delete Task
 3.Display To-Do List
 4.Exit
 Enter your choice:2

 Deleted Task:
Task2

 1. Insert task
 2.Delete Task
 3.Display To-Do List
 4.Exit
 Enter your choice:2

 Deleted Task:
Task3

 1. Insert task
 2.Delete Task
 3.Display To-Do List
 4.Exit
 Enter your choice:2

 Queue is underflow
 1. Insert task
 2.Delete Task
 3.Display To-Do List
 4.Exit
 Enter your choice:4

 Exit
 unix@unix-dx2480-MT:~/SEA19$ 
*/
