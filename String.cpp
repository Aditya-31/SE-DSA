#include<iostream>
//#include<string.h>
#define n 20
#define maximum 50
using namespace std;
class A
{
	int max;
	int length;
	char str[maximum];
	public:
		A()
		{
			max=n;
			length=0;
		}
		void copy(const A &s,const int& m)
		{
			int i=0;
			for(;i<m;i++)
				str[i]=s.str[i];
			str[i]='\0';
		}
		int string_length()
		{
			return length;
		}
		void read()
		{
			cout<<"\n Enter a String to be read."<<endl;
			cin.getline(str,n);
			int temp=0;
			while(str[temp]!='\0')
			{
				temp++;
				length++;
			}	
		
		}
		void display()
		{
			cout<<"The string you entered is :\n"<<str<<endl;	
		}
		A reverse(const int& m)
		{
			A temp;
			int i=0,j=m-1;
			for(;i<m,j>=0;i++,j--)
				temp.str[i]=str[j];
			temp.str[i]='\0';
			return temp;
		}
		A concatinate(const A& s1,const A& s)
		{
			A temp;
			int i=0,j=0,k=0;
			while (s1.str[i]!='\0')
			{
				temp.str[k]=s1.str[i];
				i++;
				k++;
			}
			if(s1.str[i]=='\0')
			{
				while (s.str[j]!='\0')
				{
					temp.str[k]=s.str[j];
					j++;
					k++;
				}
				temp,str[k]='\0';	
			}
			return temp;
		}
		int compare(const int& m,const A& s,const int& o)
		{
			if(m==o)
			{
				int i=0;
				for(;i<m;i++)
				{	if(str[i]==s.str[i])
						continue;
					else
						return 0;
				}
			}
			else if(m>o)
				return -1;
			else 
				return -2;
		}
		
		void str_print()
		{
			cout<<str;
		}
		
		int substring(A& s1)
		{
		    int M = s1.string_length();
 		    int N = string_length();
		    for (int i = 0; i <= N - M; i++) 
		    {
	 	       int j;
 		       for (j = 0; j < M; j++)
 		           if (str[i + j] != s1.str[j])
 		               break;
 		 
		        if (j == M)
 		       	    return i;
 		    }
  
 			   return -1;
		}
};

int main()
{
	A s1,s;
	s1.read();
	s.read();	
	char ch1,ch;
	
	A s2;
	A s3;
	A s31;
	A s4;
	int str_len1=s1.string_length(),str_len2=s.string_length();
	int com=s1.compare(str_len1,s,str_len2);
	A s5;
	A s6;
	int present1,present;
	do
	{
		cout<<"\nENTER THE CHOICES:\n1.Display Input Strings S1 and S2.\n2.String Copy\n3.String Reverse S1\n4.String Reverse S2\n5.String Concatinate S1 and S2\n6.String Compare S1 and S2\n"/*7.Substring S1.\n8.Substring S2."*/<<endl;
		cin>>ch;
		switch(ch)
		{
		case '1':
			cout<<"STRING 1:"<<endl;
			s1.display();
			cout<<"STRING 2:"<<endl;
			s.display();
			break;
		case '2':
			//STRING COPY
			
			s2.copy(s1,s1.string_length());
			cout<<"\n\nSTRING COPY:"<<endl;
			cout<<"Copied string is:"<<endl;
			s2.display();
			break;
		case '3':
	
			//STRING REVERSE S1
			
			s3=s1.reverse(s1.string_length());
			cout<<"\n\nSTRING REVERSE S1:"<<endl;
			s3.display();
			break;
		case '4':
			//STRING REVERSE S2
			
			s31=s2.reverse(s2.string_length());
			cout<<"\n\nSTRING REVERSE S2:"<<endl;
			s3.display();
			break;
		case '5':
			//STRING CONCATINATE
			
			s4=s1.concatinate(s1,s);
			cout<<"\n\nSTRING CONCATINATE:"<<endl;
			s4.display();
			break;
		case '6':
			//STRING COMPARE
			
			if(com==0)
				cout<<"\nSTRINGS ARE UNEQUAL IN COMPONENTS BUT EQUAL IN LENGTH";
			else if(com==-1)
			{
				cout<<"\nSTRING 1 ";
				s1.str_print();
				cout<<"is bigger";
			}
			else if(com==-2)
			{
				cout<<"\nSTRING 2 ";
				s.str_print();
				cout<<"is bigger";
			}
			else
				cout<<"\nSTRINGS ARE EQUAL";
			break;
		/*case '7':
			//SUBSTRING S1
			
			s5.read();
			present1= s1.substring(s5);
			if (present1 == -1)
				cout << "Substring Entered isn't present";
			else
				cout << "Substring Entered Present at Position " << present1+1;
			break;
		case '8':
			//SUBSTRING
			
			s6.read();
			present = s2.substring(s6);
			if (present == -1)
				cout << "Substring Entered isn't present";
			else
				cout << "Substring Entered Present at Position " << present+1;
			break;
		*/
		default:
			cout<<"\nEnter proper choice"<<endl;
			break;
		}
	cout<<"\n\nDo you want to continue ???"<<endl;
	cin>>ch1;
	}while(ch1=='y'||ch1=='Y');
	
	return 0;
}
