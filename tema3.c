#include "task1.h"
#include "task2.h"
#include "task3.h"
double cost=0;
int main(void)
{
    int n, m, d, i, j;
    double **a;
    scanf("%d%d%d", &n, &m, &d);
    a=malloc(n*sizeof(double*));
    for(i=0;i<n;i++)
        a[i]=malloc(n*sizeof(double));
    for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                a[i][j]=999;
            a[i][i]=0;
        }
        
    for(i=0; i<m; i++)
        {
            int u,v;
            double w;
            scanf("%d%d%lf", &u, &v, &w);
            a[u][v]=w;
        }
    int v[100];//vectorul de depozite
    for(i=0; i<n; i++)
        v[i]=0;
    for(i=0;i<d;i++)
        {
            int nod;
            scanf("%d",&nod);
            v[nod]=1;
        }
    int nr_of_tasks; /// numarul de cerinte pe care le vom rezolva
    scanf("%d",&nr_of_tasks);
    int x;
    for(x=0;x<nr_of_tasks;x++)
    {
        char taskid[4];
        scanf("%s",taskid);
        if(strcmp(taskid,"e1")==0)
        {
            int s;
            scanf("%d", &s);
            int k;
            scanf("%d", &k);
            int magazine[100];
            for(i=0; i<k;i++)
                scanf("%d",&magazine[i]);
            double totaldist=0;
            for(i=0;i<k;i++)
            {
                printf("%d\n",magazine[i]);
                double d1=dijkstra(a,n,s,magazine[i]); /// distanta de la depozit la magazinul i
                double d2=dijkstra(a,n,magazine[i],s); /// distanta de la magazinul i inapoi la depozit
                totaldist+=d1;
                totaldist+=d2;
                printf("%.1lf %.1lf\n",d1,d2);
                printf("%d",s);
                dijkstrapath(a,n,s,magazine[i]);/// drumul de la depozit la magazinul i
                dijkstrapath(a,n,magazine[i],s);  /// drumul de la magazinul i la depozit
                printf("\n");
            }
            printf("%.1lf",totaldist);
            if(x<nr_of_tasks-1) /// pentru a nu afisa la final \n aiurea
                printf("\n");
        }
        if(strcmp(taskid,"e2")==0)
        {
            plusminus(a,n,v);/// algoritmul plusminus, o metoda mai simplificata a algoritmului Kosaraju
        }
        if(strcmp(taskid,"e3")==0)
        {
            int r;
            scanf("%d",&r);
            for(i=0;i<r;i++)
                {
                    int k;
                    scanf("%d",&k);
            int nodes[100];
            for(j=0;j<n;j++)
                nodes[j]=0;
            for(j=0;j<k;j++)
                {
                    int node;
                    scanf("%d",&node);
                    nodes[node]=1;
                }
                
            double **subgraf;
            subgraf=malloc(n*sizeof(double*));
            for(j=0;j<n;j++)
                subgraf[j]=malloc(n*sizeof(double)); /// subgraful care contine doar nodurile date ca argument+depozitele
            int i1;
            for(i1=0;i1<n;i1++){
                for(j=0;j<n;j++)
                    subgraf[i1][j]=999;
                subgraf[i1][i1]=0;
            }
            for(i1=0;i1<n;i1++)
                for(j=0;j<n;j++)
                    if(nodes[i1]==1 && nodes[j]==1)
                        subgraf[i1][j]=a[i1][j];
                    else if(nodes[i1]==1 && v[j]==1)
                        subgraf[i1][j]=a[i1][j];
                    else if(v[i1]==1 && nodes[j]==1)
                        subgraf[i1][j]=a[i1][j];
                    else if(v[i1]==1 && v[j]==1)
                        subgraf[i1][j]=a[i1][j];
            double **shortest_pathsubgraf;
            shortest_pathsubgraf=malloc(n*sizeof(double*)); 
            for(j=0;j<n;j++)
                shortest_pathsubgraf[j]=malloc(n*sizeof(double));
            for(i1=0;i1<n;i1++)
                for(j=0;j<n;j++)
                    shortest_pathsubgraf[i1][j]=subgraf[i1][j];
            transform_to_shortest_path(shortest_pathsubgraf,n,v,nodes);/// trecere la matricea de cost minim pentru a aplica algoritmul TSP
            int viz[100];
            for(i1=0;i1<n;i1++)
                viz[i1]=0;
            cost=0;
            get_min_cost(shortest_pathsubgraf,subgraf,n,0,viz); /// cost este variabila globala in care se retine cel mai scurt drum
            printf("%.1lf",cost);
            if(i<r-1)
                printf("\n");
            for(j=0;j<n;j++)
                {
                    free(subgraf[j]);
                    free(shortest_pathsubgraf[j]);
                }
            free(subgraf);
            free(shortest_pathsubgraf);
            }
        }
    
    }
for(i=0;i<n;i++)
        free(a[i]);
    free(a);
}