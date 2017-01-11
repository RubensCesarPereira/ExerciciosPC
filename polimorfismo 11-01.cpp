/*

POLIMORFISMO:
	AD HOC
		SOBRECARGA
		COERÇÃO
		
		
	UNIVERSAL
		SUB TIPO -- ESTE VAI SER O ESTUDADO
		TEMPLATES -- PRÓXIMO TÓPICO
		
Ex:

Animal = *ptr

ptr = new Cachorro;
ptr -> emitirSom();

Assim iria chamar o método emitirSom da classe base Animal, não da classe derivada Cachorro

	Vantagens do polimorfismo:
	
	Torna os programas extensíveis
	
A decisão sobre qual o método que deve ser selecionado, de acordo com o tipo da classe derivada,
é tomada em tempo de execução, através do mecanismo de ligação tardia.
Em C++ isso ocorre utilizando-se ponteiros.

Usa-se uma variável de um tipo único (do tipo da super-classe) para referenciar objetos variados 
do tipo das sub-classes.

Envolve o uso automático do objeto armazenado na super-classe para selecionar um método de uma 
das sub-classes. O tipo do objeto armazenado não e conhecido até a execução do programa. 
A escolha do método a ser executado é feita dinamicamente.		

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
