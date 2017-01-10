import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Queue queue = new Queue();
		CircularQueue cQueue = new CircularQueue();
		Value queueItem = new Value();
		
		Scanner scan = new Scanner(System.in);
		
		int select = 0;
		
		do {
			System.out.println("\n-----------<Queue>----------");
			System.out.println("1. add queue");
			System.out.println("2. delete queue");
			System.out.println("0. exit");
			System.out.print("원하시는 작업의 번호를 선택하세요: ");
			
			select = scan.nextInt();
			
			switch(select){
			case 0:
				break;	
			
			case 1:
				System.out.print("Queue에 넣을 값을 입력하세요: ");
				queueItem.value = scan.nextInt();
				queue.addQ(queueItem);
				break;
			
			case 2:
				queue.deleteQ();
				break;

			default:
				System.out.println("잘못된 입력입니다.");
				break;
			}
			
		}while(select!=0);

		
		do{
			System.out.println("\n-----------<Circular Queue>----------");
			System.out.println("1. add queue");
			System.out.println("2. delete queue");
			System.out.println("3. current state");
			System.out.println("0. exit");
			System.out.print("원하시는 작업의 번호를 선택하세요: ");
			
			select = scan.nextInt();
			
			switch(select){
			case 0:
				break;			
			
			case 1:
				System.out.print("Queue에 넣을 값을 입력하세요: ");
				queueItem.value = scan.nextInt();
				cQueue.addQ(queueItem);
				break;
			
			case 2:
				cQueue.deleteQ();
				break;

			case 3:
				for(int i=0; i<queue.QUEUE_SIZE; i++){
					System.out.println(i+"번째 인덱스에 있는 값은 "+cQueue.queueItem[i].value);
				}
				break;
				
			default:
				System.out.println("잘못된 입력입니다.");
				break;
			}
			
		}while(select!=0);
		
		System.out.println("\n-------<Maze Problem>--------");
		MazeProblem mazePrb = new MazeProblem();
		
		
		mazePrb.path();
	}

}
