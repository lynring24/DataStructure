import java.util.ArrayList;
import java.util.List;

public class LinkStack {
	public static final int max=10;
	List <Node> list = new ArrayList<Node>();
	void push(Node e){
		if(list.size()==max)//if full
		{
			System.out.println("\n[warning]::full memory");
		}
		else
			list.add(e);
	}
	int pop(){
		if(list.size()==0){
			System.out.println("\n[warning]::empty memory");
			return -1;}
		Node temp=list.get(list.size()-1);
		list.remove(list.size()-1);
		return temp.value;
	}
}
