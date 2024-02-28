#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	
};
struct node *head=NULL;
void insert_begin(int e)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=e;
	newnode->next=head;
	head=newnode;
}
void insert_end(int e)
{
	struct node *temp;
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=e;
		head->next=NULL;
	}
	else
	{
		temp=head;
		while(temp->next != NULL)
		{
		temp=temp->next;
	    }
		temp->next=(struct node*)malloc(sizeof(struct node));
		temp->next->data=e;
		temp->next->next=NULL;
	}
}

void insert_after(int e)
{
	struct node *temp,*temp1;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL&& temp->data!=e)
		{
			temp=temp->next;
		}
		if(temp==NULL)
		{
			printf("element not found\n");
		}
		else if(temp->data==e)
		{
			printf("element found\n");
			printf("enter the element to be inserted\n",e);
			int new_e;
			scanf("%d",&new_e);
			temp1=(struct node*)malloc(sizeof(struct node));
			temp1->data=new_e;
			temp1->next=temp->next;
			temp->next=temp1;

		}
	}
}

void disp()
{
	struct node * temp;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		temp=head;
		printf("the elements are  :");
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
	printf("\n");
}

int menu()
{
	int ch;
	printf("\n 1. INSERTION AT BEGINNING\n 2. INSERTION AT END\n 3. INSERTION ONE AFTER THE ANOTHER\n 4. DISPLAY\n 5. EXIT\n ENTER YOUR CHOICE  :");
	scanf("%d",&ch);
	return ch;
}

int main()
{
	int ch;
	for(ch=menu();ch!=5;ch=menu())
	{
		switch(ch)
		{
			case 1:
				printf("\nEnter element to insert at beginning :");
				scanf("%d",&ch);
				insert_begin(ch);
				break;
			
			case 2 :
			    
				 printf("\nEnter elements to insert at the end :");
				 scanf("%d",&ch);
				 insert_end(ch);
				 break;
			
			case 3 :
			     printf("\nEnter the element to search :");
				 scanf("%d",&ch);
				 insert_after(ch);
				 break;
			
			case 4 :
			     disp();
				 break;
				 
			case 5:
			     printf("\nExit");
				 break;
			default:
				 printf("\nwrong choice");
				 break;	 	 	 	 	
		}
	}
	return 0;
}
