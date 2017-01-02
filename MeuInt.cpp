#include <iostream>
using namespace std;

class MeuInt{
	
	public:
		MeuInt(int i=0);
		int operator+(int);
		int operator-(int);
		int operator*(int);
		int operator*(MeuInt);
		int operator/(int);
		
		
		int getInteiro();
		void setInteiro(int);
		
	private:
		int inteiro;
		friend ostream &operator>>(ostream&, const MeuInt&);
		friend istream &operator>>(istream&, MeuInt&);
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

int MeuInt::operator*(MeuInt x){
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

MeuInt calcDelta(MeuInt a, MeuInt b, MeuInt c){
	MeuInt delta = b*b - a * c * 4;
	return delta;
	
}

ostream &operator<<(ostream& out, const MeuInt& meuint){
	out << meuint.inteiro;
	
	return out;
}

istream &operator>>(istream& in, MeuInt& meuint){
	
	in >> meuint.inteiro;
	
	return in;
}
		


int main(int argc, char** argv) {
	
	MeuInt inteiro1(10);
	MeuInt A, B, C;
	
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
