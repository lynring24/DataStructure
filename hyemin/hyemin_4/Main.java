import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		Postfix postfix = new Postfix();
		System.out.println("----------<Postfix>---------");
		System.out.println("���� �Է��ϼ���: ");
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
			System.out.print("���Ͻô� �۾��� ��ȣ�� �Է����ֽʽÿ�: ");
			
			select = scan.nextInt();
			
			switch(select){
			case 0:
				return ;
			case 1:
				System.out.println("����Ͻð��� �ϴ� ������ ��ȣ�� �Է����ֽʽÿ�(0~9):");
				i = scan.nextInt();
				System.out.println("�Է��Ͻð��� �ϴ� ���� �Է����ֽʽÿ�(������)");
				item = scan.nextInt();
				multi.add(i, item);
				break;
			case 2:
				System.out.println("���� ��ȣ�� �Է����ֽʽÿ�(0~9):");
				i = scan.nextInt();
				multi.delete(i);
				break;
			default:
				System.out.println("�߸��� �Է��Դϴ�.");
				break;
			}
		}while(select!=0);
	}
}
