#include<iostream>
using namespace std;
#define max for(int i=0;i<size;i++)\
			cout<<a[i]<<"\t";
#define topFive\
    cout<<"The Top 5 scores are"<<endl;\
	 for(int i=size-1;i>=size-5;i--)\
			cout<<a[i]<<"\t"; 
			
void merge(float*, int , int , int ); 
void bubbleSort(float a[],int size)
{
	int i, j;  
    for (i = 0; i < size-1; i++)      
    {
    	for (j = 0; j < size-i-1; j++)  
     	{   if (a[j] > a[j+1])  
     	   {
     	   		float temp = a[j];
     	   		a[j]=a[j+1];  
    			a[j+1]=temp;
    		}
    	}
    	cout<<"Pass "<<i+1<<endl;
    	max
    	cout<<endl;
    }   
	topFive
}

void selectionSort(float a[],int size)
{
	int min_index;
			for(int i=0;i<size;i++)
			{
				min_index=i;
				int j=0;
				for(j=i+1;j<size;j++)
				{
					if(a[j]<a[min_index])
						min_index=j;
				}
				if(i!=min_index)
				{
					float temp=a[i];
					a[i]=a[min_index];
					a[min_index]=temp;
					cout<<"Pass "<<i+1<<endl;
    				max
				}
			}
		topFive
}
void mergeSort(float a[],int l,int r,int size,int z=0)
{

	if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(a, l, m,size,z); 
        mergeSort(a, m+1, r,size,z); 
  
  		merge(a,l,m,r);
  		cout<<endl;
		max
  		
    } 
   
}
void merge(float a[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    
    float L[n1], R[n2]; 
    
    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
        
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
int main()
{

	float *a;
	char ch;
	char choice;
	do 
	{
		cout<<"Enter the Size of Array you want to sort";
		int size;
		cin>>size;
		a=new float [size];
		cout<<"Enter Percentage of "<<size<<" students:"<<endl;
		for(int i=0;i<size;i++)
			cin>>a[i];
		cout<<"MENU:\n1.BUBBLE SORT\n2.SELECTION SORT\n3.MERGE SORT"<<endl;
		cin>>ch;
		switch(ch)
		{
			case '1':
					cout<<"BUBBLE SORT:"<<endl;
					bubbleSort(a,size);
					break;
			case '2':
					cout<<"SELECTION SORT:"<<endl;
					selectionSort(a,size);
					break;
			case '3':
					cout<<"MERGE SORT:"<<endl;
					mergeSort(a,0,size-1,size);
			default:
				cout<<"Enter from available choices only!!"<<endl;
				break;	
		}
		
		cout<<"\nDo want to try another set of elements?:\t";
		cin>>choice;
	}while (choice=='y'||choice=='Y'); 
	return 0;
}
/*
OUTPUT:
unix@unix-dx2480-MT:~$ cd SEA19
unix@unix-dx2480-MT:~/SEA19$ g++ sort.cpp
unix@unix-dx2480-MT:~/SEA19$ ./a.out
Enter the Size of Array you want to sort 5
Enter Percentage of 5 students:
93.50
60.70
50.54
60.52
10.39
MENU:
1.BUBBLE SORT
2.SELECTION SORT
3.MERGE SORT
1
BUBBLE SORT:
Pass 1
60.7	50.54	60.52	10.39	93.5	
Pass 2
50.54	60.52	10.39	60.7	93.5	
Pass 3
50.54	10.39	60.52	60.7	93.5	
Pass 4
10.39	50.54	60.52	60.7	93.5	
The Top 5 scores are
93.5	60.7	60.52	50.54	10.39	Do want to try another set of elements?:y
Enter the Size of Array you want to sort 5
Enter Percentage of 5 students:
93.5060.70
^Z
[1]+  Stopped                 ./a.out
unix@unix-dx2480-MT:~/SEA19$ clear

unix@unix-dx2480-MT:~/SEA19$ g++ sort.cpp
unix@unix-dx2480-MT:~/SEA19$ ./a.out
Enter the Size of Array you want to sort 5
Enter Percentage of 5 students:
93.50
50.99
30.40
70.60
19.54
MENU:
1.BUBBLE SORT
2.SELECTION SORT
3.MERGE SORT
1
BUBBLE SORT:
Pass 1
50.99	30.4	70.6	19.54	93.5	
Pass 2
30.4	50.99	19.54	70.6	93.5	
Pass 3
30.4	19.54	50.99	70.6	93.5	
Pass 4
19.54	30.4	50.99	70.6	93.5	
The Top 5 scores are
93.5	70.6	50.99	30.4	19.54	
Do want to try another set of elements?:	y
Enter the Size of Array you want to sort 5
Enter Percentage of 5 students:
93.50
50.99
30.40
70.60
19.54
MENU:
1.BUBBLE SORT
2.SELECTION SORT
3.MERGE SORT
2
SELECTION SORT:
Pass 1
19.54	50.99	30.4	70.6	93.5	Pass 2
19.54	30.4	50.99	70.6	93.5	The Top 5 scores are
93.5	70.6	50.99	30.4	19.54	
Do want to try another set of elements?:	y
Enter the Size of Array you want to sort 5
Enter Percentage of 5 students:
93.50
50.99
30.40
70.60
19.54
MENU:
1.BUBBLE SORT
2.SELECTION SORT
3.MERGE SORT
3
MERGE SORT:

50.99	93.5	30.4	70.6	19.54	
30.4	50.99	93.5	70.6	19.54	
30.4	50.99	93.5	19.54	70.6	
19.54	30.4	50.99	70.6	93.5	Enter from available choices only!!

Do want to try another set of elements?:	 n
unix@unix-dx2480-MT:~/SEA19$*/
