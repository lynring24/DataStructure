class Offset{//�̵� ���⿡ ���� ��� �� ����/���Ҹ� ���� Ŭ����
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
	
	int top = 0;//���� �ε��� ���ۺκ�
	
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
	};//�̷� �ʱ�ȭ
	
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
		
		//8���� ���⿡ ���� row, col ���� ����/����/������ �ʱ�ȭ
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
			
			while(dir<DIRECTION && !found){//��� ������ �����ϰų� �ⱸ�� ã������ ��������
				next_row = row + move[dir].vert;
				next_col = col + move[dir].horiz;
				
				System.out.println("row/col = "+row+", "+col);
				
				if((next_row == EXIT_ROW)&&(next_col == EXIT_COL)){//�ⱸ�̸�
					found = true;
					System.out.println("row/col = "+row+", "+col);
					System.out.println("success to escape!>.o/");
					return ;
				}
			
				else if(maze[next_row][next_col] == 0 && mark[next_row][next_col] == 0){//maze�� 0�̰� ó�� �����ϴ� ���� ���
					mark[next_row][next_col] = 1;				
					position.row = row;	position.col = col;	position.dir = ++dir;
				
					add(position);
				
					row = next_row; col = next_col; dir = 0;
				}
			
				else ++dir;//���� ������ �������� ��� ���� �� ����
			}
		}
		
		System.out.println("fail to escape ;(");
	}
	
	Element delete(){
		return stack[top--];
	}
	
	void add(Element position){//�̵��ϱ� �� ���ÿ� ��ġ �� �� ���� ����
		stack[++top].row = position.row;
		stack[top].col = position.col;
		stack[top].dir = position.dir;
	}
}