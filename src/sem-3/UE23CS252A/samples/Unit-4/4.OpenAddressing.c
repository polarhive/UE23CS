#include<stdio.h>
#define SIZE 10
typedef struct node{
    int data;
    int flag;
}NODE;
void insert(int key,NODE *hashTable){
    int hash,i=0;
    hash=((key%SIZE)+i)%SIZE;
    while(hashTable[hash].flag==1 && i<SIZE){
        i++;
        hash=((key%SIZE)+i)%SIZE;
    }
    if(hashTable[hash].flag==0){
        hashTable[hash].data=key;
        hashTable[hash].flag=1;
    }
    else
        printf("\nData cannot be inserted");
}
void search(int key,NODE *hashTable){
    int i=0,hash;
    hash=((key%SIZE)+i)%SIZE;
    while(i<SIZE){
    if(hashTable[hash].data!=key && hashTable[hash].flag==1){
        i++;
        hash=((key%SIZE)+i)%SIZE;
    }
    else if(hashTable[hash].data==key){
        printf("\nData found at %d index",hash);
        return;
    }
    else
        break;
    }
    printf("\nData not found");
    return;
}
void Delete(int key,NODE *hashTable){
    int i=0,hash;
    hash=((key%SIZE)+i)%SIZE;
    while(i<SIZE){
    if(hashTable[hash].data!=key && hashTable[hash].flag==1){
        i++;
        hash=((key%SIZE)+i)%SIZE;
    }
    else if(hashTable[hash].data==key){
        hashTable[hash].data=99999;
        hashTable[hash].flag=0;
        printf("\nData deleted at %d index",hash);
        return;
    }
    else
        break;
    }
    printf("\nData not found");
    return;
}
void display(NODE *hashTable){
    for(int i=0;i<SIZE;i++){
        if(hashTable[i].flag==1)
            printf("\n%d %d",i,hashTable[i].data);
    }
}
void main(){
NODE hashTable[SIZE]={};
int key,ch;
do{
   printf("\nEnter your choice: 1.Insert 2.Delete 3.Search 4.Display 5.Exit:");
   scanf("%d",&ch);
   switch(ch){
    case 1:
        printf("\nEnter the data to be inserted");
        scanf("%d",&key);
        insert(key,hashTable);
        break;
    case 2:
        printf("\nEnter the data to be deleted");
        scanf("%d",&key);
        Delete(key,hashTable);
        break;
    case 3:
        printf("\nEnter the data to be searched");
        scanf("%d",&key);
        search(key,hashTable);
        break;
    case 4:
        display(hashTable);
        break;
    default:
        return;
   }
}while(ch>0 && ch<5);
}
