#include<stdio.h>
#include "Graph_Adj_list.c"
#include "Graph_Adj_mat.c"

void dfs_adjMat(GRAPH *g,int start,int parent){
    static int visited[MAX];
    printf("%d ",start);
    visited[start]=1;
    for(int i=1;i<=g->vertex;i++){
        if(g->adjMatrix[start][i]==1){
            if(visited[i]==0){
                dfs_adjMat(g,i,start);
            }
            else if(i!=parent){//if visited ==1 //for undirected graph
                printf("\nCycle detected: %d -> %d\n", start, i);
            }
        }
             //recursive call
    }
}
void dfs_adjList(NODE *l,int source){
    NODE *t;
    static int visited[MAX];
    t=&l[source];
    printf("%d->",t->data);
    visited[source]=1;
    while(t->next!=NULL){
        t=t->next;
        if(visited[t->data]==0)//if unvisited
            dfs_adjList(l,t->data);
        }
    }
void main(){
    GRAPH g;
    int source;
    create_adjMatrix(&g);
    matrixDisplay(g);
    printf("\nenter the source: ");
    scanf("%d",&source);
    dfs_adjMat(&g,source,-1);
   /* NODE graph[MAX];
    create_adjList(graph);
    ListDisplay(graph);
     printf("\nenter the source: ");
    scanf("%d",&source);
    dfs_adjList(graph,source);*/
}
