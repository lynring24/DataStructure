
public class Binary {
	Tree root;
	Binary(){
		TreeGernerator tree = new TreeGernerator();
		root=tree.getTree();
		System.out.print("\npre-order :"); Preorder(root);
		System.out.print("\nin-order :"); Inorder(root);
		System.out.print("\npost-order :"); Postorder(root);
	}
	
	void Inorder(Tree t){
		if(t!=null){
			Inorder(t.left);
			System.out.print(t.value+" ");
			Inorder(t.right);
		}
	}
	void Preorder (Tree t){
		if(t!=null){
			System.out.print(t.value+" ");
			Preorder(t.left);
			Preorder(t.right);
		}
	}
	void Postorder (Tree t){
		if(t!=null){
			Postorder(t.left);
			Postorder(t.right);
			System.out.print(t.value+" ");
		}
	}
	
	
}
