//taking random numbers and store it into another file
#include <stdio.h>

#include <stdlib.h>

void sort(int a[],int n,FILE *fp)

/*sorting the array elements*/

{

for(int i=0;i<n-1;i++)/*run the loop upto n-1*/

{

    for(int j=0;j< n-i-1;j++)

    {
        if(a[j]>a[j+1])

        {
            int temp=0;

            temp=a[j];/*swap the elements*/

            a[j]=a[j+1];

            a[j+1]=temp;

        }

    }

}

for(int i=0;i<n;i++)

{

    fprintf(fp,"%d ",a[i]);/*writing the array elements int the file 2*/

}
}

int main()

{

int n;

FILE *fp;

fp=fopen("test.txt","w");

if(fp==NULL)

{
    printf("\nFile not created.");
    exit(0);
}

printf("\nEnter number of elements:  ");

scanf("%d",&n);

int a[n];

for(int i=0;i<n;i++)

{
    a[i]=rand()%100;
}

for(int i=0;i<n;i++)

{
    fprintf(fp,"%d ",a[i]);
}

fclose(fp);

fp=fopen("test1.txt","w");

if(fp==NULL)

{
    printf("\nFile not opened.");
    exit(0);
}

sort(a,n,fp);

fclose(fp);
    return 0;

}
