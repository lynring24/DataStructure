public class Main {
	public static void main(String[] args) {
		int element1[] = {26, 5, 37, 1, 61, 11, 59, 15, 48, 19};
		int element2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
		int element3[] = {2, 3, 4, 1, 8, 0, 5, 9, 7, 6};
		int element4[] = {5, 4, 6, 2, 9, 1, 8, 7, 3, 0};
		
		System.out.println("\n---------<Quick Sort>--------\n");
		System.out.print("element: ");
		for(int x: element1)	System.out.print(x+" ");
		System.out.println();
		
		QuickSort q = new QuickSort();
		q.quick(element1, 0, element1.length-1);

		System.out.println("\n---------<Downward Merge Sort>--------\n");
		System.out.print("element: ");
		for(int x: element2)	System.out.print(x+" ");
		System.out.println("\n");
		
		MergeSort m = new MergeSort();
		m.mergeSort(element2, 0, element2.length-1);
		
		System.out.println("\n---------<Bubble Sort>--------\n");
		System.out.print("element: ");
		for(int x: element3)	System.out.print(x+" ");
		System.out.println("\n");
		
		BubbleSort b = new BubbleSort();
		b.bubble(element3);
		
		System.out.println("\n---------<Insertion Sort>--------\n");
		System.out.print("element: ");
		for(int x: element4)	System.out.print(x+" ");
		System.out.println("\n");
		
		InsertionSort i = new InsertionSort();
		i.insertion(element4);
	}
}
