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
		Fracao operator*(Fracao b);
		Fracao operator*(int i);
		Fracao operator/(int i);
		Fracao operator/(Fracao f);
		Fracao& operator++(); //pré-fixado
		Fracao operator++(int x); //pós-fixado
		float operator+(int x);
		float operator+(Fracao f);
		float operator-(int x);
		float operator-(Fracao f);

		friend ostream & operator<<(ostream &, const Fracao&);
		bool operator>(const Fracao& o2) const;
		bool operator<(const Fracao& o2) const;
		
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
		
		Fracao Fracao::operator*(int i){
			Fracao aux;
			aux.setN(N * i);
			aux.setD(D);
			return aux; 
		}
		Fracao Fracao::operator/(int i){
			Fracao aux;
			aux.setN(N / i);
			aux.setD(D);
			return aux;			
		}
		
		Fracao Fracao::operator/(Fracao f){
	        Fracao res;
			res.setD(getD() * f.getN());
			res.setN(getN() * f.getD());
		
			return res;	
		}
		
		Fracao Fracao::operator++(int x){ //pós-fixado			
			Fracao temp = *this; //temp == cópia antes de incrementar
			N = N + D;
			return temp;
			
			 
		} 
		
		Fracao& Fracao::operator++(){ //pré-fixado
			N += D;
			return *this;
		} 
		
		bool Fracao::operator>(const Fracao& o2) const{
			return float(N/D > (o2.N)/float (o2.D));
		
		}
		
		bool Fracao::operator<(const Fracao& o2) const{
			return float(N/D < (o2.N)/float (o2.D));
		
		}
		
		float Fracao::operator+(int x){
			return (float) N/D + x;
			
		}
		float Fracao::operator+(Fracao f){
			return (float)N/D + (float)f.N /f.D;
		}
		
		float Fracao::operator-(int x){
			return (float) N/D - x;
			
		}
		float Fracao::operator-(Fracao f){
			return (float)N/D - (float)f.N /f.D;
		}
		

		
		
/**************************************************************************/
		
ostream& operator<<(ostream &saida, const Fracao& x)
{
	saida << x.N << "/" << x.D;
	return saida; 
}		
		
		
		
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
	
	++C;
	cout << "++C" << endl;
	C.mostra();
	
	C++;
	cout << "C++" << endl;
	C.mostra();
	
	
	cout << endl;
	
	++D;
	cout << "D incrementado" << endl;
	D.mostra();
	
	cout << "C: ";
	C.mostra();
	
	A = C++;
	cout << "A = C++: ";
	A.mostra();
	
	cout << "C++: ";
	C.mostra();

	cout << endl;
	cout << "Imprimindo C direto no cout, com a funcao friend: " << endl;
	
	cout << C << endl << endl;
	
	if (A > B)
		cout <<"A eh maior" << endl;
	else
		cout << "A nao eh maior" << endl;
		
	if (B < A)
		cout <<"B eh menor" << endl;
	else
		cout << "B nao eh menor" << endl;
	
	Fracao X(1,4);
	Fracao Y(1,2);
	
	Fracao K(1, 2);
	
	cout << X + Y << endl;
	
	cout<< K + 2 << endl;	
	
	Fracao J(3, 2);
	Fracao L(1, 2);
	
	cout << J - L << endl;
	
	cout << J - 1 << endl;
	cout << L - 1 << endl;
	
	Fracao U(8,2);
	Fracao V(4,2);
	
	cout << U * 3 << endl;
	cout << U / V << endl;
	cout << U / 2 << endl;
	
	
return 0;

/* 
Fracao operator++(int fantasma) - pós-fixado, tem parâmetro fantasma que serve apenas para diferenciar os dois - retorno por valor
Fracao& operator++() - pré-fixado, não tem nenhum parâmetro - Retorno por referência
não são const, pois alteram os objetos
tipo de retorno - próprio objeto da classe
++A = B + C --- é válido
A++ = B + C --- não é válido
*/

}
