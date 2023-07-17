#include<stdio.h>
#include<stdlib.h>

#define size  10
typedef struct Node
{
    struct Node*next;
    int data;
}*node;

node newnode,head=NULL,temp=NULL;
node hash[size];

int hashfun(int x)
{
    return x%size;
}
int main()
{
    int n,x,i,k;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<size;i++)
    {
        hash[i]=NULL;
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the element\n");
        scanf("%d",&x);
        insertend(x);
    }
    print();
    return 0;
}

void insertend(int x)
{
    newnode=(node)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;
    int key=hashfun(x);
    //check if hash[key] is empty
    if(hash[key]==NULL)
    {
        hash[key]=newnode;
    }
    //if hash[key] is non empty
    else
    {
        temp=hash[key];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void print()
{
    int i;
    for(i=0;i<size;i++)
    {
        temp=hash[i];
        printf("hash[%d]-->",i);
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
