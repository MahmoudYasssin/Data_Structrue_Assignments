#include <iostream>

using namespace std;
#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node *right, *left;

    node (int val)
    {
        left=right=NULL;
        data=val;
    }
};
class BTS
{
public:
    node *root;

    BTS()
    {
        root = NULL;
    }
    node* insert_(int item, node* pnode)
    {
        if (pnode ==NULL)
        {
            node *newnode = new node(item);
            pnode =newnode;
        }
        else if(item <pnode->data)
        {
           pnode->left= insert_(item,pnode->left);
        }
        else
        {
           pnode->right=insert_(item,pnode->right);
        }
        return pnode;
    }
    void insert_(int item)
    {
        root=insert_(item,root);
    }
    void mirror(node *&pnode)
    {
        if(pnode == NULL)
        {
            return ;
        }
        else
        {
            node *temp;
            mirror(pnode->left);
            mirror(pnode->right);
            temp = pnode->left;
            pnode->left=pnode->right;
            pnode->right=temp;
        }
    }
    bool isSame(node *p1,node *p2)
    {
        if (p1==NULL && p2==NULL)
        {
            return true;
        }
        if (p1!=NULL&&p2!=NULL&&isSame(p1->left,p2->left)&&isSame(p1->right,p2->right))
        {
            return true;
        }
        return false;
    }
    void isFoldable(node *pnode)
    {
        if(pnode==NULL)
        {
            cout<<"foldable"<<endl;
            return ;
        }
        mirror(pnode->left);

        if ( isSame(pnode->left,pnode->right))
            cout<<"foldable"<<endl;
        else
         cout<<"not foldable"<<endl;
        mirror(pnode->left);

    }
    void preorder(node *x)
    {
        if (x==NULL)
            return;
        cout <<x->data<<" ";
        preorder(x->left);
        preorder(x->right);
    }
};

int main()
{
    BTS btree1;

    btree1.insert_(45);
	btree1.insert_(20);
	btree1.insert_(70);
	btree1.insert_(15);
	btree1.insert_(25);
	btree1.insert_(55);
	btree1.insert_(75);
	btree1.insert_(85);
	btree1.insert_(10);
	cout <<"tree 1 is: ";
    btree1.isFoldable(btree1.root);
    cout<<"expected : foldable"<<endl;

     BTS btree2;

    btree2.insert_(16);
	btree2.insert_(14);
	btree2.insert_(72);
	btree2.insert_(46);
	btree2.insert_(4);
	btree2.insert_(76);
	btree2.insert_(75);
	btree2.insert_(9);
	btree2.insert_(10);
	cout <<"tree 2 is: ";
    btree2.isFoldable(btree2.root);
    cout<<"expected : not foldable"<<endl;
     BTS btree3;

    btree3.insert_(3);
	btree3.insert_(1);
	btree3.insert_(5);
	btree3.insert_(2);
	btree3.insert_(4);

	cout <<"tree 3 is: ";
    btree3.isFoldable(btree3.root);
    cout<<"expected : foldable"<<endl;
     BTS btree4;

    btree4.insert_(4);
	btree4.insert_(5);
	btree4.insert_(6);
	btree4.insert_(2);
	btree4.insert_(1);
	btree4.insert_(3);
	cout <<"tree 4 is: ";
    btree4.isFoldable(btree4.root);
    cout<<"expected : notfoldable"<<endl;
     BTS btree5;

    btree5.insert_(6);
	btree5.insert_(4);
	btree5.insert_(8);
	btree5.insert_(2);
	btree5.insert_(1);
	btree5.insert_(7);
	btree5.insert_(10);
	btree5.insert_(3);
	btree5.insert_(5);
	btree5.insert_(11);
	btree5.insert_(9);
	cout <<"tree 5 is: ";
    btree5.isFoldable(btree5.root);
    cout<<"expected : foldable"<<endl;
}
