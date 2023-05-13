#include<stdio.h>

#include<stdlib.h>

#include<time.h>

//Calculating time taken for bubblesort by using linked list

typedef struct Node/*Creating an structure of data and address*/

{
    int data;
    struct Node *next;

}*node;

node insertend(node newnode,node head,node temp);

node insertend1(int);

void bubblesort(node);

node head=NULL,prev=NULL,net=NULL,cur=NULL,newnode,temp1,temp,newnode1,head1=NULL;


int main()

{
  int a[200];

  FILE *fp;

  time_t t1,t2,t;/*initialize the variables t1,t2,t*/

  fp=fopen("file3.txt","w");/*creating a file with name file3 in write mode*/

    for(int i=0;i<100;i++)

    {
      head=insertend(newnode,head,temp);/*Creating a linked list with 100 random numbers*/
    }

    temp=head;

    while(temp!=NULL)/*traversing linked list upto  temp becomes NULL */

    {
        fprintf(fp,"%d ",temp->data);/*Inserting 100 numbers into file3*/

        temp=temp->next;/*moving the temp pointer*/
    }

    fclose(fp);/*closing the file*/

     FILE *fp1;

     fp1=fopen("file3.txt","r");/*Opening the Existing file3 in read mode*/

     int x;

     for(int i=0;i<100;i++)

     {
         fscanf(fp1,"%d",&x);/*Reading the elements from the file in x variable */

         head1=insertend1(x);/*Inserting the elements from the file into the new linked list*/
     }

    t1=time(NULL);/*storing initial time in t1 variable*/

    bubblesort(head1);/*sorting the linked list in ascending order */

    t2=time(NULL);/*storing file time in t2 variable*/

     FILE *fp2 ;/*declaring the fp2 pointer*/

     fp2=fopen("file4.txt","w");/*creating a file with name file4  in write mode*/

     temp=head1;

     while(temp!=NULL)/*traversing linked list upto  temp becomes NULL */

     {
         fprintf(fp2,"%d ",temp->data);/*copy the elements from the sorted linked list into the file4*/
         temp=temp->next;/*moving the temp pointer*/
     }

     t=t2-t1;/*Calculating total time required for bubblesort in linked list*/

     printf("\nTime taken: %d",t);/*printing the time on the console*/

    fclose(fp1);

    fclose(fp2);/*closing the file*/

}

void bubblesort(node head1)/*function declaration*/

{

     int t;

     node temp,cur;

     temp=head1;

     while(temp!=NULL)

     {

         cur=temp->next;

         while(cur!=NULL)

         {

             if(temp->data>cur->data)

             {
                 t=temp->data;

                 temp->data=cur->data;

                 cur->data=t;
             }

             cur=cur->next;

         }

         temp=temp->next;

     }

}
node getnode(node newnode)

{
    newnode=(node) malloc(sizeof(struct Node));/*creating a single list by using dynamic memory allocation*/

    if(newnode==NULL)

    {
        printf("Memory is not allocated\n");
    }

    else

    {
        return newnode;
    }

}

node readdetails(node newnode)

{
    newnode->data=rand()%100;/*reading the random numbers and storing it into newnode->data*/

    newnode->next=NULL;

    return newnode;
}

node insertend(node newnode,node head,node temp)

{
    newnode=getnode(newnode);

    newnode=readdetails(newnode);

    if(head==NULL)

    {
        head=newnode;

        return head;
    }

    else

    {
        temp=head;

        while(temp->next!=NULL)/*traversing linked list upto  temp->next becomes NULL */

        {
            temp=temp->next;/*moving the temp to next pointer*/
        }

            temp->next=newnode;

        return head;/*returning the head pointer*/

    }

}

node insertend1(int x)

{
    newnode1=getnode(newnode1);

    newnode1->data=x;

    newnode1->next=NULL;

    if(head1==NULL)

    {
        head1=newnode1;

        return head1;/*returning the head1 pointer*/
    }

    else

    {
        temp=head1;

        while(temp->next!=NULL)/*traversing linked list upto  temp->next becomes NULL */

        {
            temp=temp->next;/*moving the temp to next pointer*/
        }

            temp->next=newnode1;

        return head1;/*returning the head1 pointer*/

    }

}
