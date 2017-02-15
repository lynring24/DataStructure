public class BubbleSort {
	void bubble(int[] element){
		for(int i=element.length-1; i>=0; i--){
			for(int j=0; j<i; j++){
				if(element[j]<element[j+1]){
					int temp = element[j];
					element[j] = element[j+1];
					element[j+1] = temp;
				}

				System.out.print("element: ");
				for(int x: element)	System.out.print(x+" ");
				System.out.println();
			}
		}
	}
}
