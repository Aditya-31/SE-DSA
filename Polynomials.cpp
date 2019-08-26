/*				A C++ Program to read,display & add polynomials
			NAME: Aditya Gade		STD/DIV: S.E.Comp/A			Rollno.:19		DATE: 5/07/2019 */

#include<iostream>
#include<stdio.h>
#include<math.h> 
using namespace std; 

struct term
{
	int exp;
	int coeff;
};

class polynomial
{
		int total;
		term t[20];
	public:
		void getdata();
		void display();
		double evaluate(double);
		polynomial add(polynomial&); 
		polynomial mult(polynomial&);
};

void polynomial::getdata()
{
	cout<<"Enter total number of terms in polynomial ";
	cin>>total;
	cout<<endl;
	if(total>20)
		do
		{
			cout<<"Maximum allowable terms are 20\nEnter valid number";
			cin>>total;
			cout<<"\n";	
		}while(total>20);	
	
	for(int i=0;i<total;i++)
	{
		cout<<"Enter term "<<i+1<<endl;
		cout<<"\nCoefficient: ";
		cin>>t[i].coeff;
		cout<<"Exponent: ";
		cin>>t[i].exp;
		cout<<endl;
	}	
	
	cout<<endl;
}

void polynomial::display()
{
	int i;
	for(i=0;i<total-1;i++)
		if(t[i].exp>0)
		{
			if(i==1)
				printf("%dx^%d",t[i].coeff,t[i].exp);
			printf("%+dx^%d",t[i].coeff,t[i].exp);
		}
		if(t[i].exp==1)
			printf("%+dx",t[i].coeff);
		if(t[i].exp<1)
			printf("(%+d)",t[i].coeff);
	if(t[i].exp>0)
		printf("(%+d)x^%d",t[i].coeff,t[i].exp);
	if(t[i].exp==1)
		printf("(%+d)",t[i].coeff);
	if(t[i].exp<1)
		printf("(%+d)",t[i].coeff);
	cout<<endl;
}

double polynomial::evaluate(double n)
{
	double value=0;
	for(int i=0;i<total;i++)
		value=value+t[i].coeff*pow(n,t[i].exp);
		
	return value;
}

polynomial polynomial::add(polynomial& B)
{
	polynomial C;
	int i,j,k;
	i=j=k=0;
	
	while(i<total && j<B.total)
	{
		if(t[i].exp==B.t[j].exp)
		{
			C.t[k].coeff=t[i].coeff+B.t[j].coeff;
			C.t[k].exp=t[i].exp;
			i++;j++;k++;
		}	
			
		else if(t[i].exp>B.t[j].exp)
		{
			C.t[k].coeff=t[i].coeff;
			C.t[k].exp=t[i].exp;
			i++;k++;
		}
			
		else
		{
			C.t[k].coeff=B.t[j].coeff;
			C.t[k].exp=B.t[j].exp;
			j++;k++;
		}	
	}
		
	while(i<total)
	{
		C.t[k].coeff=t[i].coeff;
		C.t[k].exp=t[i].exp;
		i++;k++;
	}
	
	while(j<B.total)
	{
		C.t[k].coeff=B.t[j].coeff;
		C.t[k].exp=B.t[j].exp;
		j++;k++;
	}	
	
	C.total=k;
	return C;	 
}

polynomial polynomial::mult(polynomial& B)
{
	polynomial C;
	int i,j,k;
	i=j=k=0;
	int flag=1;
	int new_coeff,new_exp;
	
	for(i=0;i<total;i++)
	{
		for(j=0;j<B.total;j++)
		{
			flag=1;
			C.t[k].coeff=t[i].coeff*B.t[j].coeff;
			C.t[k].exp=t[i].exp+B.t[j].exp;
			
			for(int n=0;n<k-1;n++)
				if(C.t[k].exp==C.t[n].exp)
				{
					cout<<"Inside the search."<<endl;
					C.t[n].coeff=C.t[n].coeff+C.t[k].coeff;
					flag=0;
				}
			
			if(flag==1)
			k++;	
		}
	}
	C.total=k;
	return C;
}

int main()
{
	polynomial p1;
	
	cout<<"Polynomial 1:"<<endl;
	p1.getdata();
	cout<<"Entered polynomial is: "<<endl;
	p1.display();
	
	double num;
	cout<<"Enter the number for which polynomial 1 is to be evaluated: "<<endl;
	cin>>num;
	cout<<"\nFor x="<<num<<"\nPolynomial= "<<p1.evaluate(num)<<endl<<endl;
	
	polynomial p2;
	
	cout<<"Polynomial 2:"<<endl;
	p2.getdata();
	cout<<"Entered polynomial is: "<<endl;
	p2.display();
	
	cout<<"Enter the number for which polynomial 2 is to be evaluated: "<<endl;
	cin>>num;
	cout<<"\nFor x="<<num<<"\nPolynomial= "<<p2.evaluate(num)<<endl<<endl;
	
	polynomial p3=p1.add(p2);
	cout<<"The addition of the two polynomials is "<<endl;
	p3.display();
	
	polynomial p4=p1.mult(p2);
	cout<<"The multiplication of the two polynomials is "<<endl;
	p4.display();
	
	return 0;
}
