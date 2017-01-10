import java.util.ArrayList;
import java.util.List;

class Offset{
	int vert;
	int horiz;
	Offset(int i, int j){
		vert =i; horiz= j;
	}
}
class Element{
	int row;
	int col;
	int dir; // the next direction to find
	Element(int r, int c, int d){
		row= r; col = c; dir= d;
	}
}

class MazeOpti{
	static int x =5, y=5; 					//x= row of the maze , y= col of the maze
	final static int max =20; 				//max range of the 
	int  maze[][] = new int [x+2][y+2];  	// maze plane
	Offset move[] = new Offset[8]; 		    // 8 directions W/E/S/N/etc
	List<Element> stack  = new ArrayList<Element>();	//stack with List
	int mark[][] = new int [x+2][y+2];		
	boolean found=false;				
	int row=0, col=0, dir=0;				//will be used with pathing 
	int next_row=0, next_col =0;
	
	MazeOpti(){
		//maze plate init
		maze[0]=new int[]{1,1,1,1,1,1,1};	
		maze[1]=new int[]{1,0,1,0,1,0,1};
		maze[2]=new int[]{1,0,0,0,0,1,1};	
		maze[3]=new int[]{1,0,1,1,1,0,1};
		maze[4]=new int[]{1,0,0,1,0,1,1};	
		maze[5]=new int[]{1,1,0,0,0,0,1};
		maze[6]=new int[]{1,1,1,1,1,1,1};	
		//NSEW direction init
		move[0]=new Offset(-1,0);	move[1]=new Offset(-1,1);
		move[2]=new Offset(0,1);	move[3]=new Offset(1,1);
		move[4]=new Offset(1,0);	move[5]=new Offset(1,-1);
		move[6]=new Offset(0,-1);	move[7]=new Offset(-1,-1);
		//stack init
		stack.add(new Element(1,1,1));
	}
	
	void path(){
			mark[1][1]= 1; Element pos; 
			while(stack.size()!=0 &&!found){
				pos = pop(); // get the current pos
				row=pos.row; col= pos.col; dir = pos.dir;
				while(dir<8&&!found){
				next_row = row + move[dir].vert;
				next_col = col + move[dir].horiz; 
				System.out.println("("+next_row+","+next_col+")");
			
				if(next_row==x&&next_col==y)				// arrived
					found=true;
				else if(maze[next_row][next_col]==0&&mark[next_row][next_col]==0)
				{	//if there is a way && not been through yet
					mark[next_row][next_col]=1;
					pos.row=row; pos.col=col; pos.dir=++dir;
					push(pos);						 		//push current position;
					row=next_row; col=next_col; dir=0;
				}
				else 
					++dir;
				}
		}
		if(!found) System.out.print("path found fail");
		else 
			System.out.println("path found");
	}

	void push(Element e){
		if(stack.size()!=max)
			stack.add(e);
		else 
			System.out.println("full stack\n");
	}
	Element pop(){
		if(stack.size()!=0)
			return stack.get(stack.size()-1);
		else
			return null;
	}
}
public class MazeProblem{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MazeOpti().path();
	}

}
