/*A palindrome is a string of character that‘s the same forward and backward. Typically,
punctuation, capitalization, and spaces are ignored. For example, ‖Poor Dan is in a droop‖ is
a palindrome, as can be seen by examining the characters ―poor danisina droop‖ and
observing that they are the same forward and backward. One way to check for a
palindrome is to reverse the characters in the string and then compare with them the

original-in a palindrome, the sequence will be identical. Write C++ program with functions-
1. To check whether given string is palindrome or not that uses a stack to determine whether

a string is a palindrome.
2. to remove spaces and punctuation in string, convert all the Characters to lowercase, and
then call above Palindrome checking function to check for a palindrome
3. to print string in reverse order using stack*/
/*NAME: ADITYA GADE 	Class: SE-A(COMP)	Date of creation:26-08-2018		Last Updated: 30-08-19*/
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
