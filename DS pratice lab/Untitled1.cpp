#include<stdio.h>
#include<malloc.h>
int main()
{
	int *ptr;
	ptr=(int *)malloc(1*sizeof(int));
	printf("Enter a number : ");
	scanf("%d",ptr);
	printf("The value is %d",*ptr);
	int *ptr2;
	ptr2=(int *)calloc(1,sizeof(int));
	printf("\nEnter a number : ");
	scanf("%d",ptr2);
	printf("The value is %d",*ptr2);
	free(ptr);
	free(ptr2);	
	return 0;
}
