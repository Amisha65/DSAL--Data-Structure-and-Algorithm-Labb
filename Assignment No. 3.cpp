#include <iostream>
#define SIZE 20
#include <string.h>
using namespace std;

struct node
{
    char info;
    node *prev;
    node *next;
};

class stack
{
    node *data[SIZE];
    int top;
    public:
        stack();
        void push(node *);
        node *pop();
        int gettop();
        int isempty();
};

stack::stack()
{
    top=-1;
}

void stack::push(node *p)
{
    data[++top]=p;
}

node *stack::pop()
{
    return data[top--];
}

int stack::gettop()
{
    return top;
}

int stack::isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

class tree
{
    char postf[SIZE];
    public:
        node *root;
        void create();
        void rc_in(node *);
        void rc_pre(node *);
        void rc_post(node *);
        void nrc_in(node *p);
        void nrc_pre(node *);
        void nrc_post(node *);
};

void tree::create()
{
    node *p;
    stack s;
    cout<<"Enter the Postfix expression: ";
    cin>>postf;

    for(int i=0;i<strlen(postf);i++)
    {
        p=new node;
        p->info=postf[i];
        p->next=p->prev=NULL;
        if(isalnum(postf[i]))
        {
            s.push(p);
        }
        else
        {
            p->next=s.pop();
            p->prev=s.pop();
            s.push(p);
        }
    }
    root=s.pop();
}

void tree::rc_in(node *p)
{
    if(p!=NULL)
    {
        rc_in(p->prev);
        cout<<p->info;
        rc_in(p->next);
    }
}

void tree::rc_pre(node *p)
{
    if(p!=NULL)
    {
        cout<<p->info;
        rc_pre(p->prev);
        rc_pre(p->next);
    }
}

void tree::rc_post(node *p)
{   
    if(p!=NULL)
    {
        rc_post(p->prev);
        rc_post(p->next);
        cout<<p->info;
    }
}

void tree::nrc_in(node *p)
{
    stack s;
    while(p!=NULL || s.isempty())
    {
        if(p!=NULL)
        {
            s.push(p);
            p=p->prev;
        }
        else
        {
            p=s.pop();
            cout<<p->info;
            p=p->next;
        }
    }
}

void tree::nrc_pre(node *p)
{
    stack s;
    while(p!=NULL || !s.isempty())
    {
        if(p!=NULL)
        {
            s.push(p);
            cout<<p->info;
            p=p->prev;
        }
        else
        {
            p=s.pop();
            p=p->next;
        }
    }
}

void tree::nrc_post(node *p)
{
    stack s1,s2;
    s1.push(p);

    while(!s1.isempty())
    {
        p=s1.pop();
        s2.push(p);
        if(p->prev!=NULL)
        {
            s1.push(p->prev);
        }
        if(p->next!=NULL)
        {
            s1.push(p->next);
        }
    }
    while(!s2.isempty())
    {
        p=s2.pop();
        cout<<p->info;
    }
}

int main()
{
    tree t;
    t.create();

    t.rc_in(t.root);
    cout<<endl;
    t.rc_pre(t.root);
    cout<<endl;
    t.rc_post(t.root);
    cout<<endl;

    t.nrc_in(t.root);
    cout<<endl;

    t.nrc_pre(t.root);
    cout<<endl;

    t.nrc_post(t.root);
    cout<<endl;

}