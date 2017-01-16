
public class CircularQueue {
	final int max=10;
	int [] queue = new int [max];
	int rear=-1,front=-1;
	
	boolean ISEMPTY(){	
		if(front==rear)
			return true;
		else
			return false;
	}
	void add(int n){
			rear=(rear+1)%max; 
			if(front == rear){ //equals when ==, then must be full
				System.out.println(n+":full queue");
				if(rear>0) rear --;
				else rear=n-1;
			}
			queue[rear]=n;
	}
	int del(){
		if(front==rear){
			System.out.println("queue is empty");
			return -1;
			}
		front=(front+1)%max;
		return queue[front++];
		}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i;
		CircularQueue cq = new CircularQueue();
		
		for(i=0;i<cq.max;i++)
			cq.add(i);

		for(i=0;i<4;i++)
			cq.del();
		
		for(i=0;i<4;i++)
			cq.add(10*i);
		
		System.out.println("ÀüÃ¼:");
		for(i=0;i<cq.max;i++)
			System.out.print(cq.queue[i]+" ");
	}
}
