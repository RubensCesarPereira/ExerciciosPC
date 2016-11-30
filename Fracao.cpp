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
		Fracao operator*(Fracao b );
		Fracao& operator++();
		
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

		Fracao Fracao::operator*(Fracao b ){
			Fracao res;
			res.setD(getD() * b.getD());
			res.setN(getN() * b.getN());
		
			return res;				
		}	
		
	/*	Fracao Fracao::operator++(int x){ //pós-fixado
			return this
		} */
		
		Fracao& Fracao::operator++(){ //pré-fixado
			N += D;
		} 
		
/**************************************************************************/
		
		
		
		
int main(){
	

	
	
	Fracao A(1, 2);
	Fracao B(3, 4);
	Fracao C;
	Fracao D(1,4);
	
	cout << "A: ";
	A.mostra();
	cout << "B: ";
	B.mostra();
	cout << "C: ";
	C.mostra();
	
	cout << "D: ";
	D.mostra();
	
	cout << endl;
	

	
	C = A*B;
	//C = Multiplica(A, B);
	//C = A.Multiplica(B)
	
	cout << "C = A*B" << endl;
	C.mostra();
	
	cout << endl;
	
	++D;
	cout << "D incrementado" << endl;
	D.mostra();
	
return 0;

/* 

Fracao operator++(int fantasma) - pós-fixado, tem parâmetro fantasma que serve apenas para diferenciar os dois

Fracao& operator++() - pré-fixado, não tem nenhum parâmetro - Retorno por referência

não são const, pois alteram os objetos

tipo de retorno - próprio objeto da classe

++A = B + C --- é válido
A++ = B + C --- não é válido

*/






	
	
}
