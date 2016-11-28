/* 
Fraçao
-----------------
- N: int
- D: int
-----------------
+setN(VN: int):void
+setD(VD: int):void
+getN(): int {const}
+get(): int {const}
+mostra():void {const}


*/


#include <iostream>

using namespace std;

class Fracao{

	public:
		
		Fracao(int VN = 0, int VD = 1);
		void setN(int VN);
		void setD(int VD);
		int getN() const;
		int getD() const;
		void mostra() const;
		
	private:
		int N;
		int D;


};

		Fracao::Fracao(int VN, int VD){
			setN(VN);
			setD(VD);
			
		}
		void Fracao::setN(int VN){
			N = VN;
		}
		
		void Fracao:: setD(int VD){
			if (VD != 0)
				D = VD;
			else
				D = 1;
		}
		
		int Fracao::getN() const{
			return N;
		}
		
		int Fracao::getD() const{
			return D;
		}
		
		void Fracao::mostra() const{
			cout << getN() << "/"<< getD() << endl;
		}
		
/**************************************************************************/
		Fracao Multiplica(Fracao a, Fracao b ){
		Fracao res;
		res.setD(a.getD() * b.getD());
		res.setN(a.getN() * b.getN());
		
		return res;		
			
			
	}	
		
		
		
int main(){
	

	
	
	Fracao A(1, 2);
	Fracao B(3, 4);
	Fracao C;
	
	cout << "A: ";
	A.mostra();
	cout << "B: ";
	B.mostra();
	cout << "C: ";
	C.mostra();
	
	//	C = A*B;
	C = Multiplica(A, B);
	
	C.mostra();
	
	
return 0;
	
	
}
		
