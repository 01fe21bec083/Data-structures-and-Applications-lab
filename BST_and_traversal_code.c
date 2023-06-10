#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    struct Node*left;
    int data;
    struct Node*right;
}*node;

node root,newnode,head,temp;
node InsertNode(node ,node);
node getnode(node);
int main()
{
    int n;
    root=NULL;
    while(1)
    {
        printf("Choose the option\n");
        printf("1:Insert node\n 2:Preorder\n 3:Postorder\n 4:Inorder\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:newnode=getnode(newnode);
                root=InsertNode(root,newnode);
            break;
            case 2: preorder(root);
            break;
            case 3: postorder(root);
            break;
            case 4: inorder(root);
            break;
        }
    }
   return 0;
}

node getnode(node newnode)
{
    int item;
    newnode=(node) malloc(sizeof(struct Node));
    printf("Enter the data\n");
    scanf("%d",&item);
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=item;
    return newnode;
}

node InsertNode(node root,node newnode)
{
    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        if(newnode->data<root->data)
        {
           root->left=InsertNode(root->left,newnode);
        }
        else if(newnode->data>root->data)
        {
            root->right=InsertNode(root->right,newnode);
        }
    }
    return root;
}

void preorder(node root)
{
    if(root!=NULL)
    {
    printf("%d--->",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}
void inorder(node root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d--->",root->data);
    inorder(root->right);
    }
}
void postorder(node root)
{
    if(root!=NULL)
    {
    postorder(root->left);
    postorder(root->right);
     printf("%d--->",root->data);
    }
}

