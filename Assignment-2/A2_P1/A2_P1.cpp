#include <iostream>

using namespace std;
struct Node
{
    string data;
    Node *next;
};

class Stack
{
private:
    string path;
    Node *top=NULL;
public:
    ///////////////////////////////////////////////
    Stack(string P)
    {
        path=P;
    }
    void push(string S)
    {
        Node *new_node;
        new_node=new Node;
        new_node->data=S;
        new_node->next=top;
        top=new_node;
    }
    void pop()
    {
        Node *Per;
        Per=top;
        top=Per->next;
        delete(Per);
    }
    void display()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {

            Node *fina=top;

            while(fina!=NULL)
            {
                string a=fina->data;
                cout<<a;
                fina=fina->next;
            }
        }
    }
    bool isempty()
    {
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string Top()
    {
        return top->data;
    }
    void PrintStack()
    {
        if (isempty())
        {
            return;
        }
        else
        {
            string x =Top();
            pop();
            PrintStack();
            cout << x ;
            push(x);
        }
    }
    ///////////////////////////////////////////
    void canonical()
    {
        string A="";
        int x=0;
        push("/");
        for(int i=1;i<path.size();i++)
        {
            if(path[i]=='/')
            {
                if(A=="..")
                {
                    while(!isempty())
                    {
                        pop();
                    }
                    string l;
                    l=path[i];
                    push(l);
                }
                else if(A!="" && A!=".")
                {
                    push(A);
                }
                else if(A=="" && Top()!="/" && !isempty())
                {
                    push("/");
                }
            A="";
            }
            else
            {
                A+=path[i];
            }
        }
    }
};
int main()
{

    //Test Case 1
    Stack obj1("/hello/");
    obj1.canonical();
    obj1.PrintStack();

    cout<<endl;

   //Test Case 2
    Stack obj2("/../");
    obj2.canonical();
    obj2.PrintStack();

    cout<<endl;

    //Test Case 3
    Stack obj3("/home//foo/");
    obj3.canonical();
    obj3.PrintStack();

    cout<<endl;

    //Test Case 4
    Stack obj4("/a/./b/../../c/");
    obj4.canonical();
    obj4.PrintStack();

    cout<<endl;
}
