import java.util.Scanner;

class Stack {
	final static int max =20;
	int [] list = new int [max];
	int top=0;
	void add(int n){
		if(top!=max)
			list[top++]=n;
		else
			System.out.println("full");
	}
	
	int  pop(){
			if(top>-1)
				return list[--top];
			else
				return -1;
	}
}

public class PostFix {

	public static void main(String[] args){
		// TODO Auto-generated method stub
		System.out.print("수식을 입력하시오:");
		Stack stack = new Stack();
		Scanner scan = new Scanner(System.in);
		String str = scan.nextLine();
		for(int i=0;i<str.length();i++){
			char c=str.charAt(i);
			if(c<='9'&&'0'<=c)
				stack.add(c-'0');
			else{
				int n2=stack.pop();
				switch(c){
				case '+': 
					stack.add(stack.pop()+n2);
					break;
				case '-': 
					stack.add(stack.pop()-n2);
					break;
				case '*': 
					stack.add(stack.pop()*n2);
					break;
				case '/': 
					stack.add(stack.pop()/n2);
					break;
				default: break;
				}
			}
		}//end of for
		System.out.println("결과:"+stack.pop());
	}

}
