
public class LevelOrder {
	Tree root;
	Tree [] queue;
	int front=-1,rear=-1,max=20;
	LevelOrder(){
		TreeGernerator tree = new TreeGernerator();
		root=tree.getTree();
		System.out.print("level-order :"); order(root);
	}
	void order(Tree node){
		queue = new Tree[max];
		
		if(node==null)
			return;
		add(root);
		while(true){
			node=del();
			if(node!=null){
				System.out.print(node.value+" ");
				if(node.left!=null) add(node.left);
				if(node.right!=null) add(node.right);
			}
			else break;
		}
	}
	 void add(Tree e){
	    	if(max-1==rear){
	    		System.out.println("\n[warning]::full memory");
	    	}
	    	else{
	    		queue[++rear]=e;
	    	}
	    }
	   Tree del(){
	    	if(front==rear){
	    		System.out.println("[end]");
	    		return null;
	    	}
	    	else{
	    		return queue[++front];
	    		}
	  
	    }
}
