#include <iostream>

using namespace std;

struct TreeNode {
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

    Solution()
    {
        TreeNode *root=NULL;
    }
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(p==NULL && q==NULL)
        {
            return true;
        }
        if(p==NULL || q==NULL)
        {
            return false;
        }
        if(p->val==q->val)
        {
            if(isSameTree(q->left,p->left) && isSameTree(q->right,p->right))
            {
                return true;
            }
        }
        else
        {
            return false;
        }


    }
    TreeNode *NewNode(int num)
    {
        TreeNode *new_node=new TreeNode;
        new_node->val=num;
        new_node->left=NULL;
        new_node->right=NULL;
        return(new_node);
    }
};



int main()
{
    //Test Case 1  [1,2,3], q = [1,2,3]

    Solution obj1;
    TreeNode *Left_Tree=obj1.NewNode(1);
    Left_Tree->left=obj1.NewNode(2);
    Left_Tree->right=obj1.NewNode(3);


    TreeNode *Rigth_Tree=obj1.NewNode(1);
    Rigth_Tree->left=obj1.NewNode(2);
    Rigth_Tree->right=obj1.NewNode(3);

    if(obj1.isSameTree(Left_Tree,Rigth_Tree))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }


    //Test Case 2      Input: p = [1,2], q = [1,null,2]
    Solution obj2;
    TreeNode *Left=obj2.NewNode(1);
    Left->left=obj2.NewNode(2);


    TreeNode *Rigth=obj2.NewNode(1);
    Rigth->right=obj2.NewNode(2);
    Rigth->left=obj2.NewNode(NULL);


    if(obj2.isSameTree(Left,Rigth))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

    //Test Case 3    Input: p = [1,2,1], q = [1,1,2]

    Solution obj3;
    TreeNode *LT=obj3.NewNode(1);
    LT->left=obj3.NewNode(2);
    LT->right=obj3.NewNode(1);


    TreeNode *RT=obj3.NewNode(1);
    RT->left=obj3.NewNode(1);
    RT->right=obj3.NewNode(2);

    if(obj3.isSameTree(LT,RT))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }




}
