/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>
int a=6;  // global variable

int local()
{
	int b =3; // local variable
	printf("\nenter the value : %d",b);
	return 0;
}

int statics()
{
     static int c=10; 
	 c--;
	 printf("\nenter the value :%d\n",c);
	
	return 0;
}

int registers()
{
	register int sum;
	int a=7;
	int b=8;
	

	sum = a+b;
	printf("sum == %d",sum);
	return 0;
}

int main()
{
	printf("enter the value :%d\n",a);
	local();
	statics();
	statics();
	
	registers();
	
	return 0;

}
