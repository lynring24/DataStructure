
public class CopyTree {
	Tree root1,root2;
	CopyTree(){
		TreeGernerator tree = new TreeGernerator();
		root1=tree.getTree();
		System.out.print("root1:");
		read(root1);
		System.out.print("\nroot2:");
		root2=copy(root1);
		read(root2);
	}
	 Tree copy(Tree t){
		 Tree temp;
		 if(t!=null){
			 temp=new Tree();
			 temp.left=copy(t.left);
			 temp.right=copy(t.right);
			 temp.value=t.value;
			 return temp;
		 }
		 else
			 return null;
	 }
	 void read(Tree node){
		 if(node!=null){
			 	read(node.left);
				System.out.print(node.value+" ");
				read(node.right);
			}
	 }
}
