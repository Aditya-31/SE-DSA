#include<iostream>
#include<string>
#define max 5
using namespace std;

typedef struct search
{
public:
    string name[max];
    int cno[max];

};

void sort_contacts(search &ob)
{

    for(int i=0; i<max; i++)
    {
        int minindex=i;
        for(int j=i+1; j<max; j++)
        {
            if(ob.name[j]<ob.name[minindex])
                minindex=j;
        }
        if(minindex!=i)
        {
            string temp=ob.name[minindex];
            ob.name[minindex]=ob.name[i];
            ob.name[i]=temp;
            int tempno=ob.cno[minindex];
            ob.cno[minindex]=ob.cno[i];
            ob.cno[i]=tempno;
        }
    }
}

int search_contact(search &ob,string sname)
{


    int low=0,high=max-1,mid=0,flag=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(ob.name[mid]==sname)
        {
            flag=1;
            return mid;
        }
        else if(sname<ob.name[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(flag==0)
        return -1;
}

int main()
{

    search s1;
    string sname;
    cout<<"ENTER THE CONTACT DETAILS\n";
    for(int i=0; i<max; i++)
    {
        cout<<"ENTER NAME:-";
        cin>>s1.name[i];
        cout<<"ENTER CONTACT:-";
        cin>>s1.cno[i];
    }

    sort_contacts(s1);
    cout<<"SORTED ARRAY IS\n";
    for(int i=0; i<max; i++)
    {
        cout<<"NAME:-"<<s1.name[i]<<endl;
        cout<<"CONTACT:-"<<s1.cno[i]<<endl;
    }


    cout<<"ENTER THE NAME YOU WANT TO SEARCH\n";
    cin>>sname;

    int pos=search_contact(s1,sname);

    if(pos!=-1)
    {
        cout<<"DETAILS ARE\n";
        cout<<"NAME:-"<<s1.name[pos]<<endl;
        cout<<"CONTACT:-"<<s1.cno[pos]<<endl;
    }
    else
        cout<<"CONTACT SEARCHED NOT FOUND\n";

    return 0;
}
