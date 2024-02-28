#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100
    
    int isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    int applyOperator(char op, int operand1, int operand2) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;

        }
    }

    void evaluatePostfix(char postfix[]) {
    
 int i;
    int stack[MAX_SIZE];
    int top = -1;

    for(i=0; postfix[i] != '\0'; i++) {

        if(isdigit(postfix[i])) {
            stack[++top] = postfix[i] - '0';
        }
        else {
		     int a =stack[top--] ;
             int b =stack[top--];
             stack[++top] = applyOperator(postfix[i], a,b);
        }

    }

    printf("%d", stack[0]);
    }
    int main()
    {
        char str[MAX_SIZE];
        printf("Enter postfix string : ");
        scanf("%s", str);
        
        evaluatePostfix(str);
		}
