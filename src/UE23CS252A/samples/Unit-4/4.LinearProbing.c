#include<stdio.h>
#define SIZE 10

typedef struct node{
    int data;
    int flag;//0 or 1
}NODE;
//Insert the data
void insert(int key,NODE *hashTable){
    int hash,i=0;
    hash=((key%SIZE)+i)%SIZE;
    while(hashTable[hash].flag!=0 && i<SIZE){
        i++;//increment No. of collisions
        hash=((key%SIZE)+i)%SIZE; //New hash value
    }
    if(hashTable[hash].flag==0){
        hashTable[hash].data=key;
        hashTable[hash].flag=1;
        printf("The data %d is inserted at %d",key,hash);
    }
    else
        printf("\nData cannot be inserted");

}
void search(int key,NODE *hashTable){
    int hash,i=0;
    hash=((key%SIZE)+i)%SIZE;
    while(i<SIZE){
        if(hashTable[hash].data!=key && hashTable[hash].flag==1){
            i++;
            hash=((key%SIZE)+i)%SIZE;
        }
        else if(hashTable[hash].data==key && hashTable[hash].flag==1){
            printf("\nThe data %d is found at location %d",key,hash);
            return;
        }
        else
            break;
    }
    printf("\nThe data is not Found");
    return;
}
void Delete(int key,NODE *hashTable){
    int hash,i=0;
    hash=((key%SIZE)+i)%SIZE;
    while(i<SIZE){
        if(hashTable[hash].data!=key && hashTable[hash].flag==1){
            i++;
            hash=((key%SIZE)+i)%SIZE;
        }
        else if(hashTable[hash].data==key && hashTable[hash].flag==1){
            hashTable[hash].flag=0;
            hashTable[hash].data=99999;
            return;
        }
        else
            break;
    }
    printf("\nThe data is not Found");
    return;
}
void display(NODE *hashTable){
    for(int i=0;i<SIZE;i++){
        if(hashTable[i].flag==1){
            printf("\n%d %d",i,hashTable[i].data);
        }
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

