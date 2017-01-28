import java.util.Scanner;

class Element {
	int value;
}

class Stack{
	public final static int STACK_SIZE = 100;
	
	Element stack[] = new Element[STACK_SIZE];
	Scanner scan = new Scanner(System.in);
	
	Stack(){//생성자를 호출하여 객체 배열 초기화	
		for(int i=0; i<stack.length; i++){
			stack[i] = new Element();
		}
	}
	
	int top=-1;//스택 인덱스 초기값
	
	boolean IsEmpty(Element stack[]){
		return (top<0);
	}
	
	boolean IsFull(Element stack[]){
		return (top>=STACK_SIZE-1);
	}
	
	Element item = new Element();
	
	void push(Element item){
		if(IsFull(stack)){
			System.out.println("stack is full");
			return;
		}			
		stack[++top].value=item.value;
		System.out.println(stack[top].value+"를 push하였습니다.");
	}
	
	void pop(){
		if(IsEmpty(stack)){
			System.out.println("stack is empty");
			return;
		}
		System.out.println(stack[top--].value+"를 pop하였습니다.");
	}
	
	void state(){
		if(top==-1) System.out.println("stack이 비어있습니다.");
		for(int i=0;i<=top;i++){
			System.out.println(stack[i].value);
		}
	}
	
	void selection(int select){
		switch(select){
		case 0:
			return;
		case 1:
			state();
			break;
		case 2:
			System.out.print("push할 값(정수)을 입력하십시오: ");
			item.value = scan.nextInt();
			push(item);
			break;
		case 3:
			pop();
			break;
		default:
			System.out.println("입력하신 번호에 대한 서비스가 존재하지 않습니다.");
		}
	}
}