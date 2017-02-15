public class InsertionSort {
	void insertion(int[] element){
		int i, j;
		
		for(i=1;i<element.length-1;i++){
			int temp = element[i];
			for(j=i-1;j>=0 && element[j]>temp;j--){
				element[j+1] = element[j];
				
				System.out.print("element: ");
				for(int x:element){
					System.out.print(x+" ");
				}
				System.out.println();
			}				
			element[j+1]=temp;
			
			System.out.print("element: ");
			for(int x:element){
				System.out.print(x+" ");
			}
			System.out.println();
		}
	}
}
