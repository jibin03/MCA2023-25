#include<stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int e) {
	
	if( top + 1 == MAX ) {
		printf("Stack overflow !!");
	}
	else {
		stack[++top] = e;
	}
}

void pop() {
	
	if(top == -1) {
		printf("Stack underflow");
	}
	else {
		printf(" %d Popped", stack[top--]);
	}
}

void peek() {
	
	if( top == -1 ) {
		printf("stack empty");
	}
	else {
		printf("top is %d", stack[top]);
	}
}

int menu() {
	
	int choice;
	
	printf("\n\n1. Push \n2. Pop \n3. Peek \n4.exit \n Enter your choice : ");
	scanf("%d", &choice);
	
	return choice;
}

void process() {
	
	int ch;
	
	for(ch = menu(); ch != 4; ch = menu() ) {
		int a;
		
		switch(ch) {
			
			case 1:
				printf("Enter a number : ");
				scanf("%d", &a);
				push(a);
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				peek();
				break;
				
			default:
				printf("Wrong choice !");
				break;
		}
	}
	
}

int main() {
	
	process();
	return 0;
	
}
