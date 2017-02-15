class BinarySearch {
	int mid;	
	int binsearch(int array[], int key, int low, int high){
		while(low<=high){
			mid = (low+high)/2;
			
			if(key<array[mid]) high = mid-1;
			else if(key==array[mid]) return mid;
			else low = mid+1;			
		}
		
		return -1;
	}
}
