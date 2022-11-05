#include <iostream>

using namespace std;

struct binarytreenode
{
    char value;
    binarytreenode* left=NULL;
    binarytreenode* right=NULL;
};

struct stacknode
{
    binarytreenode* treenode=NULL;
    stacknode* next=NULL;
};

stacknode *top= NULL;

void push(binarytreenode* value)
{
    stacknode* new_node= new stacknode;
    new_node->treenode=value;
    new_node->next=top;
    top=new_node;
}

binarytreenode* pop()
{
    binarytreenode *x;
    stacknode* current=top;
    top=current->next;
    x=current->treenode;
    delete current;
    return x;
}

binarytreenode* peek()
{
    return top->treenode;
}

void empty_tree()
{
    top=NULL;
}

int chartoint(string s)
{
    int num = 0;

    if(s[0]!='-')
        for (int i=0; i<s.length(); i++)
            num = num*10 + (int(s[i])-48);
    {
        for (int i=1; i<s.length(); i++)
            num = num*10 + (int(s[i])-48);
        num = num*-1;
    }

    return num;
}

bool isOperand(char c)
{
    return isdigit(c);
}

void inorder(binarytreenode* x)
    {
        if (x == NULL)
            return;
        else {
            inorder(x->left);
            cout << x->value << "  ";
            inorder(x->right);
        }
    }

void create(string s)
{
    binarytreenode *x, *y, *z;
    int len = s.length();
    z = new binarytreenode;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*'
                || s[i] == '/' || s[i] == '^')
        {

            z->value=s[i];
            x = pop();
            y = pop();
            z->left = y;
            z->right = x;
            push(z);
        }
        else
        {
            z = new binarytreenode;
            z->value=s[i];
            push(z);
        }

    }
    inorder(z);
}



int main()
{
    string f="+3*4/82";
    create(f);

    return 0;
}
