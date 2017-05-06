public class QuickSort {
	void quick(int element[], int start, int end){
		int pivot, i, j;
		int temp;
		
		if(start<end){
			i=start;
			j=end;
			pivot=element[start];
			
			while(i<j){
				while(element[j]>pivot) j--;
				while(i<j && element[i]<=pivot) i++;
				
				temp = element[i];
				element[i] = element[j];
				element[j] = temp;
			}
			
			element[start] = element[i];
			element[i] = pivot;
			
			System.out.print("element: ");
			for(int x: element)	System.out.print(x+" ");
			System.out.println("\n");
			
			quick(element, start, i-1);
			quick(element, i+1, end);
		}
	}
}
