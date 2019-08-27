#include<iostream>
using namespace std;
template<class T>
class Stack
{
	T* s;
	int top;
	int capacity;
    public:
               Stack(int n )
               {
               	s=new T[n];
               	top=-1;
               	capacity=n;
               	
               }
               void push(T e)
               {
               	if(!isFull())
                      s[++top]=e;
               }
               T pop ()
               {
               	if(!isEmpty())
               	     return s[top--];
               	return -1;
               }
               int isFull()
               {return top==capacity-1;}
               
               int isEmpty()
               {return top==-1;}
};
int main()
{
	char line[30];
	cout<<"\nEnter the line which is to be checked if palindrome or not\n";
	cin.getline(line,31,'+');
	Stack <char> S1(30);
	 for(int i=0;line[i]!='\0';i++)
	 {
	 	char temp;
	 	temp=(char)tolower(line[i]);
	 	if(('a'<=temp &&temp>='z') || ('A'<=temp &&temp>='Z'))
	          S1.push(temp);
	 }
	 
	 int flag;
	  for(int i=0;line[i]!='\0';i++)
	 {
	 	char temp;
	 	temp=(char)tolower(line[i]);
	 	if(('a'<=temp &&temp>='z') ||         ('A'<=temp &&temp>='Z'))
	 	{
	 		if(temp==S1.pop())
	 	     flag=1;
	 	 else
	 	  {    
	 	     flag=0;
	 	     break;
	 	  }
	 	}
	 }
	 if(flag==1)
	     cout<<"String is Palindrome";
	 else
	    cout<<"String isnt Palindrome";
	return 0;
}