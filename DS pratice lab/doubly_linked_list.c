#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head=NULL;
void insert(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=e;
		head->next=NULL;
		head->prev=NULL;
	}
	else{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=NULL;
		t->next->prev=t;
	}
}

void display()
{
	struct node *t;
	if(head==NULL)
	{
		printf("\nDoubly linked list is empty");
	}
	else{
		t=head;
		printf("\n");
		while(t!=NULL)
		{
			printf("%d\t",t->data);
			t=t->next;
		}
	}
}

void delete(int e)
{
	struct node *t;
	if(head==NULL)
	{
		printf("\nDoubly linked list is empty");
	}
	else if(head->next==NULL && head->data==e)
	{
		head=NULL;
	}
	else if(head->data==e)
	{
		head=head->next;
		head->prev=NULL;
	}
	else{                   //position
		t=head;
		while(t!=NULL && t->data!=e)
		{
			t=t->next;
		}
		if(t==NULL)
		{
			printf("\nElement not found");
		}
		else if(t->next==NULL)             //if e is at last node
		{
			t->prev->next=NULL;
		}
		else{
			t->prev->next=t->next;            // if e is at a node other than last
			t->next->prev=t->prev;
		}
	}
}

int menu()
{
    int ch;
    printf("\nInsert - 1\nDisplay - 2\nDelete - 3\nExit - 4\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    return ch;
}

int main()
{
    int ch,e;
    for(ch = menu();ch != 4;ch = menu())
    {
        switch(ch)
        {
            case 1 : printf("Enter the value to be inserted : ");
            		 scanf("%d",&e);
					 insert(e);
                     break;
            case 2 : display();
                     break;
            case 3 : printf("Enter the value to be deleted : ");
            		 scanf("%d",&e);
					 delete(e);
                     break;
            default : printf("Wrong Choice!!!\n");
                      break;
        };
    }
    return 0;
}
