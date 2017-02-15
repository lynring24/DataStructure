import java.util.Scanner;

public class Main {
	public static void main(String[] args) {		
		int list[] = {9, 5, 2, 7, 4, 6, 3};
		
		int key;
		int keyIndex;//Ű ���� �ε��� ��
		
		System.out.println("<Selection Sort>");
		System.out.println("Origin: ");
		
		for(int i:list){
			System.out.print(i+" ");
		}
		
		System.out.println();
		System.out.println();		
		
		SelectionSort ss = new SelectionSort();
		
		System.out.println("Sorting: ");
		ss.selectionSort(list, list.length);
		
		
		System.out.println();
		System.out.println("<Binary Search>");
		
		Scanner scan = new Scanner(System.in);
		
		System.out.print("ã���ð��� �ϴ� ���� ���� �Է��Ͻʽÿ�: ");
		key = scan.nextInt();
		
		BinarySearch bs = new BinarySearch();
		keyIndex = bs.binsearch(list, key, 0, list.length-1);
		
		if(keyIndex!=-1){
			System.out.println("�ش� ���� "+key+"�� "+(keyIndex+1)+"��° �ڸ��� ��ġ�մϴ�.");
		}
		else{
			System.out.println("�ش� ���� "+key+"��(��) �������� �ʽ��ϴ�.");
		}
		
		
		System.out.println();
		System.out.println("<Permutation>");
		Permutation permut = new Permutation();
		
		permut.perm(list, 0, list.length-1);
	}
}