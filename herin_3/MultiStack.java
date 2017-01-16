import java.util.Scanner;

class Multi{
	final static int n=5;//number of section 
	final static int size=30; // max number of size
	int [] arr = new int[size];
	int	[] top= new int[n];
	int [] bound=new int [n+1];

	Multi(){
		top[0]=bound[0]=0;
		 for(int i=1;i<n;i++){
			 top[i]=top[i-1]+size/n;
			 bound[i]=bound[i-1]+size/n;
		 	} 
		 bound[n]=bound[n-1]+size/n;
		 }
	
	void add(int s, int item){
		if(top[s]==bound[s+1]){//isFull
			System.out.println(" stack "+s+" is full");
		}
		else
			arr[top[s]++]=item;
	}
	int pop(int s){
		if(top[s]==bound[s]){//empty
			System.out.println(" stack "+s+" is empty");
			return -1;
		}
		else
			return arr[--top[s]];
	}
}
public class MultiStack {

	public static void main(String[] args) {
		Multi multi = new Multi();
		Scanner scan = new Scanner(System.in);
		int sec= multi.size/multi.n;		//section size;
		
		for(int i=0;i<multi.n;i++){
			for(int j=0;j<sec+1;j++){
				multi.add(i, j+10*i);
			}
		}
		
		System.out.println("[result]");
		for(int i=0;i<multi.size;i++){
			System.out.print(multi.arr[i]+" ");
			if(i%(sec)==multi.n)
				System.out.println("");
		}
		System.out.println("[pop]");
		for(int i=0;i<multi.n;i++){
			for(int j=0;j<sec+1;j++){
				int temp =multi.pop(i);
				if(temp!=-1){System.out.print(temp+" ");}
			}
		}
		System.out.print("");
	}
}
