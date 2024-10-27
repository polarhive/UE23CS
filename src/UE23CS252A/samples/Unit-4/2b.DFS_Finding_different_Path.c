#include<stdio.h>
#include "Graph_Adj_list.c"
#include "Graph_Adj_mat.c"

void dfs_adjMat(GRAPH *g,int start,int dest,int *path){
    static int visited[MAX],count;
    //printf("%d",start);
    path[count++]=start;
    //Code Added ....//Finding all the paths from source to dest
    if(start==dest){
        for(int i=0;i<count;i++)
            printf("%d ",path[i]);
        printf("\n");
    }
    else{
    //... code Added
    visited[start]=1;
    for(int i=1;i<=g->vertex;i++){
        if(g->adjMatrix[start][i]==1 && visited[i]==0)
            dfs_adjMat(g,i,dest,path); //recursive call
        }
    }
    count--;//Code Added - backtracking in the path array
}
void dfs_adjList(NODE *l,int source,int dest,int *path){
    NODE *t;
    static int visited[MAX],count;
    t=&l[source];
    path[count++]=source;
    //printf("%d->",t->data);
    if(source==dest){
        for(int i=0;i<count;i++)
            printf("%d ",path[i]);
        printf("\n");
    }
    else{
    visited[source]=1;
    while(t->next!=NULL){
        t=t->next;
        if(visited[t->data]==0)//if unvisited
            dfs_adjList(l,t->data,dest,path);
        }
    }
    count--;
}
void main(){
    GRAPH g;
    int source,dest,path[MAX];
    NODE graph[MAX];
    create_adjMatrix(&g);
    matrixDisplay(g);
    //create_adjList(graph);
    //ListDisplay(graph);
    printf("\nenter the source: ");
    scanf("%d",&source);
    printf("\nenter the destination: ");
    scanf("%d",&dest);
    printf("\nAdjacency Matrix:");
    dfs_adjMat(&g,source,dest,path);
    printf("\nAdjacency List:");
    dfs_adjList(graph,source,dest,path);
}

