#include "task3.h"
extern double cost;
void transform_to_shortest_path(double **a,int n,int *v,int *nodes)
{
    int i,j;
    double aux[100][100];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            aux[i][j]=999;
        aux[i][i]=0;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(v[i]==1 || nodes[i]==1) /// transformarea in matricea de drumuri minime
                if(v[j]==1 || nodes[j]==1)
                    if(i!=j)
                         aux[i][j]=dijkstra(a,n,i,j);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=aux[i][j];
}
int next_node(double **a,int n,int s,int viz[])
{
    int i;
    int next=999;
    double min_both_ways=999;
    double min=999;
    for(i=0;i<n;i++)
        if(a[s][i]!=999 && a[s][i]!=0 && viz[i]==0 && (a[s][i]+a[i][s]<min_both_ways))
        {
            min_both_ways=a[s][i]+a[i][0]; /// calcularea nodului care are cea mai scurta distanta inapoi catre inceput
            min=a[s][i];
            next=i;
        }
    if(min_both_ways!=999)
        cost+=min;
    return next;
}
void get_parents(double **graf, int n, int source, int parent[])
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
                    {
                        dist[v]=dist[u]+graf[u][v];
                        parent[v]=u; /// algoritmul lui dijkstra cu retinere de drum cu vectorul parinte dat ca parametru
                    }
    }  
}
void visit_parents(int *parent,int s,int next,int viz[])
{
    if(next==s)
        return;
    next=parent[next];
    while(next!=-1) /// daca vizitam un nod, vizitam si nodurile intermediare prin care se trece ca sa ajungem la acesta
    {
        viz[next]=1;
        next=parent[next];
    }
}
void get_min_cost(double **a,double **original,int n,int s,int viz[])
{
    int next;
    viz[s]=1;
    next=next_node(a,n,s,viz);
    int parent[100];
    int i;
    for(i=0;i<n;i++) /// algoritm TSP modificat pentru a elimina restrictia de a vizita fiecare nod o singura data
        parent[i]=-1;
    if(next!=999){
    get_parents(original,n,s,parent);
    visit_parents(parent,s,next,viz);
    }
    if(next==999)
    {
        next=0;
        cost+=a[s][0];
        return;
    }
    get_min_cost(a,original,n,next,viz);
}