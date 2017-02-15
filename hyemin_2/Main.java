import java.util.Scanner;

public class Main {
	public final static int STACK_SIZE = 100;
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Stack stack = new Stack();
		Scanner scan = new Scanner(System.in);
		
		int select=0;
		
		do{
			System.out.println("--------<Stack>--------");
			System.out.println("1. state");
			System.out.println("2. push");
			System.out.println("3. pop");
			System.out.println("0. exit");
			System.out.println("-----------------------");
			System.out.print("���Ͻô� ����� ���ڸ� �����Ͻʽÿ�: ");
			
			select = scan.nextInt();
			
			stack.selection(select);
		}while(select!=0);
		
		Polynomial polynomial = new Polynomial();
		System.out.println("--------<Polynomial>--------");
		
		polynomial.pInput();
		polynomial.pAdd();
		
		for(int i=polynomial.dStart; i<=polynomial.dEnd;i++){
			System.out.println("���: "+polynomial.poly[i].coef);
			System.out.println("����: "+polynomial.poly[i].expon);
		}
		
	}
}
