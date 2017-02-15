public class MergeSort {
	void merge(int element[], int min, int mid, int max){
		int i, j, k;
		int temp[] = new int[element.length];
		
		for(i=min;i<=max;i++) temp[i]=element[i];
		
		i=min; k=min;
		j=mid+1;
		
		while(i<=mid && j<=max){
			if(temp[i]<temp[j]) element[k++] = temp[i++];
			else element[k++] = temp[j++];
		}
		
		while(i<=mid) element[k++] = temp[i++];
		
		System.out.print("element: ");
		for(int value:element) System.out.print(value+" ");
		System.out.println("\n");
	}
	
	void mergeSort(int element[], int min, int max){
		int mid;
		
		if(min<max){
			mid=(min+max)/2;
			
			mergeSort(element, min, mid);
			mergeSort(element, mid+1, max);
			merge(element, min, mid, max);
		}
	}
}
