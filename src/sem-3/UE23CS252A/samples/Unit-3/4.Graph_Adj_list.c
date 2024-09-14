#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct node{
    int data;
    struct node *next;
}NODE;
create_adjList(NODE *l){
    int v,from,to;
    NODE *t,*nn;
    printf("\nEnter the no. of nodes:");
    scanf("%d",&v);
    l[0].data=v;
    l[0].next=NULL;
    for(int i=1;i<=l[0].data;i++){
        l[i].data=i;
        l[i].next=NULL;
    }
    while(1){
    printf("\nEnter the from and to node");
    scanf("%d %d",&from,&to);
    if(from>0 && from<=v && to>0 && to<=v){//valid vertex
            t=&l[from];
            while(t->next!=NULL){
                t=t->next;
            }
            nn=(NODE*)malloc(sizeof(NODE));
            nn->data=to;
            nn->next=NULL;
            t->next=nn;
    }
    else
        break;
    }
}
void ListDisplay(NODE *l){
    NODE *t;
    for(int i=1;i<=l[0].data;i++){
        printf("\n%d->",l[i].data);
        t=&l[i];
        while(t->next!=NULL){
            t=t->next;
            printf("%d->",t->data);
        }
        printf("NULL");
    }
}


