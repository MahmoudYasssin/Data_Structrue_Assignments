#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
    Node(char d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int findIndex(char inOrder[], char val, int size_)
{
    int index = -1;
    for (int i = 0; i < size_; ++i)
    {
        if (inOrder[i] == val)
            return index = i;
    }
    return index;
}

Node *constructBinaryTree(char inOrder[], char preOrder[], int startIndex, int endIndex, int *preIndex, int size_)
{
    if (startIndex > endIndex || (*preIndex) >= size_)
        return nullptr;
    int rootIndex = findIndex(inOrder, preOrder[*preIndex], size_);
    Node *root = new Node(inOrder[rootIndex]);
    *preIndex = *preIndex + 1;



    root->left = constructBinaryTree(inOrder, preOrder, startIndex, rootIndex - 1, preIndex, size_);



    root->right = constructBinaryTree(inOrder, preOrder, rootIndex + 1, endIndex, preIndex, size_);



    return root;
}



void postOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;


    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data;
}
void printPostOrder(string preorder, string inorder)
{
    int preIndex = 0;
    int n1=preorder.length();
    int n2=inorder.length();
    char pre[n1+1];
    char in[n2+1];
    strcpy(pre, preorder.c_str());
    strcpy(in, inorder.c_str());

    Node *root = constructBinaryTree(in, pre, 0, n2 - 1, &preIndex, n1);

    postOrderTraversal(root);

}


int main()
{

    string preorder[]= {"ABFGC","HNMRSTABU","SWXNYML","YOUSSEF","ABDEFGCHIJK"};
    string inorder[] = {"FBGAC","MNRHATBSU","XNWYSLM","UOSYFES","EDFBGAHCJIK"};


    for (int i=0; i<5; i++)
    {
        printPostOrder(preorder[i],inorder[i]);
        cout <<endl;
    }
}
