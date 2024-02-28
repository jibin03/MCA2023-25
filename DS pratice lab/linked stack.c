#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
void push(int x)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=top;
	top=newnode;
}

void peek()
{
	
	if(top==NULL)
	{
		printf("stack underflow");
	}
	else
	{
		printf("\ntop element is %d",top->data);
	}
	
}
void pop()
{
	struct node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("underflow");
	}
	else
	{
		printf("\npopped element is %d",top->data);
		top=top->next;
		free(temp);
		
	}
}
int menu()
{
    int ch;
    printf("\nPush - 1\nPeek - 2\nPop - 3\nExit - 4\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    return ch;
}

void main()
{
    int ch,a;
    for(ch = menu();ch != 4;ch = menu())
    {
        switch(ch)
        {
            case 1 : printf("Enter an element to insert : ");
            		 scanf("%d",&a);
					 push(a);
                     break;
            case 2 : peek();
                     break;
            case 3 : pop();
                     break;
            default : printf("Wrong Choice!!!\n");
                      break;
        };
    }
}

