#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node* createNode(int data);
Node* insert_start(Node *head,int data);
Node* insert_pos(Node *head,int data,int pos);
Node* insert_End(Node *head,int data);
void display(Node *head);
Node* delete_start(Node *head);
Node* delete_pos(Node *head,int pos);
Node* delete_End(Node *head);
int search(Node *head,int data);
Node* createNode(int data){
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
Node* insert_start(Node *head,int data){
    Node *temp,*last=head; //2. change
    if(head==NULL)
    {
        head=createNode(data);
        head->next=head;        //1.Change
    }
    else  //Inserting at the start
    {
        temp=createNode(data);
        temp->next=head;
        //3.change
        while(last->next!=head) //To move last pointer to the end
            last=last->next;
        last->next=temp;//
        head=temp;
    }
    return head;
}
Node* insert_pos(Node *head,int data,int pos){
    Node *temp=head,*temp1,*newnode;
    newnode=createNode(data);
    if(head==NULL)//Empty Node Condition
    {
        head=newnode;
        head->next=head;        //1.Change
    }
    else if(head->next==head)//4.Change- One Element Condition
    {
        if(pos>1)
        {
            newnode->next=head;//5.change
            head->next=newnode;
        }
        else
            head=insert_start(head,data);
    }
    else
    {
        if(pos==1)
            head=insert_start(head,data);
        else{
            for(int i=1;i<pos-1;i++)//traversing to pos
            {
                if(temp->next!=head)//6.Change - End Pos
                    temp=temp->next;
            }
            if(temp->next==head)//7.change - last node
            {
                temp->next=newnode;
                newnode->next=head;
            }
            else{ //Insert at Position
            temp1=temp->next;
            newnode->next=temp1;
            temp->next=newnode;
            }
        }
    }
    return head;
}
Node* insert_End(Node *head,int data){
    Node *temp=head;
    Node *newnode=createNode(data);
    if(head==NULL)
    {
        head=newnode;
        head->next=head;        //1.Change
    }
    else{
        while(temp->next!=head)//8.Change
            temp=temp->next;
        temp->next=newnode;
        newnode->next=head; //9.Change
    }
    return head;
}
void display(Node *head)
{
    Node *temp=head;
    if(head==NULL)
        printf("\nThe List is empty");
    else{
        while(temp->next!=head)
        {
            printf("%d->",temp->data);
            temp=temp->next; //Important otherwise infinite loop
        }
        printf("%d",temp->data);
    }
}

int main(){
    Node *head=NULL;
    int cont,ch,data,pos;
    do{
        printf("\nEnter your choice;");
        printf("\n1.Insertion at the beginning");
        printf("\n2.Insertion at the Position");
        printf("\n3.Insertion at the End");
        printf("\n4.Deletion at the beginning");
        printf("\n5.Deletion at the Position");
        printf("\n6.Deletion at the End");
        printf("\n7.Search for the data");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("\nEnter the data to be inserted:");
                scanf("%d",&data);
                head=insert_start(head,data);
                display(head);
                break;
            case 2:
                printf("\nEnter the data to be inserted:");
                scanf("%d",&data);
                printf("\nEnter the position to be inserted:");
                scanf("%d",&pos);
                head=insert_pos(head,data,pos);
                display(head);
                break;
            case 3:
                printf("\nEnter the data to be inserted:");
                scanf("%d",&data);
                head=insert_End(head,data);
                display(head);
                break;
            case 4:
                head=delete_start(head);
                display(head);
                break;
            case 5:
                printf("\nEnter the position to be deleted:");
                scanf("%d",&pos);
                head=delete_pos(head,pos);
                display(head);
                break;
            case 6:
                head=delete_End(head);
                display(head);
                break;
            case 7:
                printf("\nEnter the data to be searched: ");
                scanf("%d",&data);
                pos=search(head,data);
                if(pos>0)
                    printf("\nThe data is found at position %d",pos);
                else
                    printf("\nThe data is not found");
                break;
            default:
                printf("\nWrong Choice");
        }
        printf("\nPress 1 to continue and 0 to Exit");
        scanf("%d",&cont);
    }while(cont);
    return;
}

Node* delete_start(Node *head){
    Node *temp=head,*last=head;
    if(head==NULL){
        printf("\nThe List is Empty");
    }
    else{
        while(last->next!=head)//Change 10-last pointing to last node
            last=last->next;
        head=head->next;
        last->next=head;//Change 11.Last node-> next to new head
        temp->next=NULL;
        free(temp);

    }
    return head;
}
Node* delete_pos(Node *head,int pos){
    Node *temp1=head,*temp2;
    if(head==NULL){
        printf("\nThe List is Empty");
    }
    else if(head->next==head)//Change
    {
        head=NULL;
        free(temp1);
    }
    else{
        for(int i=1;i<pos-1;i++){
            if(temp1->next!=head)//change
                temp1=temp1->next;
        }
        if(temp1->next==head){     //Change
            head=delete_End(head);
        }
        temp2=temp1->next;
        //code to delete
        temp1->next=temp2->next;
        temp2->next=NULL;
        free(temp2);
    }
    return head;
}

Node* delete_End(Node *head){
    Node *t1=head,*t2;
    if(head==NULL)
        printf("\nList is Empty");
    else if(head->next==head)//change
    {
        head=NULL;
        free(t1);
    }
    else{
        while(t1->next->next!=head)//change
        {
            t1=t1->next;
        }
        t2=t1->next; //free(t1->next)
        t1->next=head;//Change
        free(t2);
    }
return head;
}
int search(Node *head,int data){
    int pos=0;
    Node *temp=head;
 if (head==NULL){
     printf("The List is Empty");
     return 0;
 }
 do{
    pos++;
    if(temp->data==data){
        return pos;
    }
    temp=temp->next;
 }while(temp!=head);//change
 return 0;
}
