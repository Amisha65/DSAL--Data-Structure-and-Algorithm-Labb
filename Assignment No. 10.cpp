#include<iostream>
using namespace std;
struct node
{
 int info;
 node *l;
 node *r;
};
class BST
{
 public:
 node* root;
 BST();
 node* Search(node *p, int key);
 node* newnode(int z);
 node* insert(node *p, int key);
 void Inorder(node *p);
 void Preorder(node *p);
 void Postorder(node *p);
 void Printleaf(node *p);
 int Height(node *p);
 void Printlw(node *p,int level);
 void PrintTree();
};
BST :: BST()
{
 root = NULL;
}
node* BST :: newnode(int z)
{
 node *x;
 x = new node;
 x -> info = z;
 x -> l = x -> r = NULL;
 return x;
}
node* BST :: insert(node *p , int key)
{
    if(p == NULL)
    p = newnode(key);
    else
    {
        if(key < p -> info)
        {
            p -> l = insert(p -> l,key); 
        }
         else if(key > p -> info)
        {
            p -> r = insert(p -> r,key);
        }
        else if (key == p -> info)
        {
            cout<<" Duplicate Key "<<endl;
        }
    }
     return p;
}
void BST :: Inorder(node *p)
{
 if(p != NULL)
 {
 Inorder(p -> l);
 cout<< p -> info << endl;
 Inorder(p -> r);
 }
}
void BST :: Preorder(node *p)
{
 if(p != NULL)
 {
 cout<< p -> info << endl;
 Preorder(p -> l);
 Preorder(p -> r);
 }
}
void BST :: Postorder(node *p)
{
 if(p != NULL)
 {
 Postorder(p -> l);
 Postorder(p -> r);
 cout<< p -> info << endl;
 }
}
node* BST :: Search(node *p, int key)
{
 if(p != NULL)
 {
 if(key == p -> info)
 {
 cout<<" Given Element Found "<<endl;
 return p;
 }
 else if(key < p -> info)
 {
 return(Search(p -> l,key));
 }
 else if(key > p -> info)
 {
 return(Search(p -> r,key));
 }
 else
 {
 cout<<" Given Element Not Found "<<endl;
 }
 }
}
void BST :: Printleaf(node *p)
{
 if(p == NULL)
 return;
 if(p -> l == NULL && p -> r == NULL)
 {
 cout<<p -> info << endl;
 return;
 }
 if(p -> l != NULL)
 {
 Printleaf(p -> l);
 }
 if(p -> r != NULL)
 {
 Printleaf(p -> r);
 }
}
int BST :: Height(node *p)
{
 if(p == NULL)
 return 0;
 else{
 int lHeight = Height(p -> l);
 int rHeight = Height(p -> r);
 if(lHeight > rHeight)
 return(lHeight + 1);
 else
 return(rHeight +1);
 }
}
void BST :: Printlw(node *p,int level)
{
 if(p == NULL)
 return;
 if(level == 1)
 {
 cout<< p -> info << " ";
 }
 else{
 Printlw(p -> l, level - 1);
 Printlw(p -> r, level - 1);
 }
}
void BST :: PrintTree()
{
 int h = Height(root);
 for(int i = 0; i <= h; i++)
 Printlw(root , i);
 cout<< " ";
}
int main()
{
    int ch;
    BST B;
    B.root=B.insert(B.root,10);
    B.insert(B.root,5);
    B.insert(B.root,20);
    B.insert(B.root,3);
    B.insert(B.root,15);
    B.insert(B.root,17);
    B.insert(B.root,19);
    B.insert(B.root,1);
    B.insert(B.root,4);
    while(1)
    {
        cout<<"*******************MENU*******************"<<endl;
        cout<<" Choose the operartion you want to perform \n 1.Traversals \n 2.Search \n 3.Print Leaf Node \n 4.Print Height of Tree \n 5.Print Level Wise Tree \n 6.Print Tree \n 7.Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<< " **** Inorder Traversal ****"<<endl;
                B.Inorder(B.root);
                cout<<endl;
                cout<<" **** Preorder Traversal ****"<<endl;
                B.Preorder(B.root);
                cout<<endl;
                cout<<" **** Postorder Traversal ****"<<endl;
                B.Postorder(B.root);
                cout<<endl;
                break;
            case 2: 
                B.Search(B.root, 20);
                break; 
            case 3:
                cout<<"The leaf node element are :"<<endl;
                B.Printleaf(B.root);
                cout<<endl;
                break;
            case 4:
                cout<<" Height of the Tree Is : "<<B.Height(B.root);
                cout<<endl;
                break;
            case 5:
                B.Printlw(B.root,4);
                cout<<endl;
                break;
            case 6:
                B.PrintTree();
                cout<<endl;
                break;
        }
    }
}