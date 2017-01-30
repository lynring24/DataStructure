package jan4аж;

class TreeFunctions {	

	public void postorder(Tree ptr) {
		if (ptr != null) {
			postorder(ptr.left);
			postorder(ptr.right);
			System.out.print((char)ptr.data+" ");
		}
	}
	
	void inorder(Tree ptr) {
		if (ptr != null) {
			inorder(ptr.left);
			System.out.print((char)ptr.data+" ");
			inorder(ptr.right);
		}
	}

	void preorder(Tree ptr) {
		if (ptr != null) {
			System.out.print((char)ptr.data+" ");
			preorder(ptr.left);
			preorder(ptr.right);
		}
	}
}
