/*Write C++ program for storing binary number using doubly linked lists. Write functions-
a) to compute 1‘s and 2‘s complement b) add two binary numbers.*/
/*NAME: ADITYA GADE 	Class: SE-A(COMP)	Date of creation:22-08-2018		Last Updated: 27-08-19*/
#include<iostream>
#include<iomanip>
using namespace std;
class node
{
		int data;
		node *forward,*backward;
		static int noOfBits;
	public:
		node()
		{
		}
		friend class dlink_list;
};

class dlink_list
{
		node* head,*tail;
		int size;
	public:
		dlink_list()
		{
			size=0;
			head=tail=NULL;
		}
		void create()
		{
			node*current, *previous;
			char choice;
			int flag=0;
			cout<<"\nEnter the Binary no\n(MSB->->->LSB)\n(-1 to end the no.)\n";
			int bit;
			do
			{
					cout<<"ENTER Bit:";
					cin>>bit;
				if(bit!=-1)
				{ //cout<<"1111111";
					if(!(bit>1 || bit<-1))
					{
						//cout<<"222222";
						current=new node;
						current->data=bit;
						++size;
						if(head==NULL)
						{
							head=current;
							previous=current;
						}
						else
						{
							previous->forward=current;
							current->backward=previous;
							previous=current;
						}
						current->forward=NULL;
						tail=current;
					}
					else
						cout<<"\nEnter The Bit Again(Invalid Bit)(Enter -1 to exit)!!!"<<endl;
				}
				/*cout<<"\nDo You Want to continue??:\t";
				cin>>choice;*/
			}while(bit!=-1);
		}
		void display()
		{
			node* temp=head;
			while(temp!=NULL)
			{
				cout<<setw(2)<<temp->data;
				temp=temp->forward;
			}
			cout<<"\nTotal bits:"<<size<<endl;
		}
		dlink_list onesCompliment()
		{
			dlink_list onecomp;
			node* temp=head;
			node* current,*previous;
			while(temp!=NULL)
			{
				current=new node;
				++onecomp.size;
				//previous=current;
				if(temp->data)
					current->data=0;
				else
					current->data=1;
				if (onecomp.head==NULL)
					onecomp.head=current;
					
				else
				{
					previous->forward=current;
					current->backward=previous;
				}
				previous=current;
				temp=temp->forward;
					
			}
			onecomp.tail=current;
			return onecomp;
		}

		dlink_list operator +(dlink_list& second)
		{
			dlink_list add;                                         //Linked list to store addition of the two binary numbers.
			int sum=0;
			int carry=0;
			node* temp;
			
		//If second number has less bits than the first, extra 0's are added at msb till both numbers  have equal bits.
			if(second.size<size)
			{
				while(second.size<size)
				{
					temp=new node;
					temp->data=0;
					temp->backward=NULL;
					temp->forward=second.head;
					second.head->backward=temp;
					second.head=temp;
					second.size++;
				}
			}

		//If first number has less bits than the second, extra 0's are added at msb till both numbers  have equal bits.	
			if(second.size>size)
			{
				while(second.size>size)
				{
					temp=new node;
					temp->data=0;
					temp->backward=NULL;
					temp->forward=head;
					head->backward=temp;
					head=temp;
					size++;
				}
			}
			
			add.size=size;
			node* current;
			node* previous;
			
			for(int i=0;i<add.size;i++)
			{
				current=new node;
				current->forward=NULL;
				current->backward=NULL;
				current->data=0;
				
				if(add.head==NULL)
				{
					add.head=current;
					previous=current;
				}
				else
				{
					previous->forward=current;
					current->backward=previous;
					previous=current;
				}
			}
			add.tail=current;
			
			node* temp1=tail;
			node* temp2=second.tail;
			node* temp3=add.tail;
			
			while(temp1!=NULL)
			{
				sum=carry+temp1->data+temp2->data;
				if(sum==0)
				{
					temp3->data=0;
					carry=0;
				}
				if(sum==1)
				{
					temp3->data=1;
					carry=0;	
				}
				if(sum==2)
				{
					temp3->data=0;
					carry=1;
				}
				if(sum==3)
				{
					temp3->data=1;
					carry=1;
				}
				
				temp1=temp1->backward;
				temp2=temp2->backward;
				temp3=temp3->backward;
			}

		//If carry bit is generated it gets attached to the number as msb.	
			if(carry==1)
			{
				temp=new node;
				temp->data=carry;
				temp->forward=add.head;
				temp->backward=NULL;
				add.head=temp;
			}
			return add;
		}

		static dlink_list one()
		{
			dlink_list o;
			node *current;
			node* previous;
			
			o.size=2;
			
			for(int i=0;i<o.size;i++)
			{
				current=new node;
				current->forward=NULL;
				current->backward=NULL;
				current->data=0;
				
				if(o.head==NULL)
				{
					o.head=current;
					previous=current;
				}
				else
				{
					previous->forward=current;
					current->backward=previous;
					previous=current;
				}
			}
			
			o.tail=current;
			o.tail->data=1;
			
			return o;
		}
};
int main()
{
	dlink_list l1,l2,l3,l4,l5,oneList;
	oneList= dlink_list :: one();//Because FUnction is Declared Static we dont need an object to call it 
	char ch,yes;
	cout<<"\nENTER BINARY NO 1:\t";
	l1.create();
	cout<<"\nENTER BINARY NO 2:\t";
	l2.create();
	do
	{
		cout<<"\nEnter the Choice From The Menu:\n1.Display 1st No.\n2.Display 2nd No.\n3.Ones Complement(1)";
		cout<<"\n4.Ones Complement(2)\n5.Twos Complement(1)\n6.Twos Complement(2)"<<endl;
		cin>>ch;
		switch(ch)
		{
			case'1':
					cout<<"FIRST NO.";
					l1.display();
					break;
			case'2':
					cout<<"SECOND NO.";
					l2.display();
					break;
			case'3':
					l3=l1.onesCompliment();
					cout<<"FIRST NO.(ONEs)";
					l3.display();
					break;
			case'4':
					l4=l2.onesCompliment();
					cout<<"SECOND NO.(ONEs)";
					l4.display();
					break;
			
			case'5':
					l3=l1.onesCompliment();
					l5=l3+oneList;//TWOs Compliment=ONEs Compliment+1
					cout<<"FIRST NO.(TWOs)";
					l5.display();
					break;
			case'6':
					l4=l2.onesCompliment();
					l5=l4+oneList;////TWOs Compliment=ONEs Compliment+1
					cout<<"FIRST NO.(TWOs)";
					l5.display();
					break;
			default:
					cout<<"\nEnter Valid Choice"<<endl;
					break;
		}
		cout<<"\nDo You Wish To Continue\?\?(Y/y)"<<endl;
		cin>>yes;
	}while(yes=='y'||yes=='Y');
	return 0;
}
/*
SAMPLE OUTPUT:
ubuntu@DESKTOP-4FQXGZ1:~$ cd //mnt/z/DSA
ubuntu@DESKTOP-4FQXGZ1://mnt/z/DSA$ g++ binary.cpp
ubuntu@DESKTOP-4FQXGZ1://mnt/z/DSA$ ./a.out

ENTER BINARY NO 1:
Enter the Binary no
(MSB->->->LSB)
(-1 to end the no.)
ENTER Bit:1
ENTER Bit:0
ENTER Bit:1
ENTER Bit:0
ENTER Bit:-1

ENTER BINARY NO 2:
Enter the Binary no
(MSB->->->LSB)
(-1 to end the no.)
ENTER Bit:0
ENTER Bit:1
ENTER Bit:0
ENTER Bit:1
ENTER Bit:-1

Enter the Choice From The Menu:
1.Display 1st No.
2.Display 2nd No.
3.Ones Complement(1)
4.Ones Complement(2)
5.Twos Complement(1)
6.Twos Complement(2)
1
FIRST NO. 1 0 1 0
Total bits:4

Do You Wish To Continue??(Y/y)
y

Enter the Choice From The Menu:
1.Display 1st No.
2.Display 2nd No.
3.Ones Complement(1)
4.Ones Complement(2)
5.Twos Complement(1)
6.Twos Complement(2)
2
SECOND NO. 0 1 0 1
Total bits:4

Do You Wish To Continue??(Y/y)
y

Enter the Choice From The Menu:
1.Display 1st No.
2.Display 2nd No.
3.Ones Complement(1)
4.Ones Complement(2)
5.Twos Complement(1)
6.Twos Complement(2)
3
FIRST NO.(ONEs) 0 1 0 1
Total bits:4

Do You Wish To Continue??(Y/y)
y

Enter the Choice From The Menu:
1.Display 1st No.
2.Display 2nd No.
3.Ones Complement(1)
4.Ones Complement(2)
5.Twos Complement(1)
6.Twos Complement(2)
4
SECOND NO.(ONEs) 1 0 1 0
Total bits:4

Do You Wish To Continue??(Y/y)
y

Enter the Choice From The Menu:
1.Display 1st No.
2.Display 2nd No.
3.Ones Complement(1)
4.Ones Complement(2)
5.Twos Complement(1)
6.Twos Complement(2)
5
FIRST NO.(TWOs) 0 1 1 0
Total bits:4

Do You Wish To Continue??(Y/y)
y

Enter the Choice From The Menu:
1.Display 1st No.
2.Display 2nd No.
3.Ones Complement(1)
4.Ones Complement(2)
5.Twos Complement(1)
6.Twos Complement(2)
6
FIRST NO.(TWOs) 1 0 1 1
Total bits:4

Do You Wish To Continue??(Y/y)
n
ubuntu@DESKTOP-4FQXGZ1://mnt/z/DSA$ 
*/
