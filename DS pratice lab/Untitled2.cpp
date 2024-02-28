#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	
};
struct node * top=NULL;
void push(int e)
{
	struct node* newnode=NULL;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=e;
	newnode->next=top;
	top=newnode;
	
}
void pop()
{
	if(top==NULL)
	{
		printf("linked stack in underflow");
	}
	else
	{
		printf("popped element is %d\n",top->data);
		top=top->next;
	}
}
void peek()
{
	if(top==NULL)
	{
		printf("linked stack is empty");
		
	}
	else
	{
		printf("peeked element is %d\n",top->data);
		
	}
}
int menu()
{    
    int ch;
	printf("\n1-push\n2-pop\n3-peek\n4-exit\nenter your choice:");
	scanf("%d",&ch);
	return ch;
}
int main()
{
	int ch;
	for(ch=menu();ch!=4;ch=menu())
	{
		switch(ch)
		{
			case 1 : printf("enter the elemnet");
			         scanf("%d",&ch);
			         push(ch);
			         break;
			         
			case 2 : pop();
			         break;
			           
			case 3 : peek();
			         break;
			         
			default :printf("wrong choice");
			         break;
					 
					 return 0;        
			                   
			         
		}
	}
}
