/* Polimorfismo

A decis�o sobre qual o m�todo que deve ser selecionado, 
de acordo com o tipo da classe derivada, � tomada em tempo 
de execu��o, atrav�s do mecanismo de liga��o tardia.

Em C++ isso ocorre utilizando-se ponteiros.

Polimorfismo � a capacidade de assumir formas diferentes.
Em termos de programa��o, polimorfismo reprsenta a capacidade de 
uma �nica vari�vel chamar m�todos diferentes, dependendo do que a
vari�vel cont�m. 

Maneira de escrever programas de forma gen�rica que permite a 
manipula��o de uma grande variedade de classes.

Aspectos importantes

Usa-se uma vari�vel de um tipo �nico (do tipo da super-classe) para 
referenciar objetos variados do tipo das sub-classes.

Envolve o uso autom�tico do objeto armazenado na super-classe para 
selecionar um m�todo de uma das subclasses. O tipo do objeto armazenado
n�o � conhecido at� a execu��o do programa.
A escolha do m�todo a ser executado � feita dinamicamente.

*/

class Mamifero{

	public:
		Mamifero();
		virtual ~Mamifero();
		virtual void emitir_som(); //� uma a��o que todos fazem, mas cada um de forma diferente
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
// Essa instru��o cria um novo objeto cachorro e retorna um ponteiro
//  para esse objeto, que � atribu�do a um ponteiro para mam�fero.
//Como cachorro � um mam�fero, OK

int main(){
	
	Mamifero *p_mamifero = new Cachorro;
	p_mamifero -> comer();
	p_mamifero -> emirtir_som();
	p_mamifero -> andar();
	
}


