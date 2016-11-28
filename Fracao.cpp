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
		
		Fracao(int VN, int VD);
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
			cout << getN() << endl;
			cout << "--" << endl;
			cout << getD() << endl;
		}
		
		
int main(){
	
	Fracao f1(2, 5);
	f1.mostra();
	
	
return 0;
	
	
}
		
