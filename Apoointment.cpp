/*
Pr. No		: 05
Title 		: Write C++ program for storing appointment schedule for day. Appointments are booked
		  randomly using linked list. Set start and end time and min and max duration for visit slot.
		  Write functions for-
		    a) Display free slots
		    b) Book appointment
		    c) Cancel appointment ( check validity, time bounds, availability etc)
		    d) Sort list based on time
		    e) Sort list based on time using pointer manipulation
*/
/*NAME: ADITYA GADE 	Class: SE-A(COMP)	Date of creation:22-08-2018		Last Updated: 28-08-19*/



#include<iostream>
using namespace std;

int size;	// No of Nodes or Appointments

class node	// Node Structure of each Appointment
{
    int startTime;
    int endTime;
    int flag;
    node *next;
  public:
    friend class Schedule;
};


class Schedule
{ 
  node* head;
  public:
        void create()           //Function Definition to create Appointment Schedule
        {
            int i;
            node *temp, *last;
            
            head = NULL;
            
            cout<<"\n\n\t How many Appointment Slots: ";
            cin>>size;
            
            for(i=0; i<size; i++)
            {
               temp = new(node);         // Step 1: Dynamic Memory Allocation
               
               cout<<"\n\n\t Enter Start Time: ";   // Step 2: Assign Data & Address
               cin>>temp->startTime; 
               cout<<"\n\t Enter End Time: ";
               cin>>temp->endTime;
               temp->flag = 0;
               temp->next = NULL;
               
               if(head == NULL)
               {
                  head = temp;
                  last = head;
               }
               else
               {
                  last->next = temp;
                  last = last->next;
               }
               
            }
        }

           
        void display()          //Function Definition to Display Appointment Schedule         
        {
           int cnt = 1;
           node *temp;
           
           cout<<"\n\n\t ****Appointment Schdule****";
           cout<<"\n\n\t Srno.\tStart\tEnd\tMin_Dur\tMax_Dur\tStatus";        
           
           temp = head;
           while(temp != NULL)
           {
              cout<<"\n\n\t "<<cnt;
              cout<<"\t "<<temp->startTime;
              cout<<"\t "<<temp->endTime;

              if(temp->flag)
                 cout<<"\t-Booked-";                        
              else
                 cout<<"\t--Free--";         
                 
              temp = temp->next; 
              cnt++;  
           }
        }


        void book()              //Function Definition to Book Appointment
        {
            int start;
            node *temp;

            cout<<"\n\n\t Please enter Appointment time: ";
            cin>>start;
         
           temp = head;

           while(temp != NULL)
           {
              if(start == temp->startTime)
              {
                 if(temp->flag == 0)
                 {
                    cout<<"\n\n\t Appointment Slot is Booked!!!";
                    temp->flag = 1;
                 }
                 else
                    cout<<"\n\n\t Appointment Slot is not Available!!!";
              }

              temp = temp->next; 
           }

        }
              
                 

        void cancel()            //Function Defination to Cancel Appointment
        {
            int start;
            node *temp;

            cout<<"\n\n\t Please enter Appointment time to Cancel: ";
            cin>>start;
         
           temp = head;

           while(temp != NULL)
           {
              if(start == temp->startTime)
              {
                 if(temp->flag == 1)
                 {
                    cout<<"\n\n\t Your Appointment Slot is Canceled!!!";
                    temp->flag = 0;
                 }
                 else
                    cout<<"\n\n\t Your Appointment was not Booked!!!";
              }

              temp = temp->next; 
           }
        }


        void sort()              //Function Definition to Sort Appointments
        {
           int i,j,val;
           node *temp;


           for(i=0; i < size-1; i++)  
           {
               temp = head;
               while(temp->next != NULL)
               { 
                  if(temp->startTime > temp->next->startTime)
                  {
                      val = temp->startTime;
                temp->startTime = temp->next->startTime;
                temp->next->startTime = val;

                      val = temp->endTime;
                temp->endTime = temp->next->endTime;
                temp->next->endTime = val;
                  }
                  temp = temp->next;
               }   
           }

           cout<<"\n\n\t The Appointments got Sorted!!!";

        }

	
};


int main()
{
   int ch;
   char ans;
  Schedule A;  
   do
   {    
      cout<<"\n\n *** Menu ***";
      cout<<"\n 1. Create Appointment Schedule";
      cout<<"\n 2. Display Free Slots";
      cout<<"\n 3. Book an Appointment";
      cout<<"\n 4. Cancel an Appointment";
      cout<<"\n 5. Sort slots based on Time";

      
      cout<<"\n\n\t Enter your choice: ";                        
      cin>>ch;
      
      switch(ch)
      {
         case 1: A.create();
         	 break;
         	 
         case 2: A.display();
         	 break;         	 
         	 
         case 3: A.book();
         	 break;
         	 
         case 4: A.cancel();
         	 break;

         case 5: A.sort();
         	 break;
         	 
         default: cout<<"\n\t Wrong choice!!!";
	          	 
      }
      
      cout<<"\n\n\t Do you want to continue? (y/n) : ";
      cin>>ans;
   }while(ans == 'y');
   
}




