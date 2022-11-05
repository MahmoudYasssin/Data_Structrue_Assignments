#include<iostream>
using namespace std;
template <class T>
class Queue
{

public:
    T *arr;
    int Size ;

    Queue()
    {
        Size=0;
        arr = new T[1000];
    }

    Queue(T value, int initial_Size)
    {
        Size=initial_Size;
        arr = new T[initial_Size];
        for (int i=0; i<Size; i++)
            arr[i]=value;
    }


    T& Front()
    {
        return arr[0];
    }

    void push(T value)
    {
        arr[Size++]=value;
    }

    void pop()
    {
        for (int i=1 ; i<Size; i++)
            arr[i-1]=arr[i];
        Size--;
    }
    int get_Size()
    {
        return Size;
    }
    int &Back ()
    {
        return arr[Size-1];
    }
    bool Empty()
    {
        if (Size ==0 )
            return true;
        else
            return false;
    }
     ~Queue()
    {
        Size=0;
        delete []arr;
    }

};
int main()
{

    Queue<int> a;

    a.push(1);
    a.push(0);
    a.push(1);
    a.push(2);

   int counter=0;
    while(a.get_Size()!=0)
    {
        if ((a.Front()-1)==0)
           {
            a.pop();
        counter++;}
        else if(a.Front()==0)
        {
            a.pop();
        }
        else
        {
            a.push(a.Front()-1);
            a.pop();
            counter++;
        }

    }
    cout<< "time=" <<counter<<endl;




    return 0;
}
