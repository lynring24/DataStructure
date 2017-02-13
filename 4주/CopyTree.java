package jan4аж;

class Tree {
	public	Tree left;
	public Tree right;
	public int data;
	public static Tree ptr;
}

public class CopyTree {
	static Tree ptr = new Tree();
	
	public static void main(String[] args) {
		CopyTree c = new CopyTree();
		TreeFunctions tf = new TreeFunctions();

		c.initCopy();
		System.out.println("this is orignial tree");
		tf.postorder(Tree.ptr);
		System.out.println("");
		
		Tree copied = new Tree();
		copied = c.copyTree(Tree.ptr);
		System.out.println("this is copied tree");		
		tf.postorder(copied);
	}
	
	public void initCopy() {
		Tree minus = new Tree();
		minus.data = '-'; //head

		Tree plus, mul, C, A, B;
		plus = new Tree();
		mul = new Tree();
		C = new Tree();
		A = new Tree();
		B = new Tree(); //left

		Tree div, D, E;
		div = new Tree();
		D = new Tree();
		E = new Tree(); //right

		minus.left = plus;
		minus.right = div;

		plus.data = '+';
		plus.left = mul;
		plus.right = C;

		mul.data = '*';
		mul.left = A;
		mul.right = B;

		A.data = 'A';
		A.left = null;
		A.right = null;

		B.data = 'B';
		B.right = null;
		B.left = null;

		C.data = 'C';
		C.left = null;
		C.right = null; //left

		div.data = '/';
		div.left = D;

		D.data = 'C';
		D.left = null;
		D.right = null;

		div.right = E;
		E.data = 'E';
		E.right = null;
		E.left = null; //right
		
		Tree.ptr = minus;
	}

	Tree copyTree(Tree tree) {
		Tree temp = new Tree();
		if (tree!=null) {
			temp.left = copyTree(tree.left);
			temp.right = copyTree(tree.right);
			temp.data = tree.data;
			return temp;
		}
		return null;
	}
	
}
