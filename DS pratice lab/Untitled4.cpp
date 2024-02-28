#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*head=NULL;
void insert(int e)
{
	struct node *t;
	if(head ==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=e;
		head->next=NULL;
	}
	else 
	{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
			t->next=(struct node*)malloc(sizeof(struct node));
			t->next->data=e;
			t->next->next=NULL;
		
	}
}

void del_begin()
{
	if(head==NULL)
	{
		printf("empty");
	}
	else
	{
		head=head->next;
	}
	
}
void del_end()
{
	struct node * t;
	if(head==NULL)
	{
		printf("empty");
		
	}
	else if(head->next==NULL)
	{
		head=NULL;
	}
	else
	{
		while(head->next->next!=NULL)
		{
			t=t->next;
		}
		t->next=NULL;
	}
	
}
void del_pos(int e)
{
	struct node*t;
	t=head;
	if(head==NULL)
	{
		printf("empty");
		
	}
	else if(head->data==e)
	{
		head=head->next;
	}
	else
	{
		while(t->next!=NULL)
		{
			if(t->next->data==e){
				t->next=t->next->next;
				
			}
			t=t->next;
		}
	}
}
void disp()
{
	struct node *t=head;
	if(head==NULL)
	{
		printf("empty");
		
	}
	else
	{
		while(t!=NULL)
		{
			printf("%d",t->data);
			t=t->next;
		}
	}
}
int menu()
{
	int ch;
	printf("\n 1.INSERTION OF ELEMENTS \n 2.DELETION AT BEGINNING\n 3. DELETION AT END\n 4. DELETION AT POSITION\n 5. DISPLAY\n 6. EXIT\n ENTER YOUR CHOICE  :");
	scanf("%d",&ch);
	return ch;
}

int main()
{
	int ch,e,n,i;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch(ch)
		{
			case 1:
				printf("element to be inserted");
				scanf("%d",&e);
				insert(e);
				break;
				
			case 2:
				/*printf("\nEnter element to delete at beginning :");
				scanf("%d",&e);*/
				del_begin();
				break;
			
			case 3 :
			     
				/* printf("\nEnter elements to delete at the end :");
				 scanf("%d",&e);*/
				 del_end();
				 break;
			
			case 4 :
			     printf("\nEnter the element to search :");
				 scanf("%d",&e);
				 del_pos(e);
				 break;
			
			case 5 :
			     disp();
				 break;
				 
			case 6:
			     printf("\nExit");
				 break;
				 
			default:
			     printf("wrong choice");//Linked List Deletion
			     break;
			     
		}
	}return 0;
}

