#include <iostream>
#include "Stackk.cpp"
#include <cstring>
#include <math.h>
#include <cctype>
using namespace std;

class expcon
{
    char inf[20],pre[20],post[20];
    public:
        void inf2pre();
        void inf2post();
        void preeval();
        void posteval();
        void strrev(char a[]);
        int eval(char x,int s1,int s2);
        int icp(char x);
        int isp(char x);
};

void expcon::strrev(char a[])
{
    char temp;
    int i=0;
    int j=strlen(a)-1;
    while(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        a++;
        j--;
    }
}

int expcon::icp(char x)
{
    int a;
    switch(x)
    {
        case '+':
            a=1;
            break;
        case '-':
            a=1;
            break;
        case '*':
            a=2;
            break;
        case '/':
            a=2;
            break;
        case '%':
            a=3;
            break;
        case '^':
            a=4;
    }
    return a;
}

int expcon::isp(char x)
{
    int a;
    switch(x)
    {
        case '+':
            a=1;
            break;
        case '-':
            a=1;
            break;
        case '*':
            a=2;
            break;
        case '/':
            a=2;
            break;
        case '%':
            a=3;
            break;
        case '^':
            a=4;
    }
    return a;
}

int expcon::eval(char x,int s1,int s2)
{
    switch(x)
    {
        case '+':
            return(s1+s2);
            break;
        case '-':
            return(s1-s2);
            break;
        case '*':
            return(s1*s2);
            break;
        case '/':
            return(s1/s2);
            break;
        case '^':
            return(s1^s2);
    }
}

void expcon::inf2post()
{
    int j=0;
    char y;
    stack s;
    cout<<"Enter the Infix Expression: ";
    cin>>inf;
    for(int i=0;i<strlen(inf);i++)
    {
        char x=inf[i];
        if(isalnum(x))
        {
            pre[j++]=x;
        }
        else if(x=='(')
        {
            s.push('(');
        }
        else if(x==')')
        {
            while(y=(s.pop())!='(')
            {
                pre[j++]=y;
            }
        }
        else
        {
            while(!(s.isempty()) && icp(x)<=isp(s.topdata()))
            {
                pre[j++]=s.pop();
            }
            s.push(x);
        }
    }
    while(!(s.isempty()))
    {
        pre[j++]=s.pop();
    }
    pre[j]='\0';
    cout<<pre;
}

void expcon::inf2post()
{
    int j=0;
    stack s;
    int y;
    cout<<"Enter the Expression: ";
    cin>>inf;
    for(int i=0;i<strlen(inf);i++)
    {
        char x=inf[i];
        if(isalnum(x))
        {
            post[j++]=x;
        }
        else if(x=='(')
        {
            s.push('(');
        }
        else if(x==')')
        {
            while(y=s.pop()!=')')
            {
                post[j++]=x;
            }
        }
        else
        {
            while(!(s.isempty()) && icp(x)<=isp(s.topdata()))
            {
                post[j++]=x;
            }
            s.push(x);
        }
    }
    while(!s.isempty())
    {
        post[j++]=s.pop();
    }
    post[j]='\0';
    cout<<post;
}

void expcon::inf2pre()
{
    int j=0;
    char y;
    stack s;
    cout<<"Enter the Expression: ";
    cin>>inf;
    strrev(inf);
    for(int i=0;i<strlen(inf);i++)
    {
        char x=inf[i];
        if(x=='(')
        {
            x=')';
        }
        if(x==')')
        {
            x='(';
        }
    }
    for(int i=0;i<strlen(inf);i++)
    {
        char x=inf[i];
        if(isalnum(inf[i]))
        {
            pre[j++]=x;
        }
        else if(x=='(')
        {
            s.push('(');
        }
        else if(x==')')
        {
            while(y=(s.pop())!='(')
            {
                pre[j++]=y;
            }
        }
        else
        {
            while(!(s.isempty()) && icp(x)<=isp(s.topdata()))
            {
                pre[j++]=s.pop();
            }
            s.push(x);
        }
    }
    while(!s.isempty())
    {
        pre[j++]=s.pop();
    }
    pre[j]='\0';
    strrev(pre);
    cout<<pre;
}

void expcon::preeval()
{   
    stack s;
    int r;
    cout<<"\nEnter the Prefix expression: ";
    cin>>pre;
    strrev(pre);
    for(int i=0;i<strlen(pre);i++)
    {
        char x=inf[i];
        if(isalpha(x))
        {
            s.push(x);
        }
        else if(isdigit(x))
        {
            s.push(x-48);
        }
        else
        {
            int s1=s.pop();
            int s2=s.pop();
            r=eval(x,s1,s2);
            s.push(r);
        }
    }
    r=s.pop();
    cout<<r;
}

void expcon::posteval()
{
    stack s;
    int r;
    cout<<"\nEnter the Postfix Expression: ";
    cin>>post;

    for(int i=0;i<strlen(post);i++)
    {
        char x=post[i];
        if(isalpha(x))
        {
            s.push(x);
        }
        else if(isdigit(x))
        {
            s.push(x-48);
        }
        else
        {
            int s2=s.pop();
            int s1=s.pop();
            r=eval(x,s1,s2);
            s.push(r);
        }
    }
    r=s.pop();
    cout<<r;
}

int main()
{
    expcon e;
    e.inf2post();
    e.inf2pre();
    e.preeval();
    e.posteval();
}