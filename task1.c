#include "task1.h"
double dijkstra(double **graf, int n, int source, int dest)
{
    double dist[100];
    int i;
    for(i=0;i<n;i++)
        dist[i]=999;
    int viz[100];
    for(i=0;i<n;i++)
        viz[i]=0;
    dist[source]=0;
    for(i=0;i<n-1;i++)
    {
        int u=mindistanceNode(dist,viz,n);
        viz[u]=1;
        int v;
        for(v=0;v<n;v++)
            if(viz[v]==0 && graf[u][v]!=999 && graf[u][v]!=0)
                if(dist[u]+graf[u][v]<dist[v])
                    dist[v]=dist[u]+graf[u][v]; /// algoritmul lui dijkstra
    }
    return dist[dest];
}
void printPath(int parent[],int source,int dest)
{
    if(parent[dest]==-1)
        return;
    printPath(parent,source,parent[dest]); /// recursivitate pentru a retine drumul inapoi in algoritmul lui dijkstra
    if(dest!=source)
        printf(" %d",dest);
}
void dijkstrapath(double **graf, int n, int source, int dest)
{
    double dist[100];
    int i;
    for(i=0;i<n;i++)
        dist[i]=999;
    int viz[100],parent[100];
    for(i=0;i<n;i++)
        {
            viz[i]=0;
            parent[i]=-1;
        }

    dist[source]=0;
    for(i=0;i<n-1;i++)
    {
        int u=mindistanceNode(dist,viz,n);
        viz[u]=1;
        int v;
        for(v=0;v<n;v++)
            if(viz[v]==0 && graf[u][v]!=999 && graf[u][v]!=0)
                if(dist[u]+graf[u][v]<dist[v])
                    { 
                        dist[v]=dist[u]+graf[u][v];
                        parent[v]=u;/// algoritmul lui dijkstra cu retinere de drum
                    }
    }
    printPath(parent,source,dest);
    
}