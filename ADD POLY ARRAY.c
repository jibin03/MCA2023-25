
#include<stdio.h>
int expres[10],coeres[10], n3;
void read(int exp[],int coe[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i==0)
		   printf("Enter the coefficient and exponent of 1st term : ");
		else if (i==n-1)
		   printf("Enter the coefficient and exponent of last term : ");
        else
		   printf("Enter the coefficient and exponent of next term : ");
        scanf("%d%d",&coe[i],&exp[i]);
	}
}
void disp(int exp[],int coe[],int n)
{   
    int i;
	printf("%dx^%d",coe[0],exp[0]);
	for(i=1;i<n;i++)
	{
	  if(exp[i] == 0)
	  {
	  	if(coe[i] < 0)
	  	
	      printf(" - %d",-coe[i]);
	    else
	  	  printf(" + %d",coe[i]);
	  }
	  else
	  {
	  	if(coe[i] < 0)
	      printf(" - %dx^%d",-coe[i],exp[i]);
	    else
	  	  printf(" + %dx^%d",coe[i],exp[i]);
      }
    }
	
}
mul(int coe1[], int exp1[], int coe2[], int exp2[], int n1, int n2)
{   
    int i,j,k=0;
	for(i=0,j=0; (i<n1 && j<n2) ;)
	{
		if(exp1[i] == exp2[j])
		{
			expres[k] = exp1[i];
			coeres[k] = coe1[i] * coe2[j];
			i++;j++;k++;
		}
		else if (exp1[i] < exp2[j])
		{
			expres[k] = exp2[j];
			coeres[k] = coe2[j];
			j++;k++;
		}
		else
		{
			expres[k] = exp1[i];
			coeres[k] = coe1[i];
			i++;k++;
		}
	}
	if(i<n1)
	{
		for(; i<n1 ; i++,k++)
		{
			expres[k] = exp1[i];
			coeres[k] = coe1[i];
		}
	}
	else if(j<n2)
	{
		for( ;j<n2 ; j++,k++)
		{
			expres[k] = exp2[j];
			coeres[k] = coe2[j];
		}
	}
	n3 = k;
}
sort(int exp[], int coe[],int n)
{
	int a,i,j;
	 for (i = 0; i < n; ++i)
        {
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (exp[i] < exp[j]) 
                {
 
                    a =  exp[i];
                    exp[i] = exp[j];
                    exp[j] = a;
                    a =  coe[i];
                    coe[i] = coe[j];
                    coe[j] = a;
 
                }
 
            }
        }
 
}
void main(){
	int exp1[10],exp2[10],coe1[10],coe2[10], n1,n2,i;
	printf("Enter the number of terms of 1st polynomial : ");
	scanf("%d",&n1);
	printf("Enter the terms of 1st polynomial\n");
	read(exp1,coe1,n1);
	printf("Enter the number of terms of 2nd polynomial : ");
	scanf("%d",&n2);
	printf("Enter the terms of 2nd polynomial\n");
	read(exp2,coe2,n2);
	sort(exp1,coe1,n1);
	sort(exp2,coe2,n2);
	printf("\n1st polynomial is \n");
	disp(exp1,coe1,n1);
	printf("\n2nd polynomial is \n");
	disp(exp2,coe2,n2);
	mul(coe1,exp1,coe2,exp2,n1,n2);
	printf("\nResult polynomial is \n");
	disp(expres,coeres,n3);
}
