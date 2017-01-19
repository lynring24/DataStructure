import java.util.ArrayList;
import java.util.Scanner;

class PValue{
	float coef;
	int expon;
}

class Index{
	int startIndex;
	int endIndex;
}

class Polynomial{
	final static int MAX = 50;
	
	Scanner scan = new Scanner(System.in);
	PValue poly[] = new PValue[MAX];
	
	int avail=0;
	int dStart, dEnd;//��� ���� ���۰� �� �ε��� ��
	
	Index index[] = new Index[2];
	int num[] = new int[2];
	
	
	Polynomial(){
		for(int i=0;i<2;i++){
			index[i] = new Index();
		}
		
		for(int i=0;i<MAX;i++){
			poly[i] = new PValue();
		}
	}
	
	void pInput(){
		
		int n=0;
		
		while(n<2){
			System.out.print(n+"��° ���׽��� ���� ������ �Է��Ͻʽÿ�: ");
			num[n] = scan.nextInt();
		
			for(int i=0; i<num[n] && avail<MAX; i++){//i�� �Է¹��� ���� ������ �۰�, �迭 �ε����� MAX���� ���� ��
				System.out.print(i+"��° ���� ����� ������ ������� �Է��Ͻʽÿ�(����� ����): ");
				
				if(i==0){
					index[n].startIndex = avail;//ù ��° ���� �ε��� �� ����
				}
				
				if(i==num[n]-1){
					index[n].endIndex = avail;//������ ���� �ε��� �� ����
				}
				
				poly[avail].coef = scan.nextFloat();
				poly[avail++].expon = scan.nextInt();
			}			
			n++;
		}
	}
	
	void pAttach(float coefficient, int exponent) throws Exception{
		if(avail>=MAX){
			System.out.println("�迭�� �ִ� ũ�⸦ �ʰ��Ͽ����ϴ�.");		
		}
		poly[avail].coef = coefficient;
		poly[avail++].expon = exponent;
	}
	
	void pAdd() throws Exception{
		float coefficient;
		
		dStart = avail;
		
		int a1=index[0].startIndex;
		int a2=index[0].endIndex;
		
		int b1=index[1].startIndex;
		int b2=index[1].endIndex;
		
		while(a1<= a2 && b1<=b2){
			if(poly[a1].expon < poly[b1].expon){
				pAttach(poly[b1].coef, poly[b1].expon);
				b1++;
			}
			else if(poly[a1].expon > poly[b1].expon){
				pAttach(poly[a1].coef, poly[a1].expon);
				a1++;
			}
			else if(poly[a1].expon == poly[b1].expon){
				coefficient = poly[a1].coef + poly[b1].coef;
				
				if(coefficient!=0.0f){
					pAttach(coefficient, poly[a1].expon);
					coefficient=0.0f;
				}
				
				a1++;
				b1++;
			}
			
		}
		
		for(;a1<=a2;a1++){
			pAttach(poly[a1].coef, poly[a1].expon);
		}
		
		for(;b1<=b2;b1++){
			pAttach(poly[b1].coef, poly[b1].expon);
		}
		
		dEnd = avail-1;
	}

}