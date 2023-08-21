
#include<stdio.h>
int a[10],i,n;
int main()
{
	printf("enter the array size :");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
           printf("enter array elements :");
	scanf("%d",&a[i]);
	}
		printf("\n array elements are :");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	
		printf("\n even position elements : %d ",a[i]);
	for(i=0;i<n;i+=2)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

