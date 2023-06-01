#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct Queue
{
    int data[SIZE];
    int front;
    int rear;
}k;

int main()
{
    k p[10],*qp;
    qp=&p;
    int item,op,j,h,n,y,x;
    qp->front=-1;
    qp->rear=-1;
    printf("Enter the no of random numbers\n");
    scanf("%d",&n);
    printf("Enter the range of random numbers\n");
    scanf("%d %d",&j,&y);
    FILE  *fp1=fopen("rNoQueue4.txt","w");

    for(int i=0;i<n;i++)
    {
        item=rand()%(y-j);
        fprintf(fp1,"%d ",item);
    }
    fclose(fp1);
    int k;
    FILE *fp2=fopen("rNoQueue4.txt","r");
    while(1)
    {
        printf("Enter the option\n");
        printf(" 1: Enqueue from front\n 2: Enqueue from rear\n 3: Dequeue from front \n 4: Dequeue from rear\n 5:display\n 6: update Queue\n");
        scanf("%d",&op);
        operationdisplay(op);
        switch(op)
        {
            case 1:fscanf(fp2,"%d",&x);
                Enqueue1(qp,x);
                Enqueued(x);
               break;
               case 2:fscanf(fp2,"%d",&x);
                Enqueue2(qp,x);
                Enqueued(x);
               break;
             case 3: h= Dequeue1(qp);
               Dequeued(h);
             break;
             case 4: h= Dequeue2(qp);
               Dequeued(h);
             break;
             case 5: display(qp);
             break;
             case 6: update(qp);
             break;
        }
    }
}
void operationdisplay(int op)
{
  FILE *fp5=fopen("operationQueue4.txt","a");
    char str1[]="Enqueuefront()";
    char str2[]="Enqueuerear()";
    char str3[]="Dequeuefront()";
    char str4[]="Dequeuerear()";
    if(op==1)
    {
        fprintf(fp5,"%s\n",str1);
    }
    else if(op==2)
    {
        fprintf(fp5,"%s\n",str2);
    }
    else if(op==3)
    {
        fprintf(fp5,"%s\n",str3);
    }
    else if(op==4)
    {
        fprintf(fp5,"%s\n",str4);
    }
    fclose(fp5);
}

void Enqueued(int k)
{
    FILE *fp2=fopen("Enqueued4.txt","a");
    fprintf(fp2,"%d ",k);
    fclose(fp2);
}
void Dequeued(int item)
{
      FILE *fp4=fopen("Dequeue4.txt","a");
      fprintf(fp4,"%d ",item);
     fclose(fp4);
}


void Enqueue1(k *qp,int item)
{
    if( qp->front==-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        qp->data[qp->front]=item;
        qp->front--;
    }
}
void Enqueue2(k *qp,int item)
{
    if( qp->rear==SIZE-1)
    {
       printf("Queue is full\n");
    }
    else
    {
        if(qp->front==-1)
        {
            qp->front=0;
        }
        qp->rear++;
        qp->data[qp->rear]=item;
    }
}

int Dequeue1(k *qp)
{
    int x=-1;
    if(qp->front==qp->rear)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        x=qp->data[qp->front];
        qp->front++;
        return x;
    }
}
int Dequeue2(k *qp)
{
    int x=-1;
    if(qp->rear==-1)
    {
        printf("Queue is empty\n");
        return 0;
    }
    else
    {
        x=qp->data[qp->rear];
        qp->rear--;
        return x;
    }
}

void display(k *qp)
{
    if(qp->rear==-1 || qp->front==qp->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i;

        for(i=qp->front;i<=qp->rear;i++)
        {
            printf("%d ",qp->data[i]);
        }
    }
}
void queueFile(int x)
{
    FILE *fp=fopen("Queuefile4.txt","a");
    fprintf(fp,"%d ",x);
    fclose(fp);
}

void update(k *qp)
{
    int i;
    for(int i=qp->front;i<=qp->rear;i++)
        {
            queueFile(qp->data[i]);
        }
}

