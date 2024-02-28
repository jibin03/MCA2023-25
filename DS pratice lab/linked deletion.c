  //Linked List Deletion

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert(int element)
{
	struct node *temp;
	if(head == NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=element;
		head->next=NULL;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;//traversing
		}
		temp->next=(struct node *)malloc(sizeof(struct node));
		temp->next->data=element;
		temp->next->next=NULL;
	}
}

void delete_beg()
{
	if(head == NULL)
	{
		printf("Linked List is empty");
	}
	else
	{
		head=head->next;
	}
}

void delete_end()
{
	struct node *temp;
	temp=head;
	if(head == NULL)
	{
		printf("Linked List is empty");
	}
	else if(head->next==NULL)                                                                                    // with one element.
	{
		head=NULL;
	}
	else
	{
		while(temp->next->next!=NULL)	                                                                       //more than one element.
		{
			temp=temp->next;
		}
		temp->next=NULL;
	}
}

void delete_pos(int e)
{
	struct node *temp;
    flag=0;
	temp=head;
	if(head == NULL)
	{
		printf("Linked List is empty");
	}
	else if(head->data==e)//
    {
        head=head->next;
    }
	else
    {
        while(temp->next!=NULL)
        {
            if(temp->next->data==e)
            {
                temp->next=temp->next->next;
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==0)
            printf("Entered element not found!");
    }
}
		
void display()
{
	struct node *temp=head;
	if(head == NULL)
	{
		printf("Linked List is empty");
	}
	else
	{
		printf("\nLinked List Elements are: ");
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
				delete_beg();
				break;
			
			case 3 :
			     
				/* printf("\nEnter elements to delete at the end :");
				 scanf("%d",&e);*/
				 delete_end();
				 break;
			
			case 4 :
			     printf("\nEnter the element to search :");
				 scanf("%d",&e);
				 delete_pos(e);
				 break;
			
			case 5 :
			     display();
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


