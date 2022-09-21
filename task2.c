#include "task2.h"
int mindistanceNode(double dist[],int viz[],int n)
{
    int i,min=9999,min_node;
    for(i=0;i<n;i++)
        if(viz[i]==0 && dist[i]<=min)
            {
                min=dist[i];
                min_node=i; ///calcul nod care se afla la distanta minima in algoritmul lui dijkstra
            }
    return min_node;
}
void dfs(double **a,int n,int i,int viz[],int v[])
{
    int j;
    viz[i]=1;
    for(j=0;j<n;j++)
        if(a[i][j] !=0 && a[i][j] !=999 && viz[j]==0 && v[j]==0)
            dfs(a,n,j,viz,v); /// dfs recursiv
}
void reverse_dfs(double **a,int n,int i,int viz[],int v[])
{
    int j;
    viz[i]=1;
    for(j=0;j<n;j++)
        if(a[j][i] !=0 && a[j][i] !=999 && viz[j]==0 && v[j]==0)
            reverse_dfs(a,n,j,viz,v); /// dfs invers pentru algoritmul plusminus
}
void plusminus(double **a,int n,int v[])
{
    int i;
    int nrc=0;
    int comp[100];
    for(i=0;i<n;i++)
        comp[i]=0;
    for(i=0;i<n;i++)
    if(comp[i]==0 && v[i]==0)
    {
        int plus[100],minus[100];
        int j;
        for(j=0;j<n;j++)
        {
            plus[j]=0;
            minus[j]=0;
        }
        nrc++;
        dfs(a,n,i,plus,v);
        reverse_dfs(a,n,i,minus,v);
        for(j=0;j<n;j++)
            if(plus[j]==1 && minus[j]==1 && v[j]==0)
                comp[j]=nrc;
    }
    int viz[100];
    for(i=0;i<n;i++)
        viz[i]=0;
    printf("%d\n",nrc);
    int j;
    for(i=0;i<n;i++) /// algoritmul plusminus 
            if(viz[i]==0 && v[i]==0){
                printf("%d",i);
                viz[i]=1;
                for(j=0;j<n;j++)
                    if(viz[j]==0 && comp[i]==comp[j])
                    {
                        viz[j]=1;
                        printf(" %d",j);
                    }
              if(nrc>1)
                printf("\n");
              nrc--;      
            }

}