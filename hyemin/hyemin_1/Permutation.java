class Permutation {
	void perm(int list[], int startIndex, int endIndex){
		int i, tmp;
		Swap swp = new Swap();
		
		/* startIndex�� endIndex�� ������(��, ������ �ε������� perm�� ����Ǹ�)
		 * list ���ڵ� ���*/
		if(startIndex==endIndex){
			for(i=0; i<=endIndex; i++){
				System.out.print(list[i]+" ");
			}
			System.out.println();
		}
		
		//������ �ε����� �������� ���� ������ ���
		else{
			for(i=startIndex; i<=endIndex; i++){
				swp.swap(list, startIndex, i);//startIndex�� i��° �ε��� swap
				perm(list, startIndex+1, endIndex);//startIndex �� ������ ä�� perm ȣ�� 
				swp.swap(list, startIndex, i);//list �� ���󺹱�
			}
		}
	}
}