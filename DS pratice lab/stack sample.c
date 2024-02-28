#include<stdio.h>
#define MAX 10
int stack[MAX],top=-1;
void push(int e)
{
	if(top+1==MAX)
	{
		printf("stack overflow");
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
		printf("stack underflow");
	}
	else
	{
		printf("%d popped",stack[top--]);
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
		printf("top is %d",stack[top]);
	}
}

int menu()
{
	int choice;
	printf("\n1.push\n2.pop\n3.peek\n4.exit\nenter your choice :");
	scanf("%d",&choice);
}

void process()
{
	int ch;
	for(ch=menu;ch!=4;ch=menu())
	{
		int a;
		
		switch(ch)
		{
			case 1:
				printf("enter the number");
				scanf("%d",&a);
				push(a);
				break;
				
		
			case 2:
				pop();
				break;
				
			case 3:
				peek();
				break;
				
			default:
			printf("wrong choice");
			break;
		}
	}
}
int main()
{
	 process();
}
