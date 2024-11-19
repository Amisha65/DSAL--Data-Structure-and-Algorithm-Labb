

#include <iostream>
#include <cmath>
#include <string.h>
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
        node *root;
        BST();
        node *newnode(int x);
        node* insert(node* p,int key);
        void inorder(node *);
        void preorder(node*);
        void postorder(node*);
        int serchr(node*,int key);
        void leafnode(node*);
        void printlevel(node*,int);
        int height(node*);
        void tree();
        void del(int x);
        node* del_node(node*,int);
        void mirror_tree(node*);

};

BST::BST()
{
    root=NULL;
}

node *BST::newnode(int x)
{
    node *p;
    p=new node;
    p->info=x;
    p->l=p->r=NULL;
    return p;
}

node* BST::insert(node *p,int key)
{
    if(p==NULL)
    {
        p=newnode(key);
    }
    else
    {
        if(key < p->info)
        {
            p->l=insert(p->l,key);
        }
        else if(key>p->info)
        {
            p->r=insert(p->r,key);
        }
        else if(key==p->info)
        {
            cout<<"Dublicate Key"<<endl;
        }
    }
    return p;
}

void BST::del(int x)
{
    del_node(root,x);
    cout<<"\nDeletede...\n";
}

node* BST::del_node(node* p, int x)
{
    node* temp;
    if(p==NULL)
    {
        cout<<"not Found";
        return p;
    }
    if(x<p->info)
    {
        p->l=del_node(p->l,x);
    }
    else if(x>p->info)
    {
        p->r=del_node(p->r,x);
    }
    else
    {
        if(p->l==NULL && p->r==NULL)
        {
            temp=p;
            delete temp;
            return p;
        }
        if(p->l!=NULL)
        {
            temp=p;
            p=p->l;
            delete temp;
            return p;
        }
        if(p->r!=NULL)
        {
            temp=p;
            p=p->r;
            delete temp;
            return p;
        }
        return NULL;
    }
}

void BST::inorder(node* p)
{
   if(p!=NULL)
   {
        inorder(p->l);
        cout<<p->info<<"\t";
        inorder(p->r);
   }
}

void BST::preorder(node* p)
{
    if(p!=NULL)
    {
        cout<<p->info<<"\t";
        preorder(p->l);
        preorder(p->r);
    }
}

void BST::postorder(node* p)
{
    if(p!=NULL)
    {
        postorder(p->l);
        postorder(p->r);
        cout<<p->info<<"\t";
    }
}

int BST::serchr(node* p,int key)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        if(key==p->info)
        {
            cout<<"Element is found";
            return 1;
        }
        else if(key<p->info)
        {
            return(serchr(p->l,key));
        }
        else if(key>p->info)
        {
            return(serchr(p->r,key));
        }
    }
}

void BST::leafnode(node* p)
{
    if(p==NULL)
    {
        return;
    }
    if(p->l==NULL && p->r==NULL)
    {
        cout<<p->info<<"\t";
    }
    if(p->l!=NULL)
    {
        leafnode(p->l);
    }
    if(p->r!=NULL)
    {
        leafnode(p->r);
    }
}

void BST::printlevel(node* p,int level)
{
    if(p==NULL)
    {
        return;
    }
    
    if(level==1)
    {
        cout<<p->info<<"\t";
    }
    else
    {
        printlevel(p->l,level-1);
        printlevel(p->r,level-1);
    }
}

int BST::height(node* p)
{
    if(p==NULL)
    {
        return 0;
    }
    else
    {
        int lheight=height(p->l);
        int rheight=height(p->r);
        
        if(lheight>rheight)
        {
            return(lheight+1);
        }
        else
        {
            return(rheight+1);
        }
    }
}

void BST::tree()
{
    int h=height(root);
    for(int i=0;i<h;i++)
    {
        printlevel(root,i);
        cout<<"  ";
    }
}

void BST::mirror_tree(node* p)
{
    node* temp;
    if(p==NULL)
    {
        return;
    }
    else
    {
        temp=p->l;
        p->l=p->r;
        p->r=temp;
        mirror_tree(p->l);
        mirror_tree(p->r);
    }
}

int main()
{
    BST b;
    b.root=b.insert(b.root,30);
    b.insert(b.root,20);
    b.insert(b.root,50);
    b.insert(b.root,40);
    b.insert(b.root,10);
    b.insert(b.root,60);
    b.insert(b.root,25);
    b.insert(b.root,70);
    
    b.mirror_tree(b.root);
    b.inorder(b.root);
    cout<<endl;
    b.preorder(b.root);
    cout<<endl;
    b.postorder(b.root);
    cout<<endl;
    b.serchr(b.root,20);
    cout<<endl;

    b.leafnode(b.root);
    cout<<endl;
    
    int y;
    cout<<"Enter to delete element: ";
    cin>>y;
    b.del(y);
    
    b.inorder(b.root);
    
    int x;
    cout<<"Enter the Level no.: ";
    cin>>x;
    b.printlevel(b.root,x);

    
    cout<<endl;
    cout<<b.height(b.root);
    
    cout<<endl;
    b.tree();
    
    cout<<endl;
}














