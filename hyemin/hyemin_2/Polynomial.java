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
	int dStart, dEnd;//결과 값의 시작과 끝 인덱스 값
	
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
			System.out.print(n+"번째 다항식의 항의 개수를 입력하십시오: ");
			num[n] = scan.nextInt();
		
			for(int i=0; i<num[n] && avail<MAX; i++){//i가 입력받을 항의 수보다 작고, 배열 인덱스가 MAX보다 작을 때
				System.out.print(i+"번째 항의 계수와 차수를 순서대로 입력하십시오(띄어쓰기로 구분): ");
				
				if(i==0){
					index[n].startIndex = avail;//첫 번째 항의 인덱스 값 저장
				}
				
				if(i==num[n]-1){
					index[n].endIndex = avail;//마지막 항의 인덱스 값 저장
				}
				
				poly[avail].coef = scan.nextFloat();
				poly[avail++].expon = scan.nextInt();
			}			
			n++;
		}
	}
	
	void pAttach(float coefficient, int exponent) throws Exception{
		if(avail>=MAX){
			System.out.println("배열의 최대 크기를 초과하였습니다.");		
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