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
		head->next=head;
		head->prev=head;
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
		t->next->prev=t;
		head->prev=t->next;
	}
}

void display()
{
	struct node *t;
	if(head==NULL)
	{
		printf("\nempty");
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
		printf("\nempty");
	}
	else if(head->next==head && head->data==e)
	{
		head=NULL;
	}
	else if(head->data==e)  
	{
		head->prev->next=head->next;
		head->next->prev=head->prev;
		head=head->next; 
	}
	else{
		t=head->next;
		while(t->next!=head && t->data!=e)
		{
			t=t->next;
		}
		if(t->next==head)
		{
			printf("\nElement not found");
		}
		else
		{
			t->prev->next=t->next;
			t->next->prev=t->prev;
		}
	}
}

int main()
{
	insert(20);
	insert(40);
	insert(10);
	display();
	delete(40);
	display();
	delete(20);
	display();
	delete(10);
	display();
	return 0;
}
