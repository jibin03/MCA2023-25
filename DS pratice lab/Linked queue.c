#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node * next;
};
struct node * front=NULL;
struct node * rear= NULL;
void enqueue(int a)
{
	struct node * newnode;
	newnode= (struct node *)malloc(sizeof(struct node));
	newnode->data= a;
	newnode->next=NULL;
	if(front==NULL)
	{
		front=rear=newnode;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void dequeue()
{
	struct node * temp;
	temp=front;
	if(front==NULL)
	{
		printf("queue is empty");
	}
	else
	{
		printf("\ndequeued element is %d\n",temp->data);
		front=temp->next;
		free(temp);
	}
}

void disp()
{
	struct node * temp;
	if(front==NULL)
	{
		printf("queue in empty");
	}
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
int menu()
{
    int ch;
    printf("\nEnqueue - 1\nDequeue - 2\nDisplay - 3\nExit -4\n ");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    return ch;
}

void main()
{
    int i,ch,a;
    for(ch = menu();ch != 4;ch = menu())
    {
        switch(ch)
        {
            case 1 : printf("Enter an element to insert : ");
            		 scanf("%d",&a);
					 enqueue(a);
                     break;
            case 2 : dequeue();
                     break;
            case 3 : disp();
                     break;
            default : printf("Wrong Choice!!!\n");
                      break;
        };
    }
}


