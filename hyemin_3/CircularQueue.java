class CircularQueue extends Queue{	
	int front = 0;
	int rear = 0;
	
	@Override
	void addQ(Value item){
		rear = (rear+1)%QUEUE_SIZE;
		
		if(rear==front){
			System.out.println("queue is full");
			reset();
			return ;
		}
		
		queueItem[rear].value = item.value;
		System.out.println(queueItem[rear].value+"을(를) 추가했습니다.");
		
		System.out.println("front = "+front);
		System.out.println("rear = "+rear);
	}
	
	@Override
	void deleteQ(){
		if(rear==front){
			System.out.println("Queue가 비어있습니다.");
			return ;
		}
		
		else{
			front = (front+1)%QUEUE_SIZE;
			System.out.println(queueItem[front].value+"을(를) 제거했습니다");
			
			System.out.println("front = "+front);
			System.out.println("rear = "+rear);
		}
	}
	
	void reset(){
		if(rear>0) rear--;
		else rear = QUEUE_SIZE-1;
	}
}
