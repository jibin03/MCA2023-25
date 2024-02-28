#include<stdio.h>
#define MAX 10
int stack[MAX],top=-1;
void push(int e)
{
	if(top+1==MAX)
	{
		printf("stack in overflow");
	}
	else
	{
		stack[++top]=e;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack is underflow");
		
	}
	else
	{
		printf("popped elem is %d",stack[top]);
		stack[top--];
	}
}
void peek()
{
	if(top==-1)
	{
		printf("stack is empty");
		
	}
	else
	{
		printf("peek elem is %d",stack[top]);
	}
}
int main()
{
	push(20);
	push(10);
	push(30);
	push(40);
	peek();
	pop();
	peek();
	return 0;
}

