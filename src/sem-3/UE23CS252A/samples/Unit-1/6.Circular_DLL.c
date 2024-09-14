#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;

typedef struct header{
    Node *head;
    Node *last;
    int count;
}Header;

Node* createNode(int data)
{
    Node *nn=(Node*)malloc(sizeof(Node));
    nn->data=data;
    nn->next=NULL;
    nn->prev=NULL;
    return nn;
}
Header* createFirstNode(Header *l1,int data){
    Node *nn=createNode(data);
    l1->head=nn;
    l1->last=nn;
    l1->head->prev=l1->last;
    l1->last->next=l1->head;
    l1->count=1;
    return l1;
}
Header* insert_start(Header *l1,int data){
    Node *nn;
    if(l1->head==NULL)//Empty List
    {
        l1=createFirstNode(l1,data);
    }
    else{
    nn=createNode(data);
    nn->next=l1->head;
    nn->prev=l1->last;
    l1->head->prev=nn;
    l1->last->next=nn;
    l1->head=nn;
    (l1->count)++;}
    return l1;
}
Header* insert_end(Header *l1,int data){
    Node *nn;
    if(l1->head==NULL)//Empty List
    {
        l1=createFirstNode(l1,data);
    }
    else{
    nn=createNode(data);
    nn->next=l1->head;
    nn->prev=l1->last;
    l1->head->prev=nn;
    l1->last->next=nn;
    l1->last=nn;
    (l1->count)++;}
    return l1;
}
Header* insert_pos(Header *l1,int data,int pos){
    Node *temp=l1->head,*nn;
    nn=createNode(data);
    for(int i=1;i<pos-1;i++)
        temp=temp->next;
    nn->next=temp->next;
    nn->prev=temp;
    temp->next=nn;
    nn->next->prev=nn;
    (l1->count)++;
    return l1;
}
Header* delete_start(Header *l1){
    Node *temp=l1->head;
    if(l1->head==NULL)
        printf("\nThe List is Empty:Cannot delete");
    else if(l1->head==l1->last){
        free(temp);
        l1->head=l1->last=NULL;
        (l1->count)--;
    }
    else{
        l1->head=l1->head->next;//head to second node
        l1->head->prev=l1->last;
        l1->last->next=l1->head;
        temp->next=temp->prev=NULL;
        free(temp);
        (l1->count)--;
    }

    return l1;
}
Header* delete_end(Header *l1){
    Node *temp=l1->last;
    if(l1->head==NULL)
        printf("\nThe List is Empty:Cannot delete");
    else if(l1->head==l1->last){
        free(temp);
        l1->head=l1->last=NULL;
        (l1->count)--;
    }
    else{
        l1->last=l1->last->prev;
        l1->head->prev=l1->last;//CLL
        l1->last->next=l1->head;//CLL
        temp->prev=temp->next=NULL;
        free(temp);
        (l1->count)--;
    }
    return l1;
}
Header* delete_pos(Header* l1,int pos){
    Node *temp=l1->head,*t1;
    for(int i=1;i<pos-1;i++)
        temp=temp->next;
    t1=temp->next;
    temp->next=t1->next;
    t1->next->prev=temp;
    t1->next=t1->prev=NULL;
    free(t1);
    (l1->count)--;
    return l1;
}
void display(Header *l1)
{
    Node *temp=l1->head;
    if(l1->count==0)//l1->head==NULL && l1->last==NULL
        printf("\nThe list is Empty");
    else{
        printf("\n");
        for(int i=1;i<=l1->count;i++){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        //Printing the first element NOT REQUIRED
        printf("* %d",temp->data);
    }
}
int main()
{
    int cont,ch,data,pos;
    Header *l1=(Header*)malloc(sizeof(Header));
    l1->head=NULL;
    l1->last=NULL;
    l1->count=0;
    do{
        printf("\nEnter your choice;");
        printf("\n1.Insertion at the beginning");
        printf("\n2.Insertion at the Position");
        printf("\n3.Insertion at the End");
        printf("\n4.Deletion at the beginning");
        printf("\n5.Deletion at the Position");
        printf("\n6.Deletion at the End");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the data to be inserted:");
                scanf("%d",&data);
                l1=insert_start(l1,data);
                display(l1);
                break;
            case 2:
                printf("\nEnter the data to be inserted:");
                scanf("%d",&data);
                printf("\nEnter the position to be inserted:");
                scanf("%d",&pos);
                if(pos<1 || pos>(l1->count)+1)
                    printf("\nInvalid Position");
                else if(pos==1)
                    l1=insert_start(l1,data);
                else if(pos==(l1->count)+1)
                    l1=insert_end(l1,data);
                else
                    l1=insert_pos(l1,data,pos);
                display(l1);
                break;
            case 3:
                printf("\nEnter the data to be inserted:");
                scanf("%d",&data);
                l1=insert_end(l1,data);
                display(l1);
                break;
            case 4:
                l1=delete_start(l1);
                display(l1);
                break;
            case 5:
                printf("\nEnter the position to be deleted:");
                scanf("%d",&pos);
                l1=delete_pos(l1,pos);
                display(l1);
                break;
            case 6:
                l1=delete_end(l1);
                display(l1);
                break;
            default:
                printf("\nWrong Choice");
        }
        printf("\nPress 1 to continue and 0 to Exit");
        scanf("%d",&cont);
    }while(cont);
return 0;
}
