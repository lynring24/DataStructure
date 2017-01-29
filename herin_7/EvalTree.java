
class ETree{
	ETree left;
	String data;
	String  value;		//calc value from the subtrees
	ETree right;
	ETree(String string){left=right=null; data=string;}
	
}
public class EvalTree {
	
	ETree root,temp;
	EvalTree(){
		generate();
		eval(root);
		System.out.println("result:"+root.value);
	}
	void generate(){
		root = new ETree("or");
		root.left=new ETree("or");
		root.left.left=new ETree("and");
		root.left.left.left=new ETree("A");
		root.left.left.right=new ETree("not");
		root.left.left.right.right=new ETree("B");
		root.left.right=new ETree("and");
		
		root.left.right.left=new ETree("not");
		root.left.right.right=new ETree("D");
		root.left.right.left.right=new ETree("C");
		root.right=new ETree("not");
		root.right.right= new ETree("E");
	}
	void eval(ETree node){
		if(node!=null){
			eval(node.left);
			eval(node.right);
			switch(node.data){
			case "not": 
				node.value="~("+node.right.value+")"; 
				break;
			case "and": 
				node.value="("+node.right.value+")&&("+node.left.value+")"; 
				break;
			case "or": 
				node.value="("+node.right.value+")||("+node.left.value+")";
				break;
			default:
				node.value=node.data;
				break;
			}
		}
	}
	
}
