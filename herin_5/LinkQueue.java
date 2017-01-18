
public class LinkQueue {
	public static final int max=10;
	Node [] queue = new Node[max];
    public int front=-1,rear=-1;
    boolean ISFULL(){return (max-1==rear);}
    boolean ISEMPTY(){return (front==max-1);}
    
    void add(Node e){
    	if(ISFULL()){
    		System.out.println("\n[warning]::full memory");
    	}
    	else{
    		queue[++rear]=e;
    	}
    }
    int del(){
    	if(ISEMPTY()){
    		System.out.println("\n[warning]::empty memory");
    		return -1;
    	}
    	else{
    		return queue[++front].value;
    		}
  
    }
	
}
