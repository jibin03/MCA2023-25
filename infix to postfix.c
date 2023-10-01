#include<stdio.h>
#include<string.h>
#define MAX 100

int precedence(char ch) {
	
	switch(ch) {
		
		case '+':
		case '-':
			return 1;
			
		case '*':
		case '/':
			return 2;
			
		case '(':
			return 0;
			
	}
}

void infixToPostfix(char infix[], char postfix[]) {
	
	int i, j;                //operand and operator(+,-,*,/) store chyan   stack=-1
	char opStack[MAX];
	int top = -1;            // assigning the top
	
	for(i=0, j=0 ;infix[i] != '\0'; i++) {      // i represent infix ,j represent postfix 
		
		char ch = infix[i];
		
		if(isalnum(ch)) {         
			postfix[j++] = ch;
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			
			while(top >= 0 && precedence(opStack[top]) >= precedence(ch)) {
				postfix[j++] = opStack[top--];
			}
			opStack[++top] = ch;
				
		}
		else if( ch == '(') {
			
			opStack[++top] = ch;
			
		}
		else if(ch == ')') {
			while(top >= 0 && opStack[top] != '(') {
				postfix[j++] = opStack[top--];
			}
			top--;
		}	
	}
	while(top >= 0) {
		postfix[j++] = opStack[top--];
	}
	
		postfix[j] = '\0';	
}

int main() {
	
	char infix[MAX], postfix[MAX];  // infix kodukunath postfix kittunath value store chyan
	
	printf("Enter a infix string : ");
	scanf("%s", infix);  //& doesn't use in string
	
	infixToPostfix(infix, postfix);
	
	printf("%s", postfix);
	
	return 0;
		
}



// 2*3+5  6   '6'
// 


// 

// 23*5+
