#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node tree;
tree *root = NULL;

void insert(int e)
{
    tree *p,*x,*t;
    if(root==NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        root->data=e;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        p=root;
        while(p!=NULL)
        {
            x=p;
            if(p->data > e)
                p=p->left;
            else if(p->data < e)
                p=p->right;
            else
            {
                printf("Repeated value not allowed\n\n");
                return;
            }
        }
        t=(tree *)malloc(sizeof(tree));
        t->data=e;
        t->right=NULL;
        t->left=NULL;
        if(x->data < e)
            x->right = t;
        else
            x->left = t;
        
    }
}

void inorder(tree *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d\t",r->data);
        inorder(r->right);
    }
}

void delete(int e)
{
	tree *p,*x,*t;
	p=NULL;
	x=root;
        while(x!=NULL) //to find the position at which to be delete is found.if the given element is found to be left or right then the value 
		              // of x is given to p.and x will traverse to the element we need.
        {
            if(x->data == e) // it means that the element to be deleted is the root node thus we find th position of the element then we break the loop
            	break;
            else if(x->data > e)
            {
            	p=x;
            	x=x->left;
			} 
            else if(x->data < e)
            {
            	p=x;
				x=x->right;
			}      
        }
        if(x==NULL)
        	printf("Element not found\n");
        else 
        {
        	if(x->left == NULL && x->right == NULL) //Node with No children
        	{
        		if(x == root)
        			root=NULL;
        		else if(p->right == x)
        			p->right = NULL;
        		else
        			p->left = NULL;
			}
			else if(x->left == NULL || x->right == NULL) //Node with 1 child
			{
				if(x == root) //Root
				{
					root = (x->right != NULL) ?  x->right : x->left;  //conditional operator
				}
				else if(p->left == x) 
				{
					if(p->left->left != NULL) //left left
						p->left=x->left;
					else					//left right
						p->left = x->right;
				}
				else
				{
					if(p->right->right!=NULL) //right right
						p->right=x->right;
					else						//right left
						p->right=x->left;
				}
			}
			else //node with two children
			{
				tree *t=x->right;
				while(t->left!=NULL)
					t=t->left;
				delete(t->data);
				x->data = t->data;
			}
			
		}
}

int main()
{
    insert(50);
   	insert(40);
    insert(100);
    insert(30);
    insert(45);
    insert(70);
    insert(150);
    insert(20);
    insert(35);
    insert(42);
    insert(48);
    inorder(root);
    printf("\n");
    delete(50);
    delete(150);
    delete(48);
    delete(45);
    delete(30);
    delete(40);
    delete(20);
    delete(35);
    delete(42);
    delete(70);
    printf("\n");
    inorder(root);
	printf("\n");
	return 0;
	}


