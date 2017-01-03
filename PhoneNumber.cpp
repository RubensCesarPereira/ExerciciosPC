#include <iostream>
#include <iomanip>

using namespace std;

class PhoneNumber{
	friend ostream &operator<<(ostream&, const PhoneNumber&);
	friend istream &operator>>(istream&, PhoneNumber &);

	private:
		char ddd [4];
		char prefixo[4];
		char numero[5];
			
};	

ostream &operator<<(ostream &output, const PhoneNumber &num){
	output << "(" << num.ddd << ") " << num.prefixo << "-" << num.numero;
	return output;   	
}

istream &operator>>(istream &input, PhoneNumber &num){
	input.ignore();
	input >> setw(4) >> num.ddd;
	input.ignore(2);
	input >> setw(4) >> num.prefixo;
	input.ignore();
	input >> setw(5) >> num.numero;
	
	return input;
}

int main(){
	
	PhoneNumber phone;
	
	cout << "Entre com o numero de telefone (xxx) xxx-xxxx:\n";
	
	cin >> phone; //invoca o operador >> : operator>>(cin, phone)
	
	cout << "O numero do telefone é: ";
	
	cout << phone << endl; //invoca o operador << 
	
	return 0;
}
