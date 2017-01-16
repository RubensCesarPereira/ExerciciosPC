/*
	Polimorfismo de inclusão 
	
	A partir de um ponteiro da classe base chama o método e se estiver usando polimorfismo, chama o método apropriado 
	de acordo com o que o ponteiro está apontando.
	
	Se colocar o virtual em qualquer método da classe base, ele é propragado para os outros.
	
	A decisão sobre qual o método que deve ser selecionado, de acordo com o tipo da classe derivada, é tomada
	em tempo de execução, através do mecanismo de ligação tardia. Em C++ isso ocorre utilizando-se ponteiros.
	
	Ponteiro da classe base apontando para objetos das classes derivadas.
	
	A palavra-chave virtual na frente do método faz com que "deixe um espaço" para que a ligação seja feita apenas no 
	momento da execução.
	
	O construtor nunca é virtual
	
	REGRA GERAL - Se um dos métodos da classe for virtual, o destrutor também deverá ser
	


*/

#include <iostream>

using namespace std;

class Mamifero{
	
	public: 
		Mamifero();
		virtual ~Mamifero();
		virtual void emitir_som();
		void comer();		//nao tem o virtual
		virtual void andar();
		
	protected:
		int idade;
};

class Cachorro{
	
	public:
		Cachorro();
		~Cachorro();
		void emitir_som(); //sobrescreve da classe base - mesmo  não tendo virtual, é virtual pois foi definido na classe base
		void comer();	  //sobrescreve da classe base
		void abanar_rabo();
		//o método adicionado (abanar_rabo()) não pertence a mamífero. Assim, não existe uma maneira simples de você acessar
		//o método abanar_rabo() tendo criado um ponteiro para mamífero.
		
	protected:
		int raca;
};



int main(){
	
	Mamifero *p_mamifero = new Cachorro;
	p_mamifero -> comer(); //de acordo com o tipo do ponteiro - ligação estática
	p_mamifero-> emitir_som(); //de acordo com o conteúdo do ponteiro - ligação tardia
	p_mamifero -> andar();	//cachorro tem andar() pois herdou genérico de Mamifero - ligação tardia 

	return 0;

}
