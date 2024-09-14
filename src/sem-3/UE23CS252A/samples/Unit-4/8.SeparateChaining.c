#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct node{
    int data;
    struct node *next;
}NODE;

typedef struct hashtable{
    int count;
    struct node *head;
}HASHTABLE;
NODE* createNode(int key){
    NODE *nn;
    nn=(NODE*)malloc(sizeof(NODE));
    nn->data=key;
    nn->next=NULL;
    return nn;
}
void insert(int key,HASHTABLE *HashTable){
    int hash;
    NODE *nn,*t;
    hash=key%SIZE;
    nn=createNode(key);
    if(HashTable[hash].count==0){//insert the first node in the index no;
       HashTable[hash].count++;
       HashTable[hash].head=nn;
    }
    else{
      t=HashTable[hash].head;
      while(t->next!=NULL)
            t=t->next;
      t->next=nn;
      HashTable[hash].count++;
    }
}
void search(int key,HASHTABLE *HashTable){
    int hash,pos=0;
    NODE *t;
    hash=key%SIZE;
    t=HashTable[hash].head;
    while(t!=NULL){
        pos++;
        if(t->data==key){
            printf("\nThe element is found at index [%d] in position [%d]",hash,pos);
            return;
        }
         t=t->next;
    }
    printf("\nData not found ");
}
void deleteData(int key,HASHTABLE *HashTable){
    int hash,pos=0;
    NODE *t,*prev;
    hash=key%SIZE;
    t=HashTable[hash].head;
    while(t!=NULL){
        pos++;
        if(t->data==key){
            if(pos==1){
                HashTable[hash].head=t->next;
            }
            else{
                prev=HashTable[hash].head;
                while(prev->next!=t)
                    prev=prev->next;
                prev->next=t->next;
            }
            free(t);
            HashTable[hash].count--;
            return;
        }
         t=t->next;
    }
    printf("\nData not found ");
}
void display(HASHTABLE *HashTable){
    int i;
    NODE *t;
    for(i=0;i<SIZE;i++){
        if(HashTable[i].count!=0){
            printf("\nindex=[%d] count=[%d]",i,HashTable[i].count);
            t=HashTable[i].head;
            while(t!=NULL){
                printf("%d->",t->data);
                t=t->next;
            }
        }
    }
}

void main(){
int key,ch;
HASHTABLE hashTable[SIZE]={};
    do{
    printf("\nEnter the key to be inserted:");
    scanf("%d",&key);
    insert(key,hashTable);
    printf("\nTo exit Press 0:");
    scanf("%d",&ch);
    }while(ch);
    display(hashTable);
    do{
    printf("\nEnter the key to be searched:");
    scanf("%d",&key);
    search(key,hashTable);
    printf("\nTo exit Press 0:");
    scanf("%d",&ch);
    }while(ch);

    do{
    printf("\nEnter the key to be deleted:");
    scanf("%d",&key);
    deleteData(key,hashTable);
    display(hashTable);
    printf("\nTo exit Press 0:");
    scanf("%d",&ch);
    }while(ch);

}

