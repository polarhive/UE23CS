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
     int source,*queue,*visited,v,i;
     printf("\nEnter the source vertex");
     scanf("%d",&source);
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
            }
         }
     }
     //Code added...
     for(int i=1;i<=g->vertex;i++)
    {
        if(!visited[i])
            return 0;
    }
return 1;
//...Code added
 }
 //BFS implementation using Adjacency List
 void bfs_AjdList(NODE *l)
 {
     int source,*queue,*visited,v,i,j;
     NODE *t;
     printf("\nEnter the source vertex");
     scanf("%d",&source);
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
            if(visited[j]==0){
                enqueue(queue,j);
                visited[j]=1;
                printf("%d ",j);
            }
         }
     }
 }
void main(){
    GRAPH g;
    int connected;
    create_adjMatrix(&g);
    matrixDisplay(g);
    connected=bfs_AdjMat(&g);
    if(connected)
        printf("\nThe graph is connected");
    else
        printf("\nThe graph is disconnected");
    NODE graph[MAX];
    create_adjList(graph);
    ListDisplay(graph);
    connected=bfs_AjdList(graph);
    if(connected)
        printf("\nThe graph is connected");
    else
        printf("\nThe graph is disconnected");
}

