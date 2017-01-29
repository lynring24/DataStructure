#include <stdio.h>

#define MAX_STACK 100
#define MAX_EXPR 100

typedef enum {
	lparen, rparen, plus, minus, times, divide, mode, eos, operand
} Precedence;

int stack[MAX_STACK];
char expr[MAX_EXPR];

int n;
int top=-1;
int op1, op2;

Precedence get_token(char *symbol, int *n) {
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '*': return times;
	case '/': return divide;
	case '%': return mode;
	case '\0': return eos;
	default: return operand;
	}
}

void push(int *top, int item) {
	if (*top>=MAX_STACK-1) {
		printf("stack_full \n");
		return;
	}
	stack[++*top] = item;
}

int pop(int *top) {
	if (*top<=0) {
		printf("stack empty\n");
		return -1;
	}
	return stack[*top--];
}

int eval() {
	Precedence token;
	char symbol;
	n = 0;
	token = get_token(&symbol, &n);
	while (token != eos) {
		if (token != eos)
			push(&top, symbol-'0');
		else {
			op2 = pop(&top);
			op1 = pop(&top);
			switch(token) {
			case plus: push(&top, op1+op2);
				break;
			case minus: push(&top, op1-op2);
				break;
			case times: push(&top, op1*op2);
				break;
			case divide: push(&top, op1/op2);
				break;
			case mode: push(&top, op1%op2);
			}
		}
		token = get_token(&symbol, &n);
	}
	return pop(&top);
}

int main () {
	int n, c;
	printf("╫д ют╥б: ");
	while ((c=scanf("%d", &c))!= 0)
		push(&top, c);

	printf("%d", eval());
	printf("\n");
	return 0;
}