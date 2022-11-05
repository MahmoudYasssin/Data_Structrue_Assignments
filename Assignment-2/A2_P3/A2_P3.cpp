#include <bits/stdc++.h>
using namespace std;
template <class T>
class Queue
{
private:
    T *arr;
    int Size ;
public:
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
    ~Queue()
    {
        Size=0;
        delete []arr;
    }

    T& front_Q()
    {
        return arr[0];
    }

    void push_Q(T value)
    {
        arr[Size++]=value;
    }

    void pop_Q()
    {
        for (int i=1 ; i<Size; i++)
            arr[i-1]=arr[i];
        Size--;
    }
    int get_Size_Q()
    {
        return Size;
    }
    bool empty_Q()
    {
        if(Size==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    friend class x;
};
class myStack
{
private:
    Queue<int> myqueue;
    Queue<int> myqueue2 ;
public :

    int top_S()
    {
        if (myqueue.empty_Q())
        {
            return 0 ;
        }
        else
        {
            return (myqueue.front_Q());
        }
    }
    void pop_S()
    {
        myqueue.pop_Q();
    }
    void push_S(int num)
    {
        myqueue2.push_Q(num);
        while (! myqueue.empty_Q())
        {
            myqueue2.push_Q(myqueue.front_Q());
            myqueue.pop_Q();
        }
        swap(myqueue,myqueue2);
    }
};

int main()
{
    myStack s;
    s.push_S(1);
    s.push_S(2);
    s.push_S(3);
    s.push_S(4);
    s.push_S(5);
    cout<<s.top_S()<<endl;
    s.pop_S();
    cout<<s.top_S()<<endl;
    return 0;
}

