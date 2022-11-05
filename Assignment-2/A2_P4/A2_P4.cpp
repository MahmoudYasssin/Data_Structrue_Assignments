#include <iostream>
#include <string>
using namespace std;
#include <bits/stdc++.h>

class TreeNode
{
public:

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};
class Solution
{
public:

    TreeNode *root=NULL;
    bool isSymmetric(TreeNode *root)
    {
        return root==NULL||check(root->left,root->right);
    }
    bool check(TreeNode *L,TreeNode *R)
    {
       if(L==NULL && R==NULL)
       {
           return true;
       }
       if(L==NULL || R==NULL)
       {
           return false;
       }
       if(L->val==R->val)
       {
           if(check(L->left,R->right)&&check(L->right,R->left))
           {
               return true;
           }
       }
       else
       {
           return false;
       }
    }
    TreeNode* newNode(int data)
    {
        TreeNode* node =new TreeNode;
        node->val = data;
        node->left =NULL;
        node->right = NULL;
        return (node);
    }
};


int main()
{
    // Test Case 1
    Solution obj;
    TreeNode* root = obj.newNode(1);
    root->left = obj.newNode(2);
    root->right = obj.newNode(2);
    root->left->left = obj.newNode(3);
    root->left->right = obj.newNode(4);
    root->right->left = obj.newNode(4);
    root->right->right = obj.newNode(3);
    if(obj.isSymmetric(root))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

    // Test Case 2
    Solution obj2;
    TreeNode* root2 =NULL;
    root2=obj2.newNode(4);
    root2->left = obj2.newNode(2);
    root2->right = obj2.newNode(2);
    root2->left->right = obj2.newNode(7);
    root2->left->left = obj2.newNode(5);
    root2->right->left = obj2.newNode(5);
    root2->right->right = obj2.newNode(7);
    if(obj2.isSymmetric(root2))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}
