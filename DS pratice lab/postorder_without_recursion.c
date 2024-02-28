#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;

struct Stack {
    Node* node;
    struct Stack* next;
};
typedef struct Stack Stack;

Node* root = NULL;
Stack* top = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(int e) {
    Node* p;
    Node* x;
    if (root == NULL) {
        root = createNode(e);
    }
    else {
        p = root;
        while (p != NULL) {
            x = p;
            if (p->data > e)
                p = p->left;
            else
                p = p->right;
        }
        if (x->data < e) {
            x->right = createNode(e);
        }
        else {
            x->left = createNode(e);
        }
    }
}

void push(Node* t, Stack** top) {
    Stack* temp = (Stack*)malloc(sizeof(Stack));
    temp->node = t;
    temp->next = *top;
    *top = temp;
}

Node* pop(Stack** top) {
    Node* t = NULL;
    if (*top != NULL) {
        t = (*top)->node;
        *top = (*top)->next;
    }
    return t;
}

void postOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    Stack* stack1 = NULL;
    Stack* stack2 = NULL;
    push(root, &stack1);

    while (stack1 != NULL) {
        Node* node = pop(&stack1);
        push(node, &stack2);

        if (node->left)
            push(node->left, &stack1);
        if (node->right)
            push(node->right, &stack1);
    }

    while (stack2 != NULL) {
        Node* node = pop(&stack2);
        printf("%d\t", node->data);
    }
}

void postorder(Node *r) {
    if (r != NULL) {
        postorder(r->left);
        postorder(r->right);
        printf("%d\t", r->data);
    }
}

void preorder(Node *r) {
    if (r != NULL) {
        printf("%d\t", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void inorder(Node* r) {
    if (r != NULL) {
        inorder(r->left);
        printf("%d\t", r->data);
        inorder(r->right);
    }
}

int main() {
    insert(15);
    insert(10);
    insert(23);
    insert(5);
    insert(2);
    insert(9);
    insert(17);

    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal:\n");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal (Recursive):\n");
    postorder(root);
    printf("\n");

    printf("Postorder Traversal (Non-Recursive):\n");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
