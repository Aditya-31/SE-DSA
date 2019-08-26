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
		dlink_list one()
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
	dlink_list l1,l2;
	l1.create();
	cout<<"\nENTERED BINARY NO IS:\t";
	l2.create();
	cout<<"\nENTERED BINARY NO IS:\t";
	return 0;
}
