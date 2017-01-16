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
		
ideal colocar o DESTRUTOR COMO VIRTUAL, sempre que usar algum método virtual na classe		
*/

#include <iostream>
#include <string>

using namespace std;

class Animal{

	public:
		Animal(string n = " ");
		virtual ~Animal();
		string getNome() const;
		virtual void emitirSom() const;                               //virtual só no protótipo
		virtual void comer() const;
		
	private:
		string nome;

};

class Carneiro : public Animal{
	public:
		Carneiro(int p = 0);
		~Carneiro();
		void emitirSom() const;
		void pular() const;

	private:
		int pulgas;

};

Carneiro::Carneiro(int p){
	pulgas = p;
} 

void Carneiro::emitirSom() const{
	cout << "Fazendo som de carneiro" << endl;
}

void Carneiro::pular() const{
	cout << "*Pulando*" << endl;
}

class Cachorro : public Animal{
	public:
		Cachorro(int p = 0);
		~Cachorro();
		void emitirSom() const;
		void abanarRabo() const;

	private:
		int pulgas;

};

class Gato : public Animal{
	
	public:
		Gato(string Anome = " "): Animal(string n){};
		void emitirSom() const;
		
		
};

class Poodle : public Cachorro{
	
	public:
		Poodle(string Anome = ""): Cachorro(int p = 0){};
		void emitirSom() const{ cout << "*Latindo como Poodle*" << endl;};
		void abanarRabo() const{cout << "*Abanado rabo como Poodle*" << endl;};
		
	private:
		
};

class Vira : public Cachorro{
	
	public:
		Vira(string Anome = ""): Cachorro(int p = 0){};
		void emitirSom() const{ cout << "*Latindo como um vira-lata*" << endl;};
		void abanarRabo() const{cout << "*Abanado rabo como um vira-lata*" << endl;};
		
	private:
		
};



Animal::Animal(string n){
	nome = n;	
}

Animal::~Animal(){
	cout << "destrutor de animal" << endl;
}

string Animal::getNome() const{
	return nome;	
}

void Animal::emitirSom() const{
	cout << "Estou falando " << endl;
}

void Animal::comer() const{
	cout << "Estou comendo " << endl;
}

Cachorro::Cachorro(int p){
	pulgas = p;
}

void Cachorro::emitirSom() const{
	cout << "Au au" << endl;
}

void Cachorro::abanarRabo() const{
	cout << "Estou abanando o rabo" << endl;
}

Cachorro::~Cachorro(){
	cout << "tchau, ja limpei tudo" << endl;
}

void FalaAnimal(Animal * a){
	a->emitirSom();
}

/*void FalaAnimal(Animal a){
	a.emitirSom();
} */


int main(int argc, char** argv) {
	
	Animal *vetor[100] = {NULL}; //inicializando o vetor todo com null
	
	vetor[0] = new Cachorro(5);
	vetor[1] = new Gato(4);
	vetor[2] = new Cachorro(2);
	vetor[3] = new Carneiro(2);
	vetor[4] = new Poodle(3);
	vetor[5] = new Vira(4);
	
	
	for(int i = 0; i < 100; i++)
		if(vetor[i]!= NULL)
			FalaAnimal(vetor[i]);
	
	
	/*
	Animal * ptr;
	ptr = new Cachorro(5);
	ptr-> emitirSom();
	ptr-> comer();
	delete ptr; */
	
	/*Cachorro c1(5);
	FalaAnimal(&c1);
	*/
	
	return 0;
}
