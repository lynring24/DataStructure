class Value{
	int value;
}

class Queue {
	final static int QUEUE_SIZE=5;
	Value queueItem[] = new Value[QUEUE_SIZE];
	
	int rear = -1;
	int front = -1;
	
	Queue(){
		for(int i=0; i<QUEUE_SIZE; i++){
			queueItem[i] = new Value();
		}
	}
	
	boolean isEmptyQ(){
		return (front == rear);
	}
	
	boolean isFullQ(){
		return (rear == (QUEUE_SIZE-1));
	}
	
	void addQ(Value item){
		if(isFullQ()){
			System.out.println("Queue is full.");
			return ;
		}
		
		queueItem[++rear].value = item.value;
		
		System.out.println(queueItem[rear].value+"을(를) 추가했습니다.");

		System.out.println("front = "+front);//현재 front, rear 값 확인을 위해 프린트
		System.out.println("rear = "+rear);
	}
	
	void deleteQ(){
		if(isEmptyQ()){
			System.out.println("Queue is empty");
			return ;
		}
		
		System.out.println(queueItem[++front].value+"을(를) 제거했습니다.");
		

		System.out.println("front = "+front);
		System.out.println("rear = "+rear);
	}
}
