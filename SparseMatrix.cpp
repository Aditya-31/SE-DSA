/*			A C++ Program to perform operations(read & display) on SPARSE MATRIX
	NAME: Aditya Gade		STD/DIV: S.E.Comp/A			Rollno.:19		DATE: 12/07/2019 */
#include<iostream>
using namespace std;

void getdata(int m[][3],int x,int r,int c,int n)
{
	m[0][0]=r;
	m[0][1]=c;
	m[0][2]=n;
	
	for(int i=1;i<x;i++)
	{
		cout<<"Enter the details of"<<i<<"th non zero element."<<endl;
		cout<<"Enter row position: "<<endl;
		cin>>m[i][0];
		cout<<"Enter the column position: "<<endl;
		cin>>m[i][1];
		cout<<"Enter value: "<<endl;
		cin>>m[i][2];
		cout<<endl;
	}
	cout<<endl;
	
	int temp[3];
	
	for(int i=1;i<x-1;i++)
		for(int j=i+1;j<x;j++)
		{
			if(m[i][0]>m[j][0])
			{
				for(int p=0;p<3;p++)
					temp[p]=m[i][p];
				for(int p=0;p<3;p++)
					m[i][p]=m[j][p];
				for(int p=0;p<3;p++)
					m[j][p]=temp[p];
			}
		}
		
	for(int i=1;i<x-1;i++)	
		for(int j=i+1;j<x;j++)
		{
			if(m[i][0]==m[j][0])
				if(m[i][1]>m[j][1])
				{
					for(int p=0;p<3;p++)
						temp[p]=m[i][p];
					for(int p=0;p<3;p++)
						m[i][p]=m[j][p];
					for(int p=0;p<3;p++)
						m[j][p]=temp[p];
				}
		}
	
}

void show(int a[][3],int x)
{
	for(int i=0;i<x;i++)
	{
		int flag;
		for(int j=0;j<3;j++)
		{
			if(a[i][3]!=0)
			{
				cout<<a[i][j]<<"\t";
				flag=1;
			}
			else
			{	
				--a[0][3];
				flag=0;
			}
			if(flag!=1)
				break;
		}
		cout<<endl;
	}
}

void get_transpose(int a[][3],int x,int r,int c,int n)
{
	int t[x][3];
	
	t[0][0]=c;
	t[0][1]=r;
	t[0][2]=n;
	
	for(int i=1;i<x;i++)
	{
		t[i][0]=a[i][1];
		t[i][1]=a[i][0];
		t[i][2]=a[i][2];
	}
	
	int temp[3];
	
	for(int i=1;i<x-1;i++)
		for(int j=i+1;j<x;j++)
		{
			if(t[i][0]>t[j][0])
			{
				for(int p=0;p<3;p++)
				{
					temp[p]=t[i][p];
				//for(int p=0;p<3;p++)
					t[i][p]=t[j][p];
				//for(int p=0;p<3;p++)
					t[j][p]=temp[p];
				}
			}
		}
		
	for(int i=1;i<x-1;i++)	
		for(int j=i+1;j<x;j++)
		{
			if(t[i][0]==t[j][0])
				if(t[i][1]>t[j][1])
				{
					for(int p=0;p<3;p++)
					{
						temp[p]=t[i][p];
					//for(int p=0;p<3;p++)
						t[i][p]=t[j][p];
					//for(int p=0;p<3;p++)
						t[j][p]=temp[p];
					}
				}
		}
		
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<t[i][j]<<"\t";
		}
		cout<<endl;
	}
	
} 

void add(int a[][3],int x1,int b[][3],int x2)
{
	int flag;
	if(a[0][0]==b[0][0] && a[0][1]==b[0][1])
		flag=1;
	else
		flag=0;
	
		
	int r1,r2,c1,c2,n1,n2;
	
	r1=a[0][0];
	c1=a[0][1];
	n1=a[0][2];
	
	r2=b[0][0];
	c2=b[0][1];
	n2=b[0][2];
	
	int n=n1+n2;
	int i=1;
	int j=1;	
	int k=1;
	int c[n+1][3];
	
	if(flag)
	{
		c[0][0]=r1;
		c[0][1]=c1;
		
		while(i<x1 && j<x2)
		{
			if(a[i][0]==b[j][0])
			{
				if(a[i][1]==b[j][1])
				{
					c[k][0]=a[i][0];
					c[k][1]=a[i][1];
					c[k][2]=a[i][2]+b[j][2];
					i++;j++;k++;
				}
				
				else if(a[i][1]<b[j][1])
				{
					c[k][0]=a[i][0];
					c[k][1]=a[i][1];
					c[k][2]=a[i][2];
					i++;k++;
				}
				
				else
				{
					c[k][0]=b[j][0];
					c[k][1]=b[j][1];
					c[k][2]=b[j][2];
					j++;k++;
				}
			}
			
			else if(a[i][0]<b[j][0])
			{
				c[k][0]=a[i][0];
				c[k][1]=a[i][1];
				c[k][2]=a[i][2];
				i++;k++;
			}
			
			else
			{
				c[k][0]=b[j][0];
				c[k][1]=b[j][1];
				c[k][2]=b[j][2];
				j++;k++;
			}
		}
		
		while(i<x1)
		{
			c[k][0]=a[i][0];
			c[k][1]=a[i][1];
			c[k][2]=a[i][2];
			i++;k++;
		}
		
		while(j<x2)
		{
			c[k][0]=b[j][0];
			c[k][1]=b[j][1];
			c[k][2]=b[j][2];
			j++;k++;
		}
		
		c[0][2]=k-1;
	
		cout<<"The addition of the two matrices is: "<<endl;
		/*for(int i=0;i<k;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<c[i][j]<<"\t";
			}
			cout<<endl;
		}*/
		show(c,k+1);
	}
}
int main()
{
	int r1,c1,n1;	
	cout<<"Enter the number of rows in sparse matrix"<<endl;
	cin>>r1;
	cout<<"Enter the number of columns in sparse matrix"<<endl;
	cin>>c1;	
	cout<<"Enter the number of non zero elements in sparse matrix"<<endl;
	cin>>n1;
	
	int sparse1[n1+1][3];
	getdata(sparse1,n1+1,r1,c1,n1);	
	
	int r2,c2,n2;	
	cout<<"Enter the number of rows in sparse matrix"<<endl;
	cin>>r2;
	cout<<"Enter the number of columns in sparse matrix"<<endl;
	cin>>c2;
	cout<<"Enter the number of non zero elements in sparse matrix"<<endl;
	cin>>n2;
	
	int sparse2[n2+1][3];	
	getdata(sparse2,n2+1,r2,c2,n2);
	
	char choice;
	do
	{
		cout<<"1.Display Matirx A\n2.Display Matirx B\n3.Addition of Sparse Matrices\n4.Transpose of A\n5.Transpose of B\n6.Transpose of A\n7.Transpose of B\n"<<endl;
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"The sparse representation of first matrix is:"<<endl;
				show(sparse1,n1+1);
				break;
			case 2:
				cout<<"The sparse representation of second matrix is:"<<endl;
				show(sparse2,n2+1);
				break;
			case 3:
				add(sparse1,n1+1,sparse2,n2+1);
				break;
			case 4:
				cout<<"The sparse representation of transpose of first matrix is:"<<endl;
				get_transpose(sparse1,n1+1,r1,c1,n1);	
				break;
			case 5:
				cout<<"The sparse representation of transpose of second matrix is:"<<endl;
				get_transpose(sparse2,n2+1,r2,c2,n2);
				break;
			case 6:
				break;
			case 7:
				break;

		}
		cout<<"You wish to continue (Y/N)"<<endl;
		
		cin>>choice;
	}while(choice=='Y'||choice=='y');
	return 0;
}

