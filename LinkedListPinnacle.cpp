/*Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
Second, third and final year of department can be granted membership on request. Similarly
one may cancel the membership of club. First node is reserved for president of club and last
node is reserved for secretary of club. Write C++ program to maintain club member‘s
information using singly linked list. Store student PRN and Name. Write functions to
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
//NOT DONE YETd) Display list in reverse order using recursion
e) Two linked lists exists for two divisions. Concatenate two lists.*/
/*NAME: ADITYA GADE 	Class: SE-A(COMP)	Date of creation:22-08-2018		Last Updated: 28-08-19*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class node
{
		int prn;
		char name[30];
		node* next;
	public:
		node()
		{
			prn=0;
			strcpy(name,"N.A");
		}
		friend class linked_list;
};

class linked_list
{
	node* head,*tail;
	public:
		linked_list()
		{
			head=tail=NULL;
		}
		void create()
		{
			int x;
			char n[30];
			node* current;
			node* previous;
			char choice;

			do
			{
				cout<<"Enter the PRN:\t";
				cin>>x;
				cout<<"Enter the Name:\t";
				cin.getline(n,30,'+');
				current=new node;
				
				current->prn=x;
				strcpy(current->name,n);
				current->next=NULL;

				if(head==NULL)
				{
					head=current;
					previous=current;
				}

				else
				{
					previous->next=current;
					previous=current;
				}

				tail=current;				
				cout<<"Add more?(y/n)"<<endl;
				cin>>choice;

			}while(choice=='Y'||choice=='y');
		}
		void display()
		{
			int count=0;
			node*temp=head;
			while(temp!=NULL)
			{
				if(temp==head)
				{
					cout<<"\nNAME:"<<temp->name<<"\nPRN:"<<temp->prn<<"\tMembership: President";
					count++;
				}
				else if(temp->next==NULL)
				{
					cout<<"\nNAME:"<<temp->name<<"\nPRN:"<<temp->prn<<"\tMembership: Secretary";
					count++;
				}
				else
				{	cout<<"\nNAME:"<<temp->name<<"\nPRN:"<<temp->prn<<"\tMembership: Member";
					count++;
				}
				temp=temp->next;
				cout<<"\n";
			}
			cout<<"\nThe Total No of Students in the PINNACLE CLUB is: "<<count;
		}
		void concatinateList(linked_list &q2)
		{
			node *temp;
			temp=q2.head;
			tail->next=temp;
			q2.head=NULL; //second list head label is set to  null
			tail=q2.tail;
		}

		void delete_head()
		{
			node*temp=head;
			head=temp->next;
			delete(temp);
			cout<<"\nAfter Deleting Head list";
			display();
		}
		void delete_tail()
		{
			node*temp=head;
			while(temp!=NULL)
			{	
				if(temp->next==tail)
				{
					delete(tail);
					temp->next=NULL;
					tail=temp;
				}
				temp=temp->next;
				
			}
			cout<<"\nAfter Deleting Tail list";
			display();
			
		}
		void insert_pre()
		{
			int choice,flag;
			cout<<"\nENTER: 1.TO CREATE A NEW PRESIDENT.\n\t2.CREATE ALREADY EXISTING MEMBER AS PRESIDENT\n";
			cin>>choice;
			node* temp=new node,*temp1;
			char nem[30];
			if(!(choice<0||choice>3))
			{
				switch(choice)
				{
					case 1:
						
						cout<<"\nEnter PRN:\t";
						cin>>temp->prn;
						cout<<"\nEnter Name:\t";
						cin.getline(nem,30,'+');
						strcpy(temp->name,nem);
						temp->next=head;
						head=temp;
						break;
					case 2:
						cout<<"\nEnter the name of member to be made as president:\t";
						cin.getline(nem,30,'+');
						temp1=head;
						while(temp1!=NULL)
						{
							if(!strcmp(temp1->name,nem))
							{
								strcpy(temp->name,temp1->name);
								temp->prn=temp1->prn;
								
								strcpy(temp1->name,head->name);
								temp1->prn=head->prn;
								
								strcpy(head->name,temp->name);
								head->prn=temp->prn;
								delete(temp);
								flag=1;
								cout<<"\n\tOPERATION SUCCESSFUL!!";

							}
							else
								temp1=temp1->next;
								
						}
						if(flag!=1)
						cout<<"OPERATION NOT SUCCESSFUL!";
						break;
				}
				
			}
			else
				cout<<"WRONG CHOICE ENTERED";
		}

		void insert_sec()
		{
			
			int choice,flag;
			cout<<"\nENTER: 1.TO CREATE A NEW Secretary.\n\t2.CREATE ALREADY EXISTING MEMBER AS Secretary.\n";
			cin>>choice;
			node* temp=new node,*temp1;
			char nem[30];
			if(!(choice<0||choice>3))
			{
				switch(choice)
				{
					case 1:
						
						cout<<"\nEnter PRN:\t";
						cin>>temp->prn;
						cout<<"\nEnter Name:\t";
						cin.getline(nem,30,'+');
						strcpy(temp->name,nem);
						tail->next=temp;
						tail=temp;
						break;
					case 2:
						cout<<"\nEnter the name of member to be made as SECRETARY:\t";
						cin.getline(nem,30,'+');
						temp1=head;
						while(temp1!=NULL)
						{
							if(!strcmp(temp1->name,nem))
							{
								strcpy(temp->name,temp1->name);
								temp->prn=temp1->prn;
								
								strcpy(temp1->name,tail->name);
								temp1->prn=tail->prn;
								
								strcpy(tail->name,temp->name);
								tail->prn=temp->prn;
								delete(temp);
								flag=1;
								cout<<"\n\tOPERATION SUCCESSFUL!!";

							}
							else
								temp1=temp1->next;
						}
						if(flag!=1)
						cout<<"OPERATION NOT SUCCESSFUL!";
						break;
				}
				
			}
			else
				cout<<"WRONG CHOICE ENTERED";
			
		}
		void delete_by_value()
		{
			cout<<"\nENTER: \n1.DELETE BY NAME. \t2.DELETE BY PRN.";
			int choice,p,flag;
			char nem[30];
			cin>> choice;
			node* temp=head,*temp1;
			if(!(choice<0||choice>3))
			{
				switch(choice)
				{
					case 1:
						cout<<"\nEnter the name of member to be deleted:";
						cin.getline(nem,30,'+');
						while(temp!=NULL)
						{
							temp1=temp->next;
							if(!strcmp(nem,temp1->name))
							{
								temp->next=temp1->next;
								delete(temp1);
								flag=1;	
								cout<<"\nOperation Successful\n";
								break;
							}
							else
								temp=temp->next;
						}
						if(flag!=1)
						cout<<"OPERATION NOT SUCCESSFUL!";
						break;
					case 2:
					
						cout<<"\nEnter the PRN of member to be deleted:";
						
						while(temp!=NULL)
						{
							temp1=temp->next;
							if(p==temp1->prn)
							{
								temp->next=temp1->next;
								delete(temp1);
								flag=1;	
								cout<<"\nOperation Successful\n";
								break;
							}
							else
								temp=temp->next;
						}
						if(flag!=1)
						cout<<"OPERATION NOT SUCCESSFUL!";
						break;
				}
				
			}
			else
				cout<<"WRONG CHOICE ENTERED";
				
		}

};
int main()
{
	
	linked_list l1,l2;
	cout<<"\nCREATE L1 :";
	l1.create();
	int choice;
	char yes;
	do
	{
		cout<<"Enter the Choice: "<<endl<<"1.Delete President"<<"\n2.Delete Secretary"<<"\n3.Insert President"<<"\n4.Insert Secretary"<<"\n5.Concatenate List"<<"\n6.Delete by value"<<endl;
		cin>>choice;
		switch(choice)
		{
		
			case 1:
				l1.delete_head();
				//l1.display();
				break;
			case 2:
				l1.delete_tail();
				l1.display();
				break;
			case 3:
				l1.insert_pre();
				cout<<"\nList after inserting president";
				l1.display();
				break;
			case 4:
				l1.insert_sec();
				cout<<"\nList after inserting secretary";
				l1.display();
				break;
			case 5:
				cout<<"\nCREATE 2nd List:";
				l2.create();
				cout<<"\nConcatinating the LISTS........";
				l1.concatinateList(l2);
				cout<<"\nAfter concatenation list";
				l1.display();
				break;
			case 6:
				cout<<"\n Performing Delete by Value:";
				l1.delete_by_value();
				l1.display();
				break;
			default:
				cout<<"\nENTER CORRECT OPTION.";
				break;
		}

		cout<<"\nDo you want to continue(Y/y):\t";
		cin>>yes;		
	}while(yes=='y'||yes=='Y');
	
	return 0;
}
/*
SAMPLE OUTPUT:
ubuntu@DESKTOP-4FQXGZ1:~$ cd //mnt/z/DSA
ubuntu@DESKTOP-4FQXGZ1://mnt/z/DSA$ g++ LinkedListPinnacle.cpp
ubuntu@DESKTOP-4FQXGZ1://mnt/z/DSA$ ./a.out

CREATE L1 :Enter the PRN:       123
Enter the Name: Student one+
Add more?(y/n)
y
Enter the PRN:  234
Enter the Name: Student 2
+
Add more?(y/n)
y
Enter the PRN:  456
Enter the Name: student 3+
Add more?(y/n)
n
Enter the Choice:
1.Delete President
2.Delete Secretary
3.Insert President
4.Insert Secretary
5.Concatenate List
6.Delete by value
1

After Deleting Head list
NAME:
Student 2

PRN:234 Membership: President

NAME:
student 3
PRN:456 Membership: Secretary

The Total No of Students in the PINNACLE CLUB is: 2
NAME:
Student 2

PRN:234 Membership: President

NAME:
student 3
PRN:456 Membership: Secretary

The Total No of Students in the PINNACLE CLUB is: 2
Do you want to continue(Y/y):   y
Enter the Choice:
1.Delete President
2.Delete Secretary
3.Insert President
4.Insert Secretary
5.Concatenate List
6.Delete by value
2

After Deleting Tail list
NAME:
Student 2

PRN:234 Membership: President

The Total No of Students in the PINNACLE CLUB is: 1
NAME:
Student 2

PRN:234 Membership: President

The Total No of Students in the PINNACLE CLUB is: 1
Do you want to continue(Y/y):   y
Enter the Choice:
1.Delete President
2.Delete Secretary
3.Insert President
4.Insert Secretary
5.Concatenate List
6.Delete by value
3

ENTER: 1.TO CREATE A NEW PRESIDENT.
        2.CREATE ALREADY EXISTING MEMBER AS PRESIDENT
1

Enter PRN:      123

Enter Name:     student1
+

List after inserting president
NAME:
student1

PRN:123 Membership: President

NAME:
Student 2

PRN:234 Membership: Secretary

The Total No of Students in the PINNACLE CLUB is: 2
Do you want to continue(Y/y):   y
Enter the Choice:
1.Delete President
2.Delete Secretary
3.Insert President
4.Insert Secretary
5.Concatenate List
6.Delete by value
3

ENTER: 1.TO CREATE A NEW PRESIDENT.
        2.CREATE ALREADY EXISTING MEMBER AS PRESIDENT
2

Enter the name of member to be made as president:       thanos+
OPERATION NOT SUCCESSFUL!
List after inserting president
NAME:
student1

PRN:123 Membership: President

NAME:
Student 2

PRN:234 Membership: Secretary

The Total No of Students in the PINNACLE CLUB is: 2
Do you want to continue(Y/y):   y
Enter the Choice:
1.Delete President
2.Delete Secretary
3.Insert President
4.Insert Secretary
5.Concatenate List
6.Delete by value
5

CREATE 2nd List:Enter the PRN:  987
Enter the Name: bstudent +
Add more?(y/n)
y
Enter the PRN:  345
Enter the Name: student of b+
Add more?(y/n)
n

Concatinating the LISTS........
After concatenation list
NAME:
student1

PRN:123 Membership: President

NAME:
Student 2

PRN:234 Membership: Member

NAME:
bstudent
PRN:987 Membership: Member

NAME:
student of b
PRN:345 Membership: Secretary

The Total No of Students in the PINNACLE CLUB is: 4
Do you want to continue(Y/y):   n
ubuntu@DESKTOP-4FQXGZ1://mnt/z/DSA$ ./a.out*/
