
class Postfix {
	final static int STACK_MAX = 100;
	
	String token;
	char tokens[];
	int top = -1;
	int op1, op2;
	int value;
	
	int stack[] = new int[STACK_MAX];
	
	void calculate(){
		tokens = token.toCharArray();
		
		for(char c: tokens){
			switch(c){
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
				value= value*10+(c-'0');//띄어쓰기를 사용하지 않은 상태에서 값이 들어오면 하나의 값으로 읽음
				break;
			case ' '://띄어쓰기가 들어오고, 저장된 값이 있으면 해당 값을 푸쉬
				if(value!=0){
					push(value);
					value = 0;
				}
				break;
			case '+':
				op2 = pop();
				op1 = pop();
				push(op1+op2);
				break;
			case '-':
				op2 = pop();
				op1 = pop();
				push(op1-op2);
				break;
			case '*':
				op2 = pop();
				op1 = pop();
				push(op1*op2);
				break;
			case '/':
				op2 = pop();
				op1 = pop();
				push(op1/op2);
				break;
			case '%':
				op2 = pop();
				op1 = pop();
				push(op1%op2);
				break;
			default:
				break;
			}
		}
		
		if(top==0){
			System.out.println("result: "+pop());
		}
		else if(top > 0) {
			System.out.println("The user input has too many values.");
		}
	}
	
	void push(int token){
		stack[++top] = token;
	}
	
	int pop(){
		if(top >= 0){
			return stack[top--];
		}
		else {
			System.out.println("The user has not input sufficient values in the expression.");
			return -1;
		}
	}
}
