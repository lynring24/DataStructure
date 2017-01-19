
public class MultiStack {
	final static int LENGTH = 100;
	final static int MAX_STACKS = 10;
	
	int memory[] = new int [LENGTH];
	int top[];
	int boundary[];
	
	MultiStack(){
	
		top = new int [MAX_STACKS];
		boundary = new int [MAX_STACKS+1];

		for(int i=0; i < MAX_STACKS; i++){
			top[i]=boundary[i]=(LENGTH/MAX_STACKS)*i -1;
		}
	
		boundary[MAX_STACKS] = LENGTH-1;

	}
	
	void add(int i, int item){
		if(top[i]==boundary[i+1]){
			System.out.println("stack is full "+ i);
			return ;
		}
		memory[++top[i]]=item;
	}
	
	int delete(int i){
		if(top[i] == boundary[i]){
			System.out.println("stack is empty "+i);
			return -1;
		}
		return memory[top[i]--];
	}
}

