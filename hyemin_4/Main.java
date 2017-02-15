import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		Postfix postfix = new Postfix();
		System.out.println("----------<Postfix>---------");
		System.out.println("식을 입력하세요: ");
		postfix.token = scan.nextLine();
		postfix.calculate();
		
		
		MultiStack multi = new MultiStack();
		int select = 0;
		int i, item;
		
		do{
			System.out.println("\n----------<MultiStack>----------");
			System.out.println("1. add");
			System.out.println("2. delete");
			System.out.println("0. exit");
			System.out.print("원하시는 작업의 번호를 입력해주십시오: ");
			
			select = scan.nextInt();
			
			switch(select){
			case 0:
				return ;
			case 1:
				System.out.println("사용하시고자 하는 스택의 번호를 입력해주십시오(0~9):");
				i = scan.nextInt();
				System.out.println("입력하시고자 하는 값을 입력해주십시오(십진수)");
				item = scan.nextInt();
				multi.add(i, item);
				break;
			case 2:
				System.out.println("스택 번호를 입력해주십시오(0~9):");
				i = scan.nextInt();
				multi.delete(i);
				break;
			default:
				System.out.println("잘못된 입력입니다.");
				break;
			}
		}while(select!=0);
	}
}
