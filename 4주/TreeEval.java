package jan4аж;

public class TreeEval {

	public static void main(String[] args) {
		TreeEval e = new TreeEval();
		TreeFunctions tf = new TreeFunctions();
		tf.postorder(Tree.ptr);

		e.initEval();
	}
	
	public void initEval() {
		Tree or1, or2, not1;
		or1 = new Tree();
		or2 = new Tree();
		not1 = new Tree();

		or1.data = 'V';
		or1.left = or2;
		or1.right = not1;
		
		Tree and1, and2;
		and1 = new Tree();
		and2 = new Tree();

		or2.left = and1;
		or2.right = and2;
		or2.data = 'V';
		
		Tree A, not2;
		A = new Tree();
		not2 = new Tree();
		
		and1.left = A;
		and1.right = not2;
		and1.data = '^';
		
		A.left = null;
		A.right = null;
		A.data = 'A';
		
		Tree B = new Tree();
		not2.left = null;
		not2.right = B;
		not2.data = '~';
		
		B.left = null;
		B.right = null;
		B.data = 'B';
		
		Tree not3 = new Tree();
		Tree D = new Tree();
		and2.left = not3;
		and2.right = D;
		and2.data = '^';
		
		Tree C = new Tree();
		not3.left = null;
		not3.right = C;
		not3.data = '~';
		
		C.left = null;
		C.right = null;
		C.data = 'C';
		
		D.left = null;
		D.right = null;
		D.data = 'D';
		
		Tree E = new Tree();
		not1.left = null;
		not1.right = E;
		not1.data = '~';
		
		E.left = null;
		E.right = null;
		E.data = 'E';
		
		Tree.ptr = or1;
		
	}

	void eval (Tree node) {
		if (node!=null) {
			eval(node.left);
			eval(node.right);
			switch (node.data) {
			case '~' :
				node.data = (char) ~(node.right.data);
				break;
			case '^': 
				node.data = node.left.data & node.right.data;
				break;
			case 'V':
				node.data = node.left.data | node.right.data;
				break;
			case 1:
				
			}
		}
	}
	
}