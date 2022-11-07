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
#include<bits/stdc++.h>
using namespace std;
class StudentName
{
private:
    string full_name;
    vector<string>X;

public:

    StudentName (string NAME)
    {
        full_name=NAME;
        int number_of_space=0;
        int space_index=0;
        for(int i=0;i<full_name.size();i++)
        {
            if(full_name[i]==' ')
            {
                number_of_space++;
                space_index=i;
            }
        }
        if(number_of_space==0)
        {
            X.push_back(full_name);
            X.push_back(full_name);
            X.push_back(full_name);
        }
        else if(number_of_space==1)
        {
            string sub_string1 =  full_name.substr(0,space_index);
            string sub_string2 =  full_name.substr(space_index+1,full_name.size()-1);
            X.push_back(sub_string1);
            X.push_back(sub_string2);
            X.push_back(sub_string2);
        }
        else if(number_of_space>=2)
        {
            string g=" ";
            for(int i=0;i<full_name.size();i++)
            {
                if(full_name[i]!=' ')
                {
                    g+=full_name[i];
                }
                else
                {
                    X.push_back(g);
                    g=" ";
                }
                if(i==full_name.size()-1)
                {

                    X.push_back(g);
                    g=" ";
                }
            }
        }
    }
    bool replace(int i,int j)
    {
        if(i>X.size()  || j>X.size() )
        {
            return false;
        }
        else
        {
             string temp ;
             temp = X[i-1];
             X[i-1]=X[j-1];
             X[j-1]=temp ;
             return true;
        }
    }
    void print()
    {
        for(int i=0;i<X.size();i++)
        {
            cout<<'('<<i+1<<')'<< X[i]<<endl;
        }
    }
};


int main()
{

   StudentName test1("Mahmoud Yassin");
    if(test1.replace(3,1))
    {
            cout<<"True"<<endl;
            test1.print();
    }
    else
    {
     cout<<"False"<<endl;
     test1.print();
    }
    cout<<"----------------------"<<endl;

    StudentName test2("Mahmoud Yassin");
     if(test2.replace(4,1))
    {
            cout<<"True"<<endl;
            test2.print();
    }
    else
    {
     cout<<"False"<<endl;
     test2.print();
    }
    cout<<"----------------------"<<endl;

     StudentName test3("Mahmoud" );
     if(test3.replace(5,10))
     {
            cout<<"True"<<endl;
            test3.print();
     }
    else
    {
     cout<<"False"<<endl;
     test3.print();
    }
    cout<<"----------------------"<<endl;

    StudentName test4("Mahmoud Yassin Ali Omar" );
     if(test4.replace(1,5))
     {
            cout<<"True"<<endl;
            test4.print();
     }
    else
    {
      cout<<"False"<<endl;
      test4.print();
    }
    cout<<"----------------------"<<endl;

    StudentName test5("Ahmed Mahmoud Yassin Omar Ali" );
    if(test5.replace(2,4))
    {
            cout<<"True"<<endl;
            test5.print();
    }
    else
    {
     cout<<"False"<<endl;
     test5.print();
    }
}

