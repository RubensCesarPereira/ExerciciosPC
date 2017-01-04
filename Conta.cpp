/*
• Criar classe Conta, para representar contas
bancárias, que deve ter:
– métodos debitar e creditar (com validação)
– atributo Saldo (com métodos get e set).
• Usando herança, crie os tipos mais específicos
de conta:
– Poupança
• Atributo: Juros
• Método que retorna juros auferidos
– ContaCorrente
• Atributo: Taxa cobrada por por transações
– Metodos debitar e creditar devem diminuir saldo 

*/

#include <iostream>

using namespace std;

class Conta{
	
	public:
		Conta(float = 0);
		bool debitar(float d);
		bool creditar(float c);
		float getSaldo() const;
		void setSaldo(float s);
    private:
    	float saldo;
};

Conta::Conta(float saldoInicial){
	saldo = saldoInicial;
}

bool Conta::debitar(float d){
	if ((d > 0)&& (saldo < d))
		return false;
	else{ 
		saldo -= d; 
		return true;
	}
}

bool Conta::creditar(float c){
	if(c < 0)
		return false;
	
	else{
		saldo += c;
		return true;
    }
}

float Conta::getSaldo() const{
	return saldo;
}
		
void Conta::setSaldo(float s){
	saldo = s;
}

int main(int argc, char** argv)
{
	
	Conta Leila(1000);
	
	cout << "Saldo inicial: " << Leila.getSaldo() << endl;
	
	cout << "Credito de R$ 120,45: " << endl;
	Leila.creditar(120.45);
	
	cout << "Saldo apos o credito: " << Leila.getSaldo() << endl;
	
	cout <<"Debito de R$ 50,21: " << endl;
	Leila.debitar(50.21);
	
	cout << "Saldo apos o debito: " << Leila.getSaldo()<< endl;
	
	return 0;
}

