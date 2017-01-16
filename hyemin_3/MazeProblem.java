class Offset{//이동 방향에 따른 행렬 값 증가/감소를 위한 클래스
	int vert;
	int horiz;
}

class Element{
	int row;
	int col;
	int dir;
}

class MazeProblem {
	final static int M = 11;
	final static int P = 15;
	final static int DIRECTION = 8;
	final static int MAX_STACK_SIZE = 100;	
	final static int EXIT_ROW = 11;
	final static int EXIT_COL = 15;
	
	int row, col, dir;
	int next_row, next_col;
	
	int top = 0;//스택 인덱스 시작부분
	
	int maze[][] = 
			{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				{1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
				{1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
				{1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
				{1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1},
				{1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
				{1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1},
				{1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				{1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
				{1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
				{1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};//미로 초기화
	
	int mark[][] = new int[M+2][P+2];
	
	Offset move[] = new Offset[DIRECTION];
	Element stack[] = new Element[MAX_STACK_SIZE];
	
	MazeProblem(){
		
		for(int i=0; i<MAX_STACK_SIZE;i++){
			stack[i] = new Element();
		}
		
		for(int i=0; i<DIRECTION;i++){
			move[i] = new Offset();
		}
		
		//8가지 방향에 따른 row, col 값의 증가/감소/유지를 초기화
		move[0].vert = -1;	move[0].horiz = 0;
		move[1].vert = -1;	move[1].horiz = 1;
		move[2].vert = 0;	move[2].horiz = 1;
		move[3].vert = 1;	move[3].horiz = 1;
		move[4].vert = 1;	move[4].horiz = 0;
		move[5].vert = 1;	move[5].horiz = -1;
		move[6].vert = 0;	move[6].horiz = -1;
		move[7].vert = -1;	move[7].horiz = -1;
	}
	
	
	void path(){
		Element position = new Element();
		boolean found = false;
		
		mark[1][1] = 1;
		stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
		
		while(top>-1 && !found){
			position = delete();
			row = position.row; col = position.col; dir = position.dir;
			
			while(dir<DIRECTION && !found){//모든 방향을 조사하거나 출구를 찾았으면 빠져나옴
				next_row = row + move[dir].vert;
				next_col = col + move[dir].horiz;
				
				System.out.println("row/col = "+row+", "+col);
				
				if((next_row == EXIT_ROW)&&(next_col == EXIT_COL)){//출구이면
					found = true;
					System.out.println("row/col = "+row+", "+col);
					System.out.println("success to escape!>.o/");
					return ;
				}
			
				else if(maze[next_row][next_col] == 0 && mark[next_row][next_col] == 0){//maze가 0이고 처음 접근하는 것일 경우
					mark[next_row][next_col] = 1;				
					position.row = row;	position.col = col;	position.dir = ++dir;
				
					add(position);
				
					row = next_row; col = next_col; dir = 0;
				}
			
				else ++dir;//현재 방향이 막혀있을 경우 방향 값 증가
			}
		}
		
		System.out.println("fail to escape ;(");
	}
	
	Element delete(){
		return stack[top--];
	}
	
	void add(Element position){//이동하기 전 스택에 위치 값 및 방향 저장
		stack[++top].row = position.row;
		stack[top].col = position.col;
		stack[top].dir = position.dir;
	}
}