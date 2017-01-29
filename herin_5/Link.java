
public class Link {
	Node strt;
	public static final int max=10;
	public static int cnt=0;
	Link(){strt=null;}
	boolean ISFULL(){return (cnt==max);}
	boolean ISEMPTY(){return (cnt==0);}
	void insert(Node node){
		Node temp = new Node(); 
		if(ISFULL()){
			System.out.println("\n[warning]::full memory");
		}
		else if(ISEMPTY()){
			strt=temp;cnt++;}
		else{
			if(node==null){//insert at 1st
				temp.next=strt;
				strt =temp;
			}
			else{
				temp.next=node.next;
				node.next=temp;
			}
			cnt++;
		}
		
	}
	void delete(Node pri,Node node){
		if(ISEMPTY()){
			System.out.println("\n[warning]::empty memory");
			}
		else{
			if(pri!=null)//get the first one
				pri.next=node.next;
			else
				strt=strt.next;
		}
		cnt--;
	}
}
