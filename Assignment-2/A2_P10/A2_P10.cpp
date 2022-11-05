#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

Node *createTree(int data)
{
    Node * new_Node = new Node;
    new_Node->left = NULL;
    new_Node->right = NULL;
    new_Node->data = data;
    return new_Node;
}


Node * insert_node(Node *root, int value)
{
    if (root == NULL)
    {
        return createTree(value);
    }

    if (root->data > value)
    {
        root->left = insert_node(root->left, value);
    }

    else if (root->data < value)
    {
        root->right = insert_node(root->right, value);
    }

    return root;
}


int k_sum(Node *root, int k, int &cnt)
{
    if (root == NULL)
    {
        return 0;
    }
    if (cnt > k)
    {
        return 0;
    }

    int result = k_sum(root->left, k, cnt);
    if (cnt >= k)
    {
        return result;
    }

    result += root->data;

    cnt++;
    if (cnt >= k)
    {
        return result;
    }

    return result + k_sum(root->right, k, cnt);
}

int sum(Node *root, int k)
{
    int cnt = 0;
    k_sum(root, k, cnt);
}

void deleteTree(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


int main()
{
    //test case 1
    Node *root = NULL;
    root = insert_node(root, 20);
    root = insert_node(root, 8);
    root = insert_node(root, 4);
    root = insert_node(root, 12);
    root = insert_node(root, 10);
    root = insert_node(root, 14);
    root = insert_node(root, 22);
    int k=3;
    cout<<"kth sum is "<<sum(root,k)<<endl;
    deleteTree(root);

    //test case 2
    Node *root1=NULL;
    root1 = insert_node(root1, 73);
    root1 = insert_node(root1, 156);
    root1 = insert_node(root1, 7);
    root1 = insert_node(root1, 980);
    root1 = insert_node(root1, 130);
    root1 = insert_node(root1, 114);
    root1 = insert_node(root1, 219);
    int j=5;
    cout<<"kth sum is "<<sum(root1,j)<<endl;
    deleteTree(root1);

    //test case 3

    Node* root2=NULL;
    root2 = insert_node(root2, 4);
    root2 = insert_node(root2, 5);
    root2 = insert_node(root2, 2);
    root2 = insert_node(root2, 1);
    root2 = insert_node(root2, 3);
    root2 = insert_node(root2, 7);
    root2 = insert_node(root2, 6);
    root2 = insert_node(root2, 9);
    root2 = insert_node(root2, 8);
    int l=4;
    cout<<"kth sum is "<<sum(root2,l)<<endl;
    deleteTree(root2);

    //test case 4

    Node* root3=NULL;
    root3 = insert_node(root3, 645);
    root3 = insert_node(root3, 511);
    root3 = insert_node(root3, 222);
    root3 = insert_node(root3, 124);
    int m=1;
    cout<<"kth sum is "<<sum(root3,m)<<endl;
    deleteTree(root3);


    //test case 5

    Node* root4=NULL;
    root4 = insert_node(root4, 6312);
    root4 = insert_node(root4, 514);
    root4 = insert_node(root4, 22);
    root4 = insert_node(root4, 14);
    root4 = insert_node(root4, 445);
    root4 = insert_node(root4, 511);
    root4 = insert_node(root4, 222);
    root4 = insert_node(root4, 124);
    root4 = insert_node(root4, 64);
    root4 = insert_node(root4, 51);
    root4 = insert_node(root4, 202);
    root4 = insert_node(root4, 129);
    root4 = insert_node(root4, 678);
    root4 = insert_node(root4, 50);
    root4 = insert_node(root4, 212);
    root4 = insert_node(root4, 123);
    int n=7;
    cout<<"kth sum is "<<sum(root4,n)<<endl;
    deleteTree(root4);

    return 0;
}
