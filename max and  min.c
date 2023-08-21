#include <stdio.h>
int main()
{
	int a[10],i,n,max,min;
	printf("enter the array size :");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("enter the elements :");
		scanf("%d",&a[i]);
	
	}
	max=a[0];
	min=a[0];
	 for(i=0;i<n;i++)
	 {
	 	if(a[i]>max)
	 	{
	    	max=a[i];
	    }
	    if(a[i]<min)
	    {
	    	min=a[i];
		}
	     
	 }
	 printf("maximum is %d",max);
	 printf("minimum is%d",min);
	 return 0;
	 
}
