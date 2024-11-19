#include <iostream>
#define v 7
#define INF 999
using namespace std;

class MST 
{
    int dist[v],parent[v],visited[v];
    int G[7][7]={   {0,2,3,4,0,0,0},
                    {2,0,0,0,8,0,0},
                    {3,0,0,0,6,0,0},
                    {4,0,0,0,4,5,0},
                    {0,8,6,4,0,0,7},
                    {0,0,0,5,0,0,9},
                    {0,0,0,0,7,9,0}
                };
    public:
        void display();
        void prims();
        int selectmin();
};

void MST::display()
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cout<<G[i][j]<<"\t";
        }
        cout<<endl;
    }
    
}

void MST::prims()
{
    int s;
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
        parent[i]=-1;
        dist[i]=INF;
    }
    
    cout<<"Enter the source element: ";
    cin>>s;
    int sv=s;
    dist[s]=0;
    
    for(int i=0;i<v-1;i++)
    {
        visited[s]=1;
        for(int j=0;j<v;j++)
        {
            if(G[s][j]!=0 && visited[j]==0 && G[s][j]<dist[j])
            {
                dist[j]=G[s][j];
                parent[j]=s;
            }
        }
        s=selectmin();
    }
    
    for(int i=1;i<v;i++)
    {
        int j=i;
        cout<<"\n"<<i;
        while(parent[j]!=sv && parent[i]!=-1)
        {
            cout<<"<-"<<parent[j];
            j=parent[j];
        }
        cout<<"<-"<<sv;
        cout<<"="<<dist[i]<<endl;
    }
}

int MST:: selectmin()
{
    int min=INF;
    int vertex;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0 && dist[i]<=min)
        {
            vertex=i;
            min=dist[i];
        }
    }
    return vertex;
}

int main()
{
    MST m;
    m.display();
    cout<<endl;
    m.prims();
}


