#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int flag;
}NODE;
int count=0;
NODE* init(NODE *hashTable,int size){
    for(int i=0;i<size;i++){
        hashTable[i].flag=0;
        hashTable[i].data=99999;
    }
    return hashTable;
}
NODE* createTable(NODE *hashTable,int **size){
    NODE *newTable = (NODE*)malloc(2 * (**size) * sizeof(NODE));
    int newSize = 2 * (**size);
    newTable=init(newTable,newSize);
    for(int i=0; i<**size; i++){
        if(hashTable[i].flag == 1){
            insert(hashTable[i].data, newTable, newSize);
        }
    }
    **size = newSize;
    free(hashTable);
    return newTable;
}

void insert(int key,NODE *hashTable,int size){
    int hash,hash2,i=0;
    float loadFactor;
    loadFactor = ((float)(++count) / (size));
    printf("\n%d %d %f",count,size,loadFactor);
    if(loadFactor>0.75){
        printf("****");
        count=0;
        hashTable=createTable(hashTable,&size);
    }
    hash=((key%size)+i)%size;
    while(hashTable[hash].flag==1 && i<size){
        i++;
        hash=((key%size)+i)%size;
        printf("\n***%d***",hash);
    }
    if(hashTable[hash].flag==0){
        hashTable[hash].data=key;
        hashTable[hash].flag=1;
    }
    else{
        printf("Cannot insert the data");
    }
    return;
}
void search(int key,NODE *hashTable,int *size){
    int i=0,hash;
    hash=((key%*size)+i)%*size;
    while(i<*size){
    if(hashTable[hash].data!=key && hashTable[hash].flag==1){
        i++;
        hash=((key%*size)+i)%*size;
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
void Delete(int key,NODE *hashTable,int *size){
    int i=0,hash;
    hash=((key%*size)+i)%*size;
    while(i<*size){
    if(hashTable[hash].data!=key && hashTable[hash].flag==1){
        i++;
        hash=((key%*size)+i)%*size;
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
void display(NODE *hashTable,int *size){
    for(int i=0;i<*size;i++){
        if(hashTable[i].flag==1)
            printf("\n%d %d",i,hashTable[i].data);
    }
}
void main(){
int size;
NODE *hashTable;
int key,ch;
printf("\nEnter the size of the table:");
scanf("%d",&size);
hashTable = (NODE*)malloc((size) * sizeof(NODE));
hashTable=init(hashTable,size);
do{
   printf("\nEnter your choice: 1.Insert 2.Delete 3.Search 4.Display 5.Exit:");
   scanf("%d",&ch);
   switch(ch){
    case 1:
        printf("\nEnter the data to be inserted");
        scanf("%d",&key);
        insert(key,hashTable,&size);
        break;
    case 2:
        printf("\nEnter the data to be deleted");
        scanf("%d",&key);
        Delete(key,hashTable,&size);
        break;
    case 3:
        printf("\nEnter the data to be searched");
        scanf("%d",&key);
        search(key,hashTable,&size);
        break;
    case 4:
        display(hashTable,&size);
        break;
    default:
        return;
   }
}while(ch>0 && ch<5);
}
