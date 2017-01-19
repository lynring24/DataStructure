import java.util.Scanner;

public class Main {
	public static void main(String[] args) {		
		int list[] = {9, 5, 2, 7, 4, 6, 3};
		
		int key;
		int keyIndex;//키 값의 인덱스 값
		
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
		
		System.out.print("찾으시고자 하는 정수 값을 입력하십시오: ");
		key = scan.nextInt();
		
		BinarySearch bs = new BinarySearch();
		keyIndex = bs.binsearch(list, key, 0, list.length-1);
		
		if(keyIndex!=-1){
			System.out.println("해당 정수 "+key+"는 "+(keyIndex+1)+"번째 자리에 위치합니다.");
		}
		else{
			System.out.println("해당 정수 "+key+"은(는) 존재하지 않습니다.");
		}
		
		
		System.out.println();
		System.out.println("<Permutation>");
		Permutation permut = new Permutation();
		
		permut.perm(list, 0, list.length-1);
	}
}