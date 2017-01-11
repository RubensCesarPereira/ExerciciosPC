/*

POLIMORFISMO:
	AD HOC
		SOBRECARGA
		COER��O
		
		
	UNIVERSAL
		SUB TIPO -- ESTE VAI SER O ESTUDADO
		TEMPLATES -- PR�XIMO T�PICO
		
Ex:

Animal = *ptr

ptr = new Cachorro;
ptr -> emitirSom();

Assim iria chamar o m�todo emitirSom da classe base Animal, n�o da classe derivada Cachorro

	Vantagens do polimorfismo:
	
	Torna os programas extens�veis
	
A decis�o sobre qual o m�todo que deve ser selecionado, de acordo com o tipo da classe derivada,
� tomada em tempo de execu��o, atrav�s do mecanismo de liga��o tardia.
Em C++ isso ocorre utilizando-se ponteiros.

Usa-se uma vari�vel de um tipo �nico (do tipo da super-classe) para referenciar objetos variados 
do tipo das sub-classes.

Envolve o uso autom�tico do objeto armazenado na super-classe para selecionar um m�todo de uma 
das sub-classes. O tipo do objeto armazenado n�o e conhecido at� a execu��o do programa. 
A escolha do m�todo a ser executado � feita dinamicamente.		

Class Mamifero{

	public:
		Mamifero();
		virtual ~mamifero();
		virtual void emitir_som();
		void comer();
		virtual void andar();

	Protected:
		int idade;
};
		
ideal colocar o destrutor como virtual		
		
		
		
*/

#include <iostream>
#include <string>

using namespace std;

class Animal{

	public:
		Animal(string n = " ");
		string getNome();
		void emitirSom();
		
	private:
		string nome;

};

class Cachorro : public Animal{
	public:
		Cachorro(int p = 0);
		void emitirSom();
		void abanarRabo();

	private:
		int pulgas;

};

Animal::Animal(string n){
	nome = n;	
}

string Animal::getNome(){
	return nome;	
}

void Animal::emitirSom(){
	cout << "Estou falando " << endl;
}

Cachorro::Cachorro(int p){
	pulgas = p;
}

void Cachorro::emitirSom(){
	cout << "Au au" << endl;
}

void Cachorro::abanarRabo(){
	cout << "Estou abanando o rabo" << endl;
}



int main(int argc, char** argv) {
	
	
	
	
	
	return 0;
}
