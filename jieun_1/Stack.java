package jan1주;
import java.util.*;

class Element {
	int key;
	int value;
	static int top=-1;
	static final int SIZE=100;
}

class StackFunctions {
	boolean isEmpty(Element stack[]) { return Element.top< 0 ? true : false; }
	boolean isFull(Element stack[]) { return Element.top>=Element.SIZE-1 ? true : false; }

	void push(Element item, Element stack[]) {
		if (isFull(stack)) {
			System.out.println("stack_full");
			return;
		}
		stack[++Element.top] = item;
	}

	Element spop(Element stack[]) {
		Element empty = new Element();
		empty.key = -1;
		if (isEmpty(stack)) {
			System.out.println("stack empty");
			return empty;
		}
		return stack[Element.top--];
	}
}

public class Stack {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Element stack[] = new Element[Element.SIZE];
		
		int n, i, key, value;

		Element items[] = new Element[Element.SIZE];
		for (i=0; i<Element.SIZE; i++) {
			items[i] = new Element();
			stack[i] = new Element();
		}
		
		StackFunctions f = new StackFunctions();
		
		System.out.print("넣을 아이템의 개수: ");
		n = sc.nextInt();
		System.out.print("아이템 키 입력: ");
		for (i=0; i<n; i++) {
			key = sc.nextInt();
			items[i].key = key;
		}
		System.out.print("아이템 값 입력: ");
		for (i=0; i<n; i++) {
			value = sc.nextInt();
			items[i].value = value;
		}

		for (i=0; i<n; i++) {
			f.push(items[i], stack);
		}

		System.out.print("스택 값 확인: ");
		for (i=0; i<n; i++) {
			System.out.print(f.spop(stack).value+" ");
		}
		System.out.print("\n");
	}

}
