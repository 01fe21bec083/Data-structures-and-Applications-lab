#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    int n,wtg[100000],profit[100000],k,i,j,temp1,temp2,sum1,h;
    float sum,pByw[10000];
    printf("Enter the number of objects\n");
    scanf("%d",&n);
    float a[n];
    for(i=0;i<n;i++)
    {
        a[i]=0;
    }
    printf("Enter the profit for each item serially\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&profit[i]);
    }
    printf("Enter the weights for each item serially\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&wtg[i]);
    }
    for(i=0;i<n;i++)
    {
        pByw[i]=profit[i]/wtg[i];
    }
    printf("enter the maximum capacity of container\n");
    scanf("%d",&k);
    float temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pByw[i]<pByw[j])
            {
                temp=pByw[i];
                pByw[i]=pByw[j];
                pByw[j]=temp;
                temp1=profit[i];
                profit[i]=profit[j];
                profit[j]=temp1;
                temp2=wtg[i];
                wtg[i]=wtg[j];
                wtg[j]=temp2;
            }
        }
    }
    sum=0;
    sum1=0;
    for(i=0;i<n;i++)
    {
        sum1=sum1+wtg[i];
        if(sum1<=k)
        {
           a[i]=1.0;
        }
        else if(sum1>k)
        {
           sum1=sum1-wtg[i];
            h=i;
        }
    }
    float ans=k-sum1;
     a[h]=ans/wtg[h];
     for(i=0;i<n;i++)
    {
        printf("%f ",a[i]);
    }
     for(i=0;i<n;i++)
     {
         sum=sum+(a[i]*profit[i]);
     }

     printf("Maximum profit we get is %f ",sum);
}
