class Swap{
	public void swap(int array[], int index1, int index2){
	    final int temp = array[index1];
	    array[index1] = array[index2];
	    array[index2] = temp;
	}
}