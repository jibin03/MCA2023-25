  #include<stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push() {
	
	if( top + 1 == MAX ) {
		printf("Stack overflow !!");
	}
	else {
		printf("enter the string :");
		top++;
		scanf("%s",stack[top]);
	}
}

int pop() {
	
	if(top == -1) {
		printf("Stack underflow");
	}
	else {
		
		return stack[top--];
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

int main() {
	
	char str[100];
	int i;
	
	scanf(" %s", str);
	
	for(i=0; str[i] != '\0'; i++) {
		push(str[i]);
	}
	
	
	while(i > 0) {
		printf("%c", pop());
		i--;
	}
	
}
