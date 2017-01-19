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
			System.out.print("���Ͻô� �۾��� ��ȣ�� �����ϼ���: ");
			
			select = scan.nextInt();
			
			switch(select){
			case 0:
				break;	
			
			case 1:
				System.out.print("Queue�� ���� ���� �Է��ϼ���: ");
				queueItem.value = scan.nextInt();
				queue.addQ(queueItem);
				break;
			
			case 2:
				queue.deleteQ();
				break;

			default:
				System.out.println("�߸��� �Է��Դϴ�.");
				break;
			}
			
		}while(select!=0);

		
		do{
			System.out.println("\n-----------<Circular Queue>----------");
			System.out.println("1. add queue");
			System.out.println("2. delete queue");
			System.out.println("3. current state");
			System.out.println("0. exit");
			System.out.print("���Ͻô� �۾��� ��ȣ�� �����ϼ���: ");
			
			select = scan.nextInt();
			
			switch(select){
			case 0:
				break;			
			
			case 1:
				System.out.print("Queue�� ���� ���� �Է��ϼ���: ");
				queueItem.value = scan.nextInt();
				cQueue.addQ(queueItem);
				break;
			
			case 2:
				cQueue.deleteQ();
				break;

			case 3:
				for(int i=0; i<queue.QUEUE_SIZE; i++){
					System.out.println(i+"��° �ε����� �ִ� ���� "+cQueue.queueItem[i].value);
				}
				break;
				
			default:
				System.out.println("�߸��� �Է��Դϴ�.");
				break;
			}
			
		}while(select!=0);
		
		
		System.out.println("\n-------<Maze Problem>--------");
		MazeProblem mazePrb = new MazeProblem();
		mazePrb.path();
	}

}
