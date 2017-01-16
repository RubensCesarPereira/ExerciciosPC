/*
	Polimorfismo de inclus�o 
	
	A partir de um ponteiro da classe base chama o m�todo e se estiver usando polimorfismo, chama o m�todo apropriado 
	de acordo com o que o ponteiro est� apontando.
	
	Se colocar o virtual em qualquer m�todo da classe base, ele � propragado para os outros.
	
	A decis�o sobre qual o m�todo que deve ser selecionado, de acordo com o tipo da classe derivada, � tomada
	em tempo de execu��o, atrav�s do mecanismo de liga��o tardia. Em C++ isso ocorre utilizando-se ponteiros.
	
	Ponteiro da classe base apontando para objetos das classes derivadas.
	
	A palavra-chave virtual na frente do m�todo faz com que "deixe um espa�o" para que a liga��o seja feita apenas no 
	momento da execu��o.
	
	O construtor nunca � virtual
	
	REGRA GERAL - Se um dos m�todos da classe for virtual, o destrutor tamb�m dever� ser
	


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
		void emitir_som(); //sobrescreve da classe base - mesmo  n�o tendo virtual, � virtual pois foi definido na classe base
		void comer();	  //sobrescreve da classe base
		void abanar_rabo();
		//o m�todo adicionado (abanar_rabo()) n�o pertence a mam�fero. Assim, n�o existe uma maneira simples de voc� acessar
		//o m�todo abanar_rabo() tendo criado um ponteiro para mam�fero.
		
	protected:
		int raca;
};



int main(){
	
	Mamifero *p_mamifero = new Cachorro;
	p_mamifero -> comer(); //de acordo com o tipo do ponteiro - liga��o est�tica
	p_mamifero-> emitir_som(); //de acordo com o conte�do do ponteiro - liga��o tardia
	p_mamifero -> andar();	//cachorro tem andar() pois herdou gen�rico de Mamifero - liga��o tardia 

	return 0;

}
