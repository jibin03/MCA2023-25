#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};
struct node * front=NULL;
struct node * rear=NULL;
void enqueue(int e)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=e;
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
	struct node*t=front;
	if(front==NULL)
	{
		printf("empty");
	}
	else
	{
		printf("dq elem is %d",front->data);
		front=front->next;
	}
}
void disp()
{
	struct node * t=front;
	if(front ==NULL)
	{
		printf("empty");
		
	}
	else
	{
		while(t!=NULL)
		{
			printf("elemts r %d",t->data);
			t=t->next;
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

int main()
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
    return 0 ;
}
