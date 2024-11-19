#include <iostream>
using namespace std;

struct node
{
    int info,lf,rf;
    node *l,*r;
};

class TBT
{
    node* head,*root;
    public:
        TBT()
        {
            root=NULL;
        }
        void create();
        void inorder();
        void preorder();
};

void TBT::create()
{
    node *t,*p;
    int n,d;
    
    head=new node;
    head->l=head->r=head;
    head->lf=head->rf=0;
    
    cout<<"Enter the Nodes: ";
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cout<<"Enter DATA: ";
        cin>>d;
        
        t=new node;
        t->info=d;
        t->l=t->r=t;
        t->rf=t->lf=0;
        
        if(root==NULL)
        {
            root=t;
            head->l=root;
            root->l=head;
            root->r=head;
        }
        else
        {
            p=root;
            while(1)
            {
            if(t->info<p->info)
            {
                if(p->lf==0)
                {
                    t->l=p->l;
                    p->l=t;
                    p->lf=1;
                    t->r=p;
                    break;
                }
                else
                {
                    p=p->l;
                }
            }
            else
            {
                if(p->rf==0)
                {
                    t->r=p->r;
                    p->r=t;
                    p->rf=1;
                    t->l=p;
                    break;
                }
                else
                {
                    p=p->r;
                }
            }
           }
            
        }
    }
}

void TBT::inorder()
{
    cout<<"\nInorder Treversal"<<endl;
    node *p=root;
    do
    {
        while(p->lf==1)
        {
            p=p->l;
            cout<<p->info<<"\t";
        }
        cout<<p->info<<"\t";
        while(p->rf==0)
        {
            p=p->r;
            if(p==head)
            {
                return;
            }
        }
        p=p->r;
    }while(p!=head);
}

void TBT::preorder()
{
    cout<<"\nInorder Treversal"<<endl;
    node *p=root;
    do
    {
        while(p->lf==1)
        {
            cout<<p->info<<"\t";
            p=p->l;
        }
        cout<<p->info<<"\t";
        while(p->rf==0)
        {
            p=p->r;
            if(p==head)
            return;
        }
        p=p->r;
    }while(p!=head);
}

int main()
{
    TBT t;
    t.create();
    t.preorder();
    t.inorder();
}

