#include<stdio.h>
#define MAX 10

typedef struct graph{
    int vertex;
    int adjMatrix[MAX][MAX];
}GRAPH;
void create_adjMatrix(GRAPH *g){
    int from,to;
    printf("\nEnter the no. of Vertices:");
    scanf("%d",&g->vertex);
    for(int i=1;i<=g->vertex;i++){
        g->adjMatrix[0][i]=i; // Name row and column index to represent vertex
        g->adjMatrix[i][0]=i;
        for(int j=1;j<=g->vertex;j++){//initialize adj Matrix with zeros
            g->adjMatrix[i][j]=0;
        }
    }
    while(1){
      printf("\nEnter the from and to vertices:");
      scanf("%d %d",&from,&to);
      if(from>0 && from<=g->vertex && to>0 && to<=g->vertex){
        g->adjMatrix[from][to]=1;
        //g->adjMatrix[to][from]=1; for undirected
        }
      else
        break;

    }
}
void matrixDisplay(GRAPH g){
    for(int i=0;i<=g.vertex;i++){
            printf("\n");
        for(int j=0;j<=g.vertex;j++){
            if(i==0 && j==0){
               printf("  ");
            }
            else
            printf("%d ",g.adjMatrix[i][j]);
        }
    }
}

