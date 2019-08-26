/*		A C++ Program to read,display,and calculate sum,average,maximum and minimum value in a user given array
			NAME: Aditya Gade		STD/DIV: S.E.Comp/A			Rollno.:19		DATE: 21/06/2019 */
#include<iostream>
using namespace std;
int main()
{	
	cout<<"\nEnter the maximum size of array"<<endl;
	int no;
	cin>>no;
	int array[no];

	cout<<"\nEnter the Marks for "<<no<<" Students(Enter '-1' for Absent Students)"<<endl;
	for(int i=0;i<no;i++)
	{
		cout<<i+1<<":";
		cin>>array[i];
		cout<<endl;
	}

	cout<<"\nThe Marks of student are:"<<endl;
	for(int i=0;i<no;i++)
	cout<<i+1<<":"<<array[i]<<endl;
		char ch1;


int sum=0;
int sum1=0;
int count=0;
int max=0;
int min;
for(int i=0;i<no;i++)
{	int flag=0;
	if(array[i]>0)
	{
		min=array[i];
		break;
	}
}
float avg;
int no1;
float avg1;
char a;
do

	{	
		cout<<"\nENTER YOUR CHOICE:\n1:SUM and AVERAGE (With ABSENT):\n2:SUM and AVERAGE (Without ABSENT):\n3:MAX:\n4:MIN:\n5:ONLY PRESENT(with marks):"<<endl;
		cin>>a;
		switch(a)
		{
			case '1':
				
				for(int i=0;i<no;i++)
				sum=sum+array[i];	
				cout<<"\nThe total of the array is(With ABSENT):"<<sum<<endl;
			
				avg=(float)sum/no;
				cout<<"\nAverage of the array elements is(WITH ABSENT):"<<avg<<endl;
				break;
			case '2':
				
				for(int i=0;i<no;i++)
				if(array[i]>0)
				sum1=sum1+array[i];	
				cout<<"\nThe total of the array is(Without ABSENT):"<<sum1<<endl;
				
				
				for(int i=0;i<no;i++)
				if(array[i]==-1)
				count++;
				no1=no-count;
				avg1=(float)sum1/(float)no1;
				cout<<"\nAverage of the array elements is(Without ABSENT):"<<avg1<<endl;
				break;
			case '3':
				
				for(int i=0;i<no;i++)
				if(array[i]>max)
					max=array[i];
				cout<<"\nThe highest marks in the array are:"<<max<<endl;
				break;
			case '4':
				
				for(int i=0;i<no;i++)
				{		if(array[i]>-1)
						{
							if(array[i]<min)
							min=array[i];
						}
				}
				cout<<"\nThe lowest marks in the array are:"<<min<<endl;
				break;
	
			case '5':
				cout<<"\n The present students are(with marks):"<<endl;
			for(int i=0;i<no;i++)
				if(array[i]!=-1)
				cout<<i+1<<":"<<array[i]<<endl;
				break;
			
			default:
				cout<<"\nENTER PROPER CHOICE";
				break;
		
		}

		cout<<"\n\nDo you want to continue ???"<<endl;
		cin>>ch1;
		
	}while(ch1=='y'||ch1=='Y');

	
	return 0;
}
/*
OUTPUT:

unix@unix-dx2480-MT:~$ cd SEA19
unix@unix-dx2480-MT:~/SEA19$ g++ 1st.cpp
unix@unix-dx2480-MT:~/SEA19$ ./a.out

Enter the maximum size of array5

Enter the Array elements
1
2
3
4
5

The Array elements are:
1
2
3
4
5

The total of the array is:15

Average of the array elements is:3

The highest value in the array is:5

The lowest value in the array is:1
unix@unix-dx2480-MT:~/SEA19$ 

*/
/*
OUTPUT:(After Modificiation:)
unix@unix-dx2480-MT:~$ cd SEA19
unix@unix-dx2480-MT:~/SEA19$ g++ 1st.cpp
unix@unix-dx2480-MT:~/SEA19$ ./a.out

Enter the maximum size of array5

Enter the Marks for 5 Students(Enter '-1' for Absent Students)
1:12

2:23

3:30

4:-1

5:-1


The Marks of student are:
1:12
2:23
3:30
4:-1
5:-1

The total of the array is:63

Average of the array elements is:12.6

The highest marks in the array are:30

The lowest marks in the array are:12

 The present students are(with marks):
1:12
2:23
3:30
unix@unix-dx2480-MT:~/SEA19$ 

*/
/*
OUTPUT:(before switch case)
unix@unix-dx2480-MT:~$ cd SEA19
unix@unix-dx2480-MT:~/SEA19$ g++ 1st.cpp
unix@unix-dx2480-MT:~/SEA19$ ./a.out

Enter the maximum size of array5

Enter the Marks for 5 Students(Enter '-1' for Absent Students)
1:12

2:13

3:20

4:-1

5:-1


The Marks of student are:
1:12
2:13
3:20
4:-1
5:-1

The total of the array is(With ABSENT):43

Average of the array elements is(WITH ABSENT):8.6

The total of the array is(Without ABSENT):45

Average of the array elements is(Without ABSENT):15

The highest marks in the array are:20

The lowest marks in the array are:12

 The present students are(with marks):
1:12
2:13
3:20
unix@unix-dx2480-MT:~/SEA19$ 
*/
/*
FINAL OUTPUT:
unix@unix-dx2480-MT:~$ cd SEA19
unix@unix-dx2480-MT:~/SEA19$ g++ 1st.cpp
unix@unix-dx2480-MT:~/SEA19$ ./a.out

Enter the maximum size of array
5

Enter the Marks for 5 Students(Enter '-1' for Absent Students)
1:12

2:13

3:30

4:-1

5:-1


The Marks of student are:
1:12
2:13
3:30
4:-1
5:-1
1:SUM and TOTAL (With ABSENT):
2:SUM and TOTAL (Without ABSENT):
3:MAX:
4:MIN:
5:ONLY PRESENT(with marks):
1

ENTER PROPER CHOICEDo you want to continue ???n
unix@unix-dx2480-MT:~/SEA19$ g++ 1st.cpp
unix@unix-dx2480-MT:~/SEA19$ ./a.out

Enter the maximum size of array
5

Enter the Marks for 5 Students(Enter '-1' for Absent Students)
1:12

2:13

3:30

4:-1

5:-1


The Marks of student are:
1:12
2:13
3:30
4:-1
5:-1
1:SUM and TOTAL (With ABSENT):
2:SUM and TOTAL (Without ABSENT):
3:MAX:
4:MIN:
5:ONLY PRESENT(with marks):
1

The total of the array is(With ABSENT):53

Average of the array elements is(WITH ABSENT):10.6
Do you want to continue ???y
1:SUM and TOTAL (With ABSENT):
2:SUM and TOTAL (Without ABSENT):
3:MAX:
4:MIN:
5:ONLY PRESENT(with marks):
2

The total of the array is(Without ABSENT):55

Average of the array elements is(Without ABSENT):18.3333
Do you want to continue ???y
1:SUM and TOTAL (With ABSENT):
2:SUM and TOTAL (Without ABSENT):
3:MAX:
4:MIN:
5:ONLY PRESENT(with marks):
3

The highest marks in the array are:30
Do you want to continue ???y
1:SUM and TOTAL (With ABSENT):
2:SUM and TOTAL (Without ABSENT):
3:MAX:
4:MIN:
5:ONLY PRESENT(with marks):
4

The lowest marks in the array are:12
Do you want to continue ???y
1:SUM and TOTAL (With ABSENT):
2:SUM and TOTAL (Without ABSENT):
3:MAX:
4:MIN:
5:ONLY PRESENT(with marks):
5

 The present students are(with marks):
1:12
2:13
3:30
Do you want to continue ???n
unix@unix-dx2480-MT:~/SEA19$ 
*/
