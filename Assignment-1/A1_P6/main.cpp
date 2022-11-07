/*
Mahmoud yassin mahmoud
20200506

Ahmed hassan ahmed foad
20200010

Omar AbdEl-Aziz El-Sayed
20200831

youssef Mohammed galal
20200664

*/
#include <iostream>

using namespace std;

struct LinkedList
{
    string first_name;
    string last_name;
    string phone_number;
    LinkedList *next;
};
class PhoneDirectory
{
public:
    LinkedList *head;
    PhoneDirectory()
    {
        head=NULL;
    }
    void add_an_entry(string first,string last,string phone)
    {
        LinkedList *new_entry;
        new_entry=new LinkedList;

        new_entry->first_name=first;
        new_entry->last_name=last;
        new_entry->phone_number=phone;

        if(head==NULL)
        {
            head=new_entry;
            new_entry->next=NULL;

        }
        else
        {
            LinkedList *last=head;
            while(last->next!=NULL)
            {
                last=last->next;
            }
            last->next=new_entry;
            new_entry->next=NULL;
        }
    }
    ///
    void search_by_FirstName(string first)
    {
        LinkedList *temp=head;
        while(temp!=NULL)
        {
            if(temp->first_name==first)
             {
                 cout<<"First Name : "<<temp->first_name<<endl;
                 cout<<"Last Name : "<<temp->last_name<<endl;
                 cout<<"Phone Number : "<<temp->phone_number<<endl;
                 return;
             }
             temp=temp->next;
        }
        cout<<"Not exist"<<endl;
    }
    //
    void search_by_Phone(string phone)
    {
        LinkedList *temp;
        temp=head;
        while(temp!=NULL)
        {
            if(temp->phone_number==phone)
            {
                cout<<"First Name : "<<temp->first_name<<endl;
                cout<<"Last Name : "<<temp->last_name<<endl;
                cout<<"Phone Number : "<<temp->phone_number<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"Not exist"<<endl;

    }
    //
    void delete_entry(string first)
    {
        LinkedList *temp=head;
        if(temp->first_name==first)
        {
            head=temp->next;
            delete(temp);
        }
        else
        {
            LinkedList *cuurent,*perivous;
            cuurent=head;
            perivous=head;
            while(cuurent->first_name!=first)
            {
                perivous=cuurent;
                cuurent=cuurent->next;
            }
            perivous->next=cuurent->next;
            delete(cuurent);

        }

    }
    ////
    void display()
    {
        LinkedList *print;
        if(head==NULL)
        {
            cout<<"Empty"<<endl;
        }
        else
        {
            print=head;
            while(print!=NULL)
            {
                cout<<print->first_name<<'\t'<<print->last_name<<'\t'<<print->phone_number<<endl;
                print=print->next;
            }
        }
        cout<<endl;
    }

};
int main()
{

   cout<<"1. Add an entry to the directory"<<endl; //
   cout<<"2. Look up a phone number"<<endl; //
   cout<<"3. Look up by first name"<<endl; //
   cout<<"4. Delete an entry from the directory"<<endl; //
   cout<<"5. List All entries in phone directory"<<endl;
   cout<<"6. Exit form this program"<<endl; //
   cout<<"--------------------------------------"<<endl;


   PhoneDirectory obj;
   while(true)
   {
       int n=0;
       cout<<"Enter Your Choose : ";
       cin>>n;
       if(n==1)
       {
           string first1,last1,phone1;
           cout<<"Enter Your First Name : ";
           cin>>first1;
           cout<<"Enter Your Last Name : ";
           cin>>last1;
           cout<<"Enter Your Phone Number : ";
           cin>>phone1;
           obj.add_an_entry(first1,last1,phone1);
       }
       else if(n==2)
       {
           cout<<"Enter the phone number you want to search about : ";
           string phone2;
           cin>>phone2;
           obj.search_by_Phone(phone2);
       }
      else if(n==3)
      {
           string first3;
           cout<<"Enter the name you want to search about it : ";
           cin>>first3;
           obj.search_by_FirstName(first3);
      }
      else if(n==4)
      {
          string first4;
          cout<<"Enter the first name you want to delete it: ";
          cin>>first4;
          obj.delete_entry(first4);
      }
      else if(n==5)
      {
          obj.display();

      }
      else if(n==6)
      {
          break;
      }
   }

}


