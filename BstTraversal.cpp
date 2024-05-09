#include<iostream>
using namespace std;

class Node {
    public:
    int data ;
    Node *left , *right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

void PreOrder(Node *root)
{
    if(root==NULL)
    return;
    // Node print 
    cout<<root->data<<" ";
    //left
    PreOrder(root->left);
    //right 
    PreOrder(root->right);

}

void InOrder(Node *root)
{
    if(root==NULL)
    return ;
    //left
    InOrder(root->left);
    //print Node
    cout<<root->data<<" ";
    //right 
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if(root==NULL)
    return ;
    //left
    PostOrder(root->left);
    //right
    PostOrder(root->right);
    //print Node 
    cout<<root->data<<" ";
}


Node * BinaryTree()
{
    int x;
    cin>>x;
    if (x==-1)
     return NULL;

     Node *temp = new Node(x);
     //left side create 
     cout<<"Enter the left chid of " <<x<<" : " ;
     temp->left=BinaryTree();
     //right side create
     cout<<"Enter the right chid of " <<x<<" : " ;
     temp->right=BinaryTree();
     return temp;
    
}

int main()
{
    cout<<"Enter the root node :";
    Node *root;
    root = BinaryTree();

    cout<<"preOrder : ";
    PreOrder(root);
    cout<<endl;
    cout<<"InOrder : ";
    InOrder(root);
    cout<<endl;
    cout<<"PostOrder : ";
    PostOrder(root);
}