#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct node{
    int data;
    struct node *next;
}NODE;

typedef struct hash{
    int count;
    struct node *head;
}HASHTABLE;
NODE createNode(int key){
    NODE *nn=(NODE*)malloc(sizeof(NODE));
    nn->data=key;
    nn->next=NULL;
    return nn;
}
void insert(int key,HASHTABLE *HashTable){
    int hash;
    NODE *nn,*t;
    hash=key%SIZE;
    nn=createNode(key);
    if(HashTable[hash].count==0){
        HashTable[hash].count++;
        HashTable[hash].head=nn;
    }
    else{
      t=HashTable[hash].head;
      while(t->next!=NULL){
        t=t->next;
      }
      t->next=nn;
      HashTable[hash].count++;
    }
}
void search(int key, HASHTABLE *HashTable){
    int hash,pos=0;
    NODE *t;
    hash=key%SIZE;
    t=HashTable[hash].head;
    while(t!=NULL){
        pos++;
        if(t->data==key){
            printf("")
        else
            t=t->next;
    }}
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
                free(t);
            }
        }
        else
            t=t->next;
    }
}
void main(){
int key;
HASHTABLE HashTable[SIZE]={};
}
