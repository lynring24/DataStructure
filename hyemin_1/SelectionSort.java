class SelectionSort{
	public void selectionSort(int list[], int n){
		
		int i, j, min;
		
		for(i=0;i<n-1;i++){
			min = i;
			
			for(j=i+1; j<n; j++){
				if(list[j] < list[min]) min=j;
			}
			
			//���� Ŭ���� ��ü ���� �� swap �޼ҵ� ȣ��
			Swap swp = new Swap();
			swp.swap(list, min, i);
			
			//������ ������ �迭 ��ü ���
			for(int count=0;count<n;count++){
				System.out.print(list[count]+" ");
			}
			
			System.out.println();
		}
	}
}