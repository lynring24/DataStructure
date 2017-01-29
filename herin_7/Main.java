import java.util.Scanner;

class Tree {
	Tree left;
	char value;	
	Tree right;
	Tree(){left=null; right=null;}
	Tree(char n){left=null; value = n; right=null;}
}

public class Main {

	public static void main(String[] args) {
		/*>####Tue
		-	Binary Trees(Postorder, Inorder, Preorder, Level Order)
		-	Copy Tree
		-	Evaluation Tree*/
		System.out.println("1.Binary Trees");
		new Binary();
		System.out.println("\n\n2.LevelOrder");
		new LevelOrder();
		System.out.println("\n\n3.Copy Trees");
		new CopyTree();
		System.out.println("\n\n4.Eval Trees");
		new EvalTree();
	}
	
}
