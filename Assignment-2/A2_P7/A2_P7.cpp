#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

void mirror(struct Node* node)
{
    if (node == NULL)
        return;
    else
    {
        struct Node* temp;


        mirror(node->left);
        mirror(node->right);
        temp	 = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

void inOrder(struct Node* node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}



int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    cout << "Inorder traversal of the constructed tree \n";
    inOrder(root);

    mirror(root);

    cout << "\nInorder traversal of the mirror tree is \n";
    inOrder(root);
    cout<<endl;

    struct Node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    cout << "Inorder traversal of the constructed tree \n";
    inOrder(root2);
    mirror(root2);
    cout << "\nInorder traversal of the mirror tree is \n";
    inOrder(root2);
    cout << endl;

    struct Node *root3 = newNode(54);
    root3->left = newNode(51);
    root3->right = newNode(75);
    root3->left->left = newNode(49);
    root3->left->right = newNode(52);
    root3->right->left = newNode(74);
    root3->right->right = newNode(85);


    cout << "Inorder traversal of the constructed tree \n";
    inOrder(root3);


    mirror(root3);


    cout << "\nInorder traversal of the mirror tree is \n";
    inOrder(root3);
    cout<<endl;

    struct Node *root4 = newNode(5);
    root4->left = newNode(3);
    root4->right = newNode(7);
    root4->left->left = newNode(2);
    root4->left->right = newNode(4);
    root4->right->right = newNode(9);
    root4->right->right->right = newNode(10);
    root4->left->left->left=newNode(1);
    root4->right->right->left=newNode(8);

    cout << "Inorder traversal of the constructed tree \n";
    inOrder(root4);


    mirror(root4);

    cout << "\nInorder traversal of the mirror tree is \n";
    inOrder(root4);
    cout<<endl;

    struct Node *root5 = newNode(3);
    root5->left = newNode(9);
    root5->right = newNode(20);
    root5->right->left = newNode(15);
    root5->right->right = newNode(7);

    cout << "Inorder traversal of the constructed tree \n";
    inOrder(root5);


    mirror(root5);


    cout << "\nInorder traversal of the mirror tree is \n";
    inOrder(root5);

    return 0;

}
