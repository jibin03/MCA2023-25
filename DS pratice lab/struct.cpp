#include<stdio.h>
struct stud 
{
	int Aage;
	char Aname[20];
	
};
int main()
{
	struct stud A;
	printf("enter age and name :");
	scanf("%d\n%s",&A.Aage,&A.Aname);
	printf("age%d \n name%s",A.Aage,A.Aname);
	return 0;
}

