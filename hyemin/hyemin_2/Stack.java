import java.util.Scanner;

class Element {
	int value;
}

class Stack{
	public final static int STACK_SIZE = 100;
	
	Element stack[] = new Element[STACK_SIZE];
	Scanner scan = new Scanner(System.in);
	
	Stack(){//�����ڸ� ȣ���Ͽ� ��ü �迭 �ʱ�ȭ	
		for(int i=0; i<stack.length; i++){
			stack[i] = new Element();
		}
	}
	
	int top=-1;//���� �ε��� �ʱⰪ
	
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
		System.out.println(stack[top].value+"�� push�Ͽ����ϴ�.");
	}
	
	void pop(){
		if(IsEmpty(stack)){
			System.out.println("stack is empty");
			return;
		}
		System.out.println(stack[top--].value+"�� pop�Ͽ����ϴ�.");
	}
	
	void state(){
		if(top==-1) System.out.println("stack�� ����ֽ��ϴ�.");
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
			System.out.print("push�� ��(����)�� �Է��Ͻʽÿ�: ");
			item.value = scan.nextInt();
			push(item);
			break;
		case 3:
			pop();
			break;
		default:
			System.out.println("�Է��Ͻ� ��ȣ�� ���� ���񽺰� �������� �ʽ��ϴ�.");
		}
	}
}