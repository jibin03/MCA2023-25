#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node * next;
};
struct node * top=NULL;
void push(int a)
{
	struct node * newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=a;
	newnode->next=top;
	top=newnode;
}
void disp()
{
	struct node* temp;
	temp=top;
	if(top==NULL)
	{
		printf("list is empty");	
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}

void peek()
{
	if(top==NULL)
	{
		printf("stack is empty");
	}
	else
	{
		printf("top element is %d\n",top->data);
	}
}

void pop()
{
	struct node * temp;
	temp=top;
	if(top==NULL)
	{
		printf("stack is underflow");
	}
	else
	{
		printf("popped element is %d\n",temp->data);
		top=temp->next;
		free(temp);
	}
}

int main()
{
push(10);
push(20);
push(30);
push(40);
disp();
peek();
pop();
disp();
pop();
disp();
return 0;
}

