#include<stdio.h>
#include "Graph_Adj_list.c"
#include "Graph_Adj_mat.c"
int f=-1,r=-1;
int isempty(int *q){
    return (f==r && f==-1);
}
void enqueue(int *q,int data){
    if(isempty(q))
        f++;
    q[++r]=data;
}
int dequeue(int *q){
    int d=q[f];
    if(f==r && f!=-1){//one element condition
        f=r=-1;
    }
    else
        f++;
    return d;
}
//BFS implementation using Adjacency Matrix
int bfs_AdjMat(GRAPH *g)
 {
     int source,*queue,*visited,v,i,dest;
     printf("\nEnter the source vertex");
     scanf("%d",&source);
     printf("\nEnter the destination vertex");
     scanf("%d",&dest);
     v=g->vertex;
     queue=(int*)calloc(v,sizeof(int));
     visited=(int*)calloc(v+1,sizeof(int));
     enqueue(queue,source);
     visited[source]=1;
     printf("\n%d ",source);
     while(!isempty(queue)){
         i=dequeue(queue);
         for(int j=1;j<=v;j++){
            if(g->adjMatrix[i][j]==1 && visited[j]==0){
                enqueue(queue,j);
                visited[j]=1;
                printf("%d ",j);
                if(dest==j) return 1;
            }
         }
     }
     return 0;
 }
 //BFS implementation using Adjacency List
 int bfs_AjdList(NODE *l)
 {
     int source,*queue,*visited,v,i,j,dest;
     NODE *t;
     printf("\nEnter the source vertex");
     scanf("%d",&source);
     printf("\nEnter the destination vertex");
     scanf("%d",&dest);
     v=l[0].data;
     queue=(int*)calloc(v,sizeof(int));
     visited=(int*)calloc(v+1,sizeof(int));
     enqueue(queue,source);
     visited[source]=1;
     printf("\n%d ",source);
     while(!isempty(queue))
     {
         i=dequeue(queue);
         t=&l[i];
         while(t->next!=NULL)
         {
            t=t->next;
            j=t->data;
            if(visited[j]==0)
            {
                enqueue(queue,j);
                visited[j]=1;
                printf("%d ",j);
                if(dest==j) return 1;
            }
         }
     }
 return 0;
 }
void main(){
    GRAPH g;
    int path;
    create_adjMatrix(&g);
    matrixDisplay(g);
    path=bfs_AdjMat(&g);
    if(path) printf("\nThere is a path");
    else printf("\nNo path exist");
    NODE graph[MAX];
    create_adjList(graph);
    ListDisplay(graph);
    path=bfs_AjdList(graph);
    if(path) printf("\nThere is a path");
    else printf("\nNo path exist");
}
