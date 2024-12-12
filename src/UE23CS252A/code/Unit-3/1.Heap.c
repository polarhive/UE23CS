#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 20

typedef struct heap{
    int heap[SIZE];
    int heapSize;
}Heap;

Heap* init(Heap *h){
    h->heapSize=0;
    h->heap[0]=INT_MAX;
    return h;
}
void swap(int *a, int *b){
 int t;
 t=*a;
 *a=*b;
 *b=t;
}
Heap* insert_TopDown(Heap *h,int data){
    int p,c;
    h->heap[++(h->heapSize)]=data;
    c=h->heapSize; //c => index no of the child
    p=c/2;
    while(h->heap[p]<h->heap[c]){
        swap(&h->heap[p],&h->heap[c]);
        c=p;
        p=c/2;
    }
    return h;
}

void insert_BottomUp(Heap *h){
    int p,c;
    p=h->heapSize/2;
    for(int i=p;i>=1;i--){
        p=i;
        c=2*p;
        while(c<=h->heapSize){
            if(c+1<=h->heapSize && h->heap[c+1]>h->heap[c])
                c++;
            if(h->heap[p]<h->heap[c])
                swap(&h->heap[p],&h->heap[c]);
            else
                break;
            p=c;
            c=2*p;
        }
    }
}
void display(Heap *h){
    if(h!=NULL){
    for(int i=1;i<=h->heapSize;i++)
        printf("%d ",h->heap[i]);
}
}

int deleteData(Heap *h){
    int p,c,d;
    d=h->heap[1];
    h->heap[1]=h->heap[h->heapSize--];
    p=1;
    c=2*p;
    while(c<=h->heapSize){
            if(c+1<=h->heapSize && h->heap[c+1]>h->heap[c])
                c++;
            if(h->heap[p]<h->heap[c])
                swap(&h->heap[p],&h->heap[c]);
            else
                break;
            p=c;
            c=2*p;
        }
    return d;
}
void main(){
    Heap *h,*h1;
    int n,d;
    h=(Heap*)malloc(sizeof(Heap));
    h=init(h);
    //Bottom Up
    h1=(Heap*)malloc(sizeof(Heap));
    h1=init(h1);
    printf("\nEnter the no of node");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("\nEnter data: ");
        scanf("%d",&d);
        h=insert_TopDown(h,d);
        h1->heap[++(h1->heapSize)]=d;//Constructing Complete BT for Bottom up approach
    }
    display(h);
    insert_BottomUp(h1);
    printf("\nBottom Up Construction\n");
    display(h1);
    /*Priority Queue implementation*/
    printf("\n***Priority Queue***\n");
    n=h1->heapSize;
    for(int i=1;i<=n;i++)
        printf("%d ",deleteData(h1));

}
