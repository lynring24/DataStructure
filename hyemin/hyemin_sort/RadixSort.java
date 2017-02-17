import java.util.Arrays;

public class RadixSort {
	int getMax(int element[]){
		int max=element[0];
		
		for(int i=1; i<element.length; i++){
			if(element[i]>max) max = element[i];
		}
		return max;
	}
	
	void radix(int element[], int exp){
		int i;
		int len = element.length;
		int output[] = new int[len];
		int count[] = new int[10];
		Arrays.fill(count, 0);
		
		for(i=0;i<len;i++) count[(element[i]/exp)%10]++;
		
		for(i=1; i<10; i++) count[i] += count[i-1];
		
		for(i=len-1; i>=0; i--){
			output[count[ (element[i]/exp)%10 ] - 1] = element[i];
			System.out.println("output["+(count[ (element[i]/exp)%10 ]-1 )+"] = " +element[i]);
			count[ (element[i]/exp)%10 ]--;
		}
		
		for(i=0; i<len; i++) element[i] = output[i];
	}
	
	void radixSort(int element[]){
		int max = getMax(element);
		
		for(int exp=1; max/exp>0; exp*=10){
			radix(element, exp);
			
			System.out.print("element: ");
			for(int i:element) System.out.print(i+" ");
			System.out.println("\n");
		}
	}
}
