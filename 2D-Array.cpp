/*		A C++ Program to read,display,and calculate addition,subtraction,multiplication of 2 multidiemensional array
			NAME: Aditya Gade		STD/DIV: S.E.Comp/A			Rollno.:19		DATE: 24/06/2019 */
#include <iostream>
using namespace std;
const int m=10;
const int n=10;



	void show(int a[][n],int b[][n],int r,int c);
	void addition(int a[][n],int b[][n],int add[][n],int r,int c);
	void subtraction1(int a[][n],int b[][n],int sub1[][n],int r,int c);
	void subtraction2(int a[][n],int b[][n],int sub2[][n],int r,int c);
	void multiplication(int a[][n],int b[][n],int mul[][n],int r,int c);	



int main()
{	
	int r,c;
	int a[m][n],b[m][n],add[m][n],sub1[m][n],sub2[m][n],mul[m][n];
	cout<<"\nEnter the maximum rows of array"<<endl;
	cin>>r;
	cout<<"\nEnter the maximum columns of array"<<endl;
	cin>>c;
	
	cout<<"Enter the matrix A of "<<r<<"rows and "<<c<<" columns."<<endl;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		cin>>a[i][j];
	cout<<"Enter the matrix B of "<<r<<"rows and "<<c<<" columns."<<endl;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		cin>>b[i][j];
	char ch,ch1;
	
	do
	{
		cout<<"\nENTER THE CHOICES:\n1.Display Input Matrix\n2.Addition of Input Matrix\n3.Subtraction of Input Matrix (A-B)\n4.Subtraction of Input Matrix (B-A)\n5. Multiplication of Input Matrix"<<endl;
		cin>>ch;
		switch(ch)
		{
		case '1':
			show(a,b,r,c);
			break;
		case '2':
			addition(a,b,add,r,c);
			break;
		case '3':
			subtraction1(a,b,sub1,r,c);
			break;
		case '4':
			subtraction2(a,b,sub2,r,c);
			break;
		case '5':
			multiplication(a,b,mul,r,c);
			break;
		default:
			cout<<"\nEnter proper choice"<<endl;
			break;
		}
	cout<<"\n\nDo you want to continue ???"<<endl;
	cin>>ch1;
	}while(ch1=='y'||ch1=='Y');
	return 0;
}

void show(int a[m][n],int b[m][n],int r,int c)
{
	cout<<"The input matrix are:"<<endl;
	cout<<"\nMatrix A: "<<endl;
	for(int i=0;i<r;i++)
	{	for(int j=0;j<c;j++)
		cout<<a[i][j]<<"\t";
	cout<<"\n";
	}
	cout<<"\nMatrix B: "<<endl;
	for(int i=0;i<r;i++)
	{	for(int j=0;j<c;j++)
		cout<<b[i][j]<<"\t";
	cout<<"\n";
	}
}

void addition(int a[m][n],int b[m][n],int add[m][n],int r,int c)
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		add[i][j]=a[i][j]+b[i][j];

	cout<<"\nMatrix ADDITION: "<<endl;
	for(int i=0;i<r;i++)
	{	for(int j=0;j<c;j++)
		cout<<add[i][j]<<"\t";
	cout<<"\n";
	}
}

void subtraction1(int a[m][n],int b[m][n],int sub1[m][n],int r,int c)
{
 	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		sub1[i][j]=a[i][j]-b[i][j];

	cout<<"\nMatrix SUBTRACTION(A-B): "<<endl;
	for(int i=0;i<r;i++)
	{	for(int j=0;j<c;j++)
		cout<<sub1[i][j]<<"\t";
	cout<<"\n";
	}
}

void subtraction2(int a[m][n],int b[m][n],int sub2[m][n],int r,int c)
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		sub2[i][j]=b[i][j]-a[i][j];

	cout<<"\nMatrix SUBTRACTION (B-A): "<<endl;
	for(int i=0;i<r;i++)
	{	for(int j=0;j<c;j++)
		cout<<sub2[i][j]<<"\t";
	cout<<"\n";
	}
}

void multiplication(int a[m][n],int b[m][n],int mul[m][n],int r,int c)
{
	 for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
		mul[i][j]=0;
	 for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			for(int k = 0; k < c; k++)
			{
			mul[i][j] += a[i][k] * b[k][j];
			}

	cout<<"\nMatrix MULTIPLICATION: "<<endl;
	for(int i=0;i<r;i++)
	{	for(int j=0;j<c;j++)
		cout<<mul[i][j]<<"\t";
	cout<<"\n";
	}
}

/*
OUTPUT:
unix@unix-dx2480-MT:~/SEA19$ g++ 2nd.cpp
unix@unix-dx2480-MT:~/SEA19$ ./a.out

Enter the maximum rows of array
3

Enter the maximum columns of array
3
Enter the matrix A of 3rows and 3 columns.1
2
3
4
5 
6
7
8
9
Enter the matrix B of 3rows and 3 columns.9
8
7
6
5
4
3
2
1

ENTER THE CHOICES:
1.Display Input Matrix
2.Addition of Input Matrix
3.Subtraction of Input Matrix (A-B)
4.Subtraction of Input Matrix (B-A)
5. Multiplication of Input Matrix

Enter proper choice


Do you want to continue ???
^[[A^[[A^Z
[1]+  Stopped                 ./a.out
unix@unix-dx2480-MT:~/SEA19$ g++ 2nd.cpp
unix@unix-dx2480-MT:~/SEA19$ ./a.out

Enter the maximum rows of array
2

Enter the maximum columns of array
2
Enter the matrix A of 2rows and 2 columns.
1
2
3
4
Enter the matrix B of 2rows and 2 columns.
4
3
2
1

ENTER THE CHOICES:
1.Display Input Matrix
2.Addition of Input Matrix
3.Subtraction of Input Matrix (A-B)
4.Subtraction of Input Matrix (B-A)
5. Multiplication of Input Matrix
1
The input matrix are:

Matrix A: 
1	2	
3	4	

Matrix B: 
4	3	
2	1	


Do you want to continue ???
y

ENTER THE CHOICES:
1.Display Input Matrix
2.Addition of Input Matrix
3.Subtraction of Input Matrix (A-B)
4.Subtraction of Input Matrix (B-A)
5. Multiplication of Input Matrix
2

Matrix ADDITION: 
5	5	
5	5	


Do you want to continue ???
y

ENTER THE CHOICES:
1.Display Input Matrix
2.Addition of Input Matrix
3.Subtraction of Input Matrix (A-B)
4.Subtraction of Input Matrix (B-A)
5. Multiplication of Input Matrix
3

Matrix SUBTRACTION(A-B): 
-3	-1	
1	3	


Do you want to continue ???
y

ENTER THE CHOICES:
1.Display Input Matrix
2.Addition of Input Matrix
3.Subtraction of Input Matrix (A-B)
4.Subtraction of Input Matrix (B-A)
5. Multiplication of Input Matrix
4

Matrix SUBTRACTION (B-A): 
3	1	
-1	-3	


Do you want to continue ???
y

ENTER THE CHOICES:
1.Display Input Matrix
2.Addition of Input Matrix
3.Subtraction of Input Matrix (A-B)
4.Subtraction of Input Matrix (B-A)
5. Multiplication of Input Matrix
5

Matrix MULTIPLICATION: 
7	5	
-2021782668	32585	


Do you want to continue ???
y

ENTER THE CHOICES:
1.Display Input Matrix
2.Addition of Input Matrix
3.Subtraction of Input Matrix (A-B)
4.Subtraction of Input Matrix (B-A)
5. Multiplication of Input Matrix
6

Enter proper choice


Do you want to continue ???
n
unix@unix-dx2480-MT:~/SEA19$ 

*/
