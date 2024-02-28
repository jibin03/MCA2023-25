#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;

void insert(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=e;
		head->next=head;
	}
	else{
		t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->next=head;
	}
}

void display()
{
	struct node *t;
	if(head==NULL)
	{
		printf("Circular linked list is empty");
	}
	else{
		t=head;
		printf("\n");
		do{
			printf("%d\t",t->data);
			t=t->next;
		}while(t!=head);
	}
}
void delete(int e)
{
	struct node *t;
	if(head==NULL)
	{
		printf("\nCircular linked list is empty");

	}
	else if(head->next==head && head->data==e)
	{
		head=NULL;
	}
	else if(head->data==e)
	{
		t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=head->next;
		head=head->next;
	}
	else{
		t=head;
		while(t->next!=head && t->next->data!=e)
		{
			t=t->next;
		}
		if(t->next==head)
		{
			printf("\nElement is not Available");

		}
		else{
			t->next=t->next->next;
		}
	}
}
int menu()
{
    int ch;
    printf("\n1 - Insert\n2 - Display\n3 - Delete\n4 - Exit\n");
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
					 insert(a);
                     break;
            case 2 : display();
                     break;
            case 3 :  printf("Enter an element to delete : ");
            		 scanf("%d",&a);
					 delete(a);
                     break;
            
            default : printf("Wrong Choice!!!\n");
                      break;
        };
    }
    return 0;
}



