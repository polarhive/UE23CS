#include<stdio.h>
#include<stdlib.h>

struct trie{
struct trie *child[255];
int eos;
};
struct stack{
 struct trie *node;
 int index;
};
typedef struct stack Stack;
char output[30];
int len=0,top=-1;
Stack* STACK[30];
typedef struct trie Trie;
void push(Trie *t,int index){
    Stack *nn=(Stack*)malloc(sizeof(Stack));
    nn->node=t;
    nn->index=index;
    STACK[++top]=nn;
}
Stack* pop()
{
    return STACK[top--];
}
int ChildCount(Trie *t)
{
    int count=0;
    for(int i=0;i<256;i++)
    {
        if(t->child[i]!=NULL)
            count++;
    }
    return count;
}
Trie* createNode()
{
    Trie *nn=(Trie*)malloc(sizeof(Trie));
    for(int i=0;i<255;i++)
        nn->child[i]=NULL;
    nn->eos=0;
    return nn;
}
void insertWord(char *word,Trie *root)
{
    int index;
    Trie *t=root;
    for(int i=0;word[i]!='\0';i++)
    {
        index=word[i];//word[i]-'a' - 26 pointers
        if(t->child[index]==NULL)
            t->child[index]=createNode();
        t=t->child[index];
    }
    t->eos=1;
}
void display(Trie *root){
    Trie *t=root;
    for(int i=0;i<255;i++)
    {
        if(t->child[i]!=NULL)
        {
            output[len++]=i;//i+'a' =>26 pointers
            if(t->child[i]->eos==1)
            {
                printf("\n");
                for(int j=0;j<len;j++)
                    printf("%c",output[j]);
            }
            display(t->child[i]);
        }
    }
    len--;
    return;
}
void search(char *word,Trie *root){
    int index;
    Trie *t=root;
    for(int i=0;word[i]!='\0';i++){
      index=word[i];
      if(t->child[index]==NULL){
          printf("\nData not found");
          return;
      }
      t=t->child[index];
    }
    if(t->eos==1)
       printf("\nData found");
    else
        printf("\nData not found");
    return;
}
void deleteData(char *word,Trie *root){
    int index;
    Stack *s;
    Trie *t=root;
    for(int i=0;word[i]!='\0';i++){
      index=word[i];
      if(t->child[index]==NULL){
          printf("\nData not found");
          return;
      }
      push(t,index);
      t=t->child[index];
    }
    t->eos=0;
    if(ChildCount(t)>=1)
        return;
    else{
        s=pop();
        t=s->node;
        index=s->index;
        while(ChildCount(t)<=1 && t->eos==0){
            free(t->child[index]);
            t->child[index]=NULL;
            s=pop();
            t=s->node;
            index=s->index;
        }
    }
}
void main()
{
    Trie *root;
    int ch;
    char word[30];
    root=createNode();
    do{
    printf("\nEnter your choice 1.Insert 2.Display 3.Search 4. Display 5.exit:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("\nEnter the word to be inserted:");
        scanf("%s",word);
        insertWord(word,root);
        break;
    case 2:
        len=0;
        display(root);
        break;
    case 3:
        printf("\nEnter the word to be searched:");
        scanf("%s",word);
        search(word,root);
        break;
    case 4:
        printf("\nEnter the word to be deleted:");
        scanf("%s",word);
        deleteData(word,root);
        break;
    default:
        return;
    }
    }while(ch);

}
