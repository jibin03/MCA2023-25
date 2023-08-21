#include<stdio.h>
int a[10],i,n;
int main()
{
	printf("enter the array size :");
	scanf("%d",&n);
	printf("enter array elements");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
		printf("\narray elements are :");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
		printf("\n even position elements : %d ",a[i]);
	for(i=n;i<n;i+=2)
	{
		printf("%d ",a[i]);
	}
	
	return 0;
}


