import java.util.Random;
class Node{
	Random ran= new Random();
	int value;
	Node next;
	Node(){
		value=ran.nextInt(10);
		System.out.print(value + " ");
		next=null;
	}
}
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("1.Link");
		Link list = new Link();
		for(int i=0;i<list.max+1;i++){
			list.insert(null);
		}
		System.out.print("\n>memory:");
		for(Node temp=list.strt;temp!=null;temp=temp.next){
			System.out.print(temp.value+" ");
		}
		for(int i=0;i<list.max+1;i++){
			list.delete(null, null);
		}
		System.out.println("\n\n2.LinkStack");
		LinkStack stack = new LinkStack();
		for(int i=0;i<stack.max+1;i++){
			stack.push(new Node());
		}
		for(int i=0;i<stack.max+1;i++){
			int temp=stack.pop();
			if(temp!=-1)
				System.out.print(temp+" ");
		}
		System.out.println("\n\n3.LinkQueue");
		LinkQueue queue = new LinkQueue();
		for(int i=0;i<queue.max+1;i++){
			queue.add(new Node());
		}
		for(int i=0;i<queue.max+1;i++){
			int temp=queue.del();
			if(temp!=-1)
				System.out.print(temp+" ");
		}
		
	}

}
