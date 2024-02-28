#include<stdio.h>
struct datestructure
{
	int date,month,year;
	
};

int comparedates(struct datestructure d1, struct datestructure d2)
{

return d1.date==d2.date && d1.month==d2.month && d1.year==d2.year;
}
int main()
{
	struct datestructure d1,d2;
	printf("enter the first date :");
	scanf("%d/%d/%d",&d1.date,&d1.month,&d1.year);
	
	printf("enter the second date :");
	scanf("%d/%d/%d",&d1.date,&d2.month,&d2.year);

	if (comparedates(d1,d2))
	{
		printf("dates are equal ");
		
	}
	else
	{
		printf("dates are not equal");
	}
	return 0;
}
