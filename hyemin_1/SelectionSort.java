class SelectionSort{
	public void selectionSort(int list[], int n){
		
		int i, j, min;
		
		for(i=0;i<n-1;i++){
			min = i;
			
			for(j=i+1; j<n; j++){
				if(list[j] < list[min]) min=j;
			}
			
			//스왑 클래스 객체 생성 및 swap 메소드 호출
			Swap swp = new Swap();
			swp.swap(list, min, i);
			
			//정렬할 때마다 배열 전체 출력
			for(int count=0;count<n;count++){
				System.out.print(list[count]+" ");
			}
			
			System.out.println();
		}
	}
}