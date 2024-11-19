#include <iostream>
#include <cmath>
using namespace std;

class SEIT
{
    int n;
    struct stud
    {
        int rn;
        string name;
        float sg;
    }s[20];
    public:
        void setdata();
        void getdata();
        void search(float);
        void bubble_sort();
        void insertion();
        void binary_search(string);
        int partition(int,int);
        void quick_sort(int,int);
        void quick_display();
};

void SEIT::setdata()
{
    cout<<"Enter the Number of Student: ";
    cin>>n;
    cout<<"Enter Information of the student"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Roll No.: ";
        cin>>s[i].rn;
        cout<<"Name: ";
        cin>>s[i].name;
        cout<<"SGPA: ";
        cin>>s[i].sg;
        
    }
}

void SEIT::getdata()
{
    cout<<"ROll No."<<"\t"<<"NAme"<<"\t"<<"\t"<<"SGPA"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<s[i].rn<<"\t"<<"\t"<<s[i].name<<"\t"<<"\t"<<s[i].sg<<endl;
    }
}

void SEIT::search(float marks)
{
    cout<<"ROll No."<<"\t"<<"NAme"<<"\t"<<"\t"<<"SGPA"<<endl;
    for(int i=0;i<n;i++)
    {
        if(s[i].sg>marks)
        {
            cout<<s[i].rn<<"\t"<<"\t"<<s[i].name<<"\t"<<"\t"<<s[i].sg<<endl;
        }
    }
}

void SEIT::bubble_sort()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(s[j].rn>s[j+1].rn)
            {
                struct stud temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    getdata();
}

void SEIT::insertion()
{
    int i,p;
    struct stud temp;
    for(int i=1;i<n;i++)
    {
        string key=s[i].name;
        temp=s[i];
        for(p=i-1;(p>=0) && s[p].name>key;p--)
        {
            s[p+1]=s[p];
        }
        s[p+1]=temp;
    }
    getdata(); 
}

void SEIT::binary_search(string key)
{
    int l,h,mid;
    mid=floor((l+h)/2);
    if(s[mid].name==key)
    {
        cout<<"Key is Found: "<<key;
    }
    else if(s[mid].name<key)
    {
        h=mid-1;
    }
    else if(s[mid].name>key)
    {
        l=mid+1;
    }
    else
    {
        cout<<"Key is  not found";
    }
}

// int SEIT::partition(int l,int h)
// {
//     l=0;
//     h=i+2;
// }


int main()
{
    SEIT s;
    s.setdata();
    s.getdata();
    s.search(5);
    s.bubble_sort();
    s.insertion();
    s.binary_search("Ami");
}