#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void transform_to_shortest_path(double **,int n,int *,int *);
double dijkstra(double **, int, int, int);
int mindistanceNode(double [],int [],int);
void get_min_cost(double **,double**, int, int, int[]);
void get_parents(double **, int, int, int[]);
void visit_parents(int *,int,int,int[]);