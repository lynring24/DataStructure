class Permutation {
	void perm(int list[], int startIndex, int endIndex){
		int i, tmp;
		Swap swp = new Swap();
		
		/* startIndex가 endIndex와 같으면(즉, 마지막 인덱스까지 perm이 진행되면)
		 * list 숫자들 출력*/
		if(startIndex==endIndex){
			for(i=0; i<=endIndex; i++){
				System.out.print(list[i]+" ");
			}
			System.out.println();
		}
		
		//마지막 인덱스에 도달하지 않은 상태일 경우
		else{
			for(i=startIndex; i<=endIndex; i++){
				swp.swap(list, startIndex, i);//startIndex와 i번째 인덱스 swap
				perm(list, startIndex+1, endIndex);//startIndex 값 고정한 채로 perm 호출 
				swp.swap(list, startIndex, i);//list 값 원상복구
			}
		}
	}
}