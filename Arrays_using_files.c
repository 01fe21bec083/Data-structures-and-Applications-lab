//taking input from the file and sorting it and store it in another file.
#include <stdio.h>

#include <stdlib.h>

void print(int a[5])

{

for(int i=0;i<5;i++)

{ printf("%d ",a[i]);/*print the array elements*/ }

}

int main()

{

FILE *fp,*fp1;

int temp;

fp=fopen("file1.txt","w");/*open the new file1 in write mode*/

int a[5],b[5];

int i=0;

printf("enter the array element");

for(i=0;i<5;i++)

{ scanf("%d",&a[i]);/*taking the array elements from the user*/ }

print(a);/*calling the function print*/

for(int i=0;i<5;i++)

{ fprintf(fp,"%d ",a[i]);/*writing the array elements int the file 1*/ }

fclose(fp);/*closing the existing file*/

fp=fopen("file1.txt","r");/*open the file 1 in read mode*/

for(i=0;i<5;i++)

{
 fscanf(fp,"%d",&b[i]);/*reading the elements from the file 1 and taking them in new array b*/
 }
fp1=fopen("file2.txt","w");/*open the new file2 in write mode*/

/*sorting the array elements */

for(i=0;i<5;i++)

{

  for(int j=i+1;j<5;j++)

{
      if(b[j]<b[i])
      {
      temp=b[j];/*swap the elements*/

      b[j]=b[i];

      b[i]=temp;

      }

  }
}

print(b);/*calling the function print*/

for(int i=0;i<5;i++)

{ fprintf(fp1,"%d ",b[i]);/*writing the array elements int the file 2*/ }

fclose(fp);/*closing the existing file 1*/

fclose(fp1);/*closing the existing file 2*/

}
