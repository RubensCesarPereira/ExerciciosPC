#include <iostream>
using namespace std;

class MeuInt{
	
	public:
		MeuInt(int i=0);
		int operator+(int);
		int operator-(int);
		int operator*(int);
		int operator/(int);
		int getInteiro();
		void setInteiro(int);
		
	private:
		int inteiro;
		
	
};

MeuInt::MeuInt(int i){
	inteiro = 1;
}



int MeuInt::operator+(int x){
	inteiro = x + inteiro;
	return inteiro;
}
int MeuInt::operator-(int x){
		inteiro = x - inteiro;
	return inteiro;
}
int MeuInt::operator*(int x){
	inteiro = x * inteiro;
	return inteiro;
}
int MeuInt::operator/(int x){
	inteiro = x / inteiro;
	return inteiro;
}

int MeuInt::getInteiro(){
	return inteiro;
}

void MeuInt::setInteiro(int x){
	inteiro = x;
}

calcDelta(MeuInt a, MeuInt b, MeuInt c){
	delta = b*b - 4 * a * c
	return delta;
	
}



int main(int argc, char** argv) {
	
	MeuInt inteiro1(10);
	
	int c = inteiro1 + 1;
	
	cout << "inteiro1 + 1: ";
	cout << c << endl;
	
	cout << "Entre com as variáveis: " << endl;
	cout << "A: ";
	cin >> A;
	
	cout << "B: ";
	cin >> B;
	
	cout << "C: ";
	cin >> C;
	
	
	
	
	
	
	
	
	return 0;
}
