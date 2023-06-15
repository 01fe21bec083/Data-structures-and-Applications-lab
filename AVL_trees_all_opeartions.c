#include<stdio.h>
#include<stdlib.h>

//structure declared for a node
typedef struct Node
{
    struct Node*left;
    int data;
    int height;
    struct Node*right;
}*node;

node root,newnode,head,temp,p,t;
node InsertNode(node ,int);
node deleteNode(node,int);
node balanceCheck(node);
int balancefactor(node);
int NodeHeight(node);
node RRRotation(node);
node LLRotation(node);
node RLRotation(node);
node LRRotation(node);
int main()
{
    int n,key,key1;
    root=NULL;
    while(1)
    {
        printf("Choose the option\n");
        printf(" 1:Insert node\n 2:Preorder\n 3:Postorder\n 4:Inorder\n 5:Delete node\n ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("Enter the element\n");
            scanf("%d",&key1);
                root=InsertNode(root,key1);
            break;
            case 2: preorder(root);
            break;
            case 3: postorder(root);
            break;
            case 4: inorder(root);
            break;
            case 5:printf("enter the key element to be deleted\n");
                  scanf("%d",&key);
                  root=deleteNode(root,key);
                  break;
        }
    }
   return 0;
}

//function for inserting node in  tree
node InsertNode(node p,int key1)
{
    if(p==NULL)
    {
        t=(node)malloc(sizeof(struct Node));
        t->data=key1;
        t->height=1;
        t->left=t->right=NULL;
        return t;
    }
    if(key1<p->data)
    {
       p->left=InsertNode(p->left,key1);
    }
    else if(key1>p->data)
    {
        p->right=InsertNode(p->right,key1);
    }
    p->height=NodeHeight(p);
    p=balanceCheck(p);
    return p;
}

//function for finding inorder successor of the particular node
node inorderSuccesor(node temp)
{
    while(temp->left!=NULL && temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}

//function for delete a node from tree
node deleteNode(node root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Case 1: No child or one child
        if (root->left == NULL)
        {
            node temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Two children
        node temp = inorderSuccesor(root->left);
        root->data = temp->data;
        root->left = deleteNode(root->left, temp->data);
   }
    root->height=Nodeheight(root);
    if(BalanceFactor(root)>1 && BalanceFactor(root->left)>=0)

      {

          root=LLRotation(root);

      }

    else if(BalanceFactor(root)>1 && BalanceFactor(root->left)<0)

    {

        root=LRRotation(root);

    }

    else if(BalanceFactor(root)<-1 && BalanceFactor(root->right)<=0)

    {

       root=RRRotation(root);

    }

    else if(BalanceFactor(root)<-1 && BalanceFactor(root->right)>0)

    {

       root=RLRotation(root);

    }
    return root;
}

//function for preorder traversal
void preorder(node root)
{
    if(root!=NULL)
    {
    printf("%d--->",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

//function for inorder traversal
void inorder(node root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d--->",root->data);
    inorder(root->right);
    }
}

//function for postorder traversal
void postorder(node root)
{
    if(root!=NULL)
    {
    postorder(root->left);
    postorder(root->right);
     printf("%d--->",root->data);
    }
}

//function for finding a height of a particular node
int NodeHeight(node p)
{
 int hl,hr;
 hl=p && p->left?p->left->height:0;
 hr=p && p->right?p->right->height:0;

 return hl>hr?hl+1:hr+1;
}

//function for finding balance factor for a node
int BalanceFactor(node p)
{
 int hl,hr;
 hl=p && p->left?p->left->height:0;
 hr=p && p->right?p->right->height:0;

 return hl-hr;
}

//function for performing LL Rotation if it is LL imbalance
node LLRotation(node p)
{
 node pl=p->left;
 node plr=pl->right;

 pl->right=p;
 p->left=plr;
 p->height=NodeHeight(p);
 pl->height=NodeHeight(pl);

 if(root==p)
   root=pl;

 return pl;
}

//function for performing LR Rotation if it is LR imbalance
node LRRotation(node p)
{
    p->left=RRRotation(p->left);
    p=LLRotation(p);
    return p;
}

//function for performing RR Rotation if it is RR imbalance
node  RRRotation(node p)
{
    node pr=p->right;
    node prr=pr->left;
    pr->left=p;
    p->right=prr;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    if(root==p)
        root=pr;
 return pr;
}

//function for performing RL Rotation if it is RL imbalance
node RLRotation(node p)
{
  p->right=LLRotation(p->right);
  p=RRRotation(p);
  return p;
}

//function for checking if it is LL,LR,RR&RL imbalance or not
node balanceCheck(node p)
{
     if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1)
      {
          p=LLRotation(p);
      }
    else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)
    {
        p=LRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1)
    {
       p=RRRotation(p);
    }
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1)
    {
       p=RLRotation(p);
    }
  return p;
}
