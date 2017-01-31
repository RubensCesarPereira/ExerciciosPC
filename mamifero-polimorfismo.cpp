/* Polimorfismo

A decisão sobre qual o método que deve ser selecionado, 
de acordo com o tipo da classe derivada, é tomada em tempo 
de execução, através do mecanismo de ligação tardia.

Em C++ isso ocorre utilizando-se ponteiros.

Polimorfismo é a capacidade de assumir formas diferentes.
Em termos de programação, polimorfismo reprsenta a capacidade de 
uma única variável chamar métodos diferentes, dependendo do que a
variável contém. 

Maneira de escrever programas de forma genérica que permite a 
manipulação de uma grande variedade de classes.

Aspectos importantes

Usa-se uma variável de um tipo único (do tipo da super-classe) para 
referenciar objetos variados do tipo das sub-classes.

Envolve o uso automático do objeto armazenado na super-classe para 
selecionar um método de uma das subclasses. O tipo do objeto armazenado
não é conhecido até a execução do programa.
A escolha do método a ser executado é feita dinamicamente.

*/

class Mamifero{

	public:
		Mamifero();
		virtual ~Mamifero();
		virtual void emitir_som(); //é uma ação que todos fazem, mas cada um de forma diferente
		void comer();
		virtual void andar();
	protected:
		int idade;

};

class Cachorro : Mamifero{
	
	public:
		Cachorro();
		~Cachorro(); 
		void emitir_som();
		void comer();
	protected:
		int raca;
	
};

//	Mamifero *P_mamifero = new cachorro;
// Essa instrução cria um novo objeto cachorro e retorna um ponteiro
//  para esse objeto, que é atribuído a um ponteiro para mamífero.
//Como cachorro é um mamífero, OK

int main(){
	
	Mamifero *p_mamifero = new Cachorro;
	p_mamifero -> comer();
	p_mamifero -> emirtir_som();
	p_mamifero -> andar();
	
}


