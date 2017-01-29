import java.util.Scanner;

class TreeGernerator{

	Tree root,temp;
	TreeGernerator(){// A*B+C-D/E
		root = new Tree('-');
		root.left=new Tree('+');
		temp=root.left.left=new Tree('*');
		temp.left=new Tree('A');
		temp.right=new Tree('B');
		root.left.right=new Tree('C');
		root.right=new Tree('/');
		root.right.left=new Tree('D');
		root.right.right= new Tree('E');
		
	}

	Tree getTree(){
		return root;
	}
}

/* THIS IS FAILURE OF RANDOM TREE GENERATOR --------
class TreeGernerator{
	Tree root,tail;
	String str;
	TreeGernerator(){
		System.out.print("enter equation:");
		Scanner scan = new Scanner(System.in);
		str = scan.next();
		root=new Tree();
		vacant(root,0,str.length());
	}
	void vacant(Tree t,int s,int e){
		if(s<e){
			int mid=(e+s)/2;
			t.value= str.charAt(mid);
			t.left=new Tree();
			t.right=new Tree();
			vacant(t.left,s,mid);
			vacant(t.right,mid+1,e);
		}
	}
	Tree getTree(){
		return root;
	}

}*/