#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
 

struct node *root=NULL;

struct stack{
	struct node *r;
	struct stack *next;
};

struct stack *top=NULL;

void insert(int e)
{
	struct node *p,*x;
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node));
		root->data=e;
		root->left=NULL;
		root->right=NULL;
	}
	else{
		p=root;
		while(p!=NULL)
		{
			x=p;
			if(p->data>e)
			{
				p=p->left;
			}
			else{
				p=p->right;
			}
		}
		if(x->data<e)
		{
			x->right=(struct node *)malloc(sizeof(struct node));
			x->right->data=e;
			x->right->left=NULL;
			x->right->right=NULL;
		}
		else{
			x->left=(struct node*)malloc(sizeof(struct node));
			x->left->data=e;
			x->left->left=NULL;
			x->left->right=NULL;
		}
	}
}

void push(struct node *t)
{
	struct stack *temp=(struct stack *)malloc(sizeof(struct stack));
	temp->r=t;
	temp->next=top;
	top=temp;
}

struct node *pop()
{
	struct node *t=NULL;
	if(top!=NULL)
	{
		t=top->r;
		top=top->next;
	}
	return t;
}


void inorderwor(struct node *r)
{
	struct node *t;
	for(t=root;t!=NULL;t=t->left)
	{
		push(t);
	}
	t=pop();
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		for(t=t->right;t!=NULL;t=t->left)
		{
			push(t);
		}
		t=pop();
	}	
}

int main()
{
	insert(100);
	insert(60);
	insert(150);
	insert(200);
	insert(75);
	insert(50);
	insert(250);
	insert(90);
	inorderwor(root);
	return 0;
}

