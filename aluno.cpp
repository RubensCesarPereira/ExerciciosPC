#include <iostream>
#include <string>
#include <string.h>

#define numNotas 3

//sem os const

using namespace std;

class Aluno{
	
	public:
		Aluno(); //construtor
		Aluno(string nome, int nro_notas); //construtor com parametros
		~Aluno(); //destrutor
		void setNome(string n); //seta um nome para o aluno
		string getNome(); //retorna o nome do aluno, constante pois não altera
		int getRA(); //retorna o RA, constante pois não altera
		int getNroNotas();
		bool setNroNotas(int nr);
		bool setNota(int pos, double *valor);
		bool getNota(int pos, double *valor);
		//static int getProxRA();
		
	private: 
		string nome;
		int RA;
		int nro_notas;
		double *ptr;
	
		static int cont_ra;   	
};

int Aluno::cont_ra;

Aluno::Aluno(){
	
	nome = "maria";
	cont_ra ++;
	setNroNotas(10);
	ptr = new double [getNroNotas()]; //número padrao de notas
	RA = Aluno::cont_ra;
	
	for(int i = 0; i < numNotas; i++){
		ptr[i] = 1;
	}
}


Aluno::Aluno(string nome, int nro_notas ){
	
	setNome(nome);
	cont_ra ++;
	ptr = new double [nro_notas];
	//RA = Aluno::cont_ra;
	
	setNroNotas(nro_notas);
	
	for(int i = 0; i < nro_notas; i++){
		std::cout << "Digite a nota da prova " << i << std::endl;
		std::cin >> ptr[i];
		
	}
}

Aluno::~Aluno(){
	
	delete [] ptr;
}

void Aluno::setNome(string n){
	nome = n;
}

string Aluno::getNome(){
	cout << "getNome rodou" << endl;
	return nome;
}

int Aluno::getRA(){
	cout << "getRA rodou" << endl;
	return RA;
}


bool Aluno::setNroNotas(int nr){
	//if...
	nro_notas = nr;
	return true;
}

int Aluno::getNroNotas(){
	cout << "getNroNotas rodou" << endl;
	return nro_notas;
}

bool Aluno::setNota(int pos, double *valor){
	if((pos >= 0) && pos <= (getNroNotas())){
		ptr[pos] = *valor;
		return true;
	}
	else
		return false;
	
}

bool Aluno::getNota(int pos, double *valor){
	cout << "getNota rodou" << endl;
	if(pos >= 0 && pos <= getNroNotas()){
		*valor = ptr[pos];
		return true;
	}
	else
		return false;
	
	
}

/*int Aluno::getProxRA(){
	return RA;
}*/



#include <iostream>


int main(int argc, char** argv) {
	
	Aluno aluno1; //declara um aluno 1
	std::cout << "Nome do aluno 1:";
	std::cout << aluno1.getNome() << std::endl;
	std::cout << "-------------------------------------" << endl;
	
	std::cout << "RA do aluno 1:";
	std::cout << aluno1.getRA() << std::endl;
	std::cout << "-------------------------------------" << endl;
	
	std::cout << "Número de notas do aluno 1:";
	std::cout << aluno1.getNroNotas() << std::endl;
	std::cout << "-------------------------------------" << endl;
	
	std::cout << "Nota 1 do aluno 1:";
	double nota1;
	std::cout << aluno1.getNota(1, &nota1) <<endl;
	std::cout << "-------------------------------------" << endl;
	
	std::cout << "Nota 1 do aluno 1 na variável:";
	std::cout << nota1 << std::endl;
	
	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" "<< endl;
	
	Aluno aluno2("Joao", 5);
	
	std::cout << "Nome do aluno 21:";
	std::cout << aluno2.getNome() << std::endl;
	std::cout << "-------------------------------------" << endl;
	
	std::cout << "RA do aluno 2:";
	std::cout << aluno2.getRA() << std::endl;
	std::cout << "-------------------------------------" << endl;
	
	std::cout << "Número de notas do aluno 2:";
	std::cout << aluno2.getNroNotas() << std::endl;
	std::cout << "-------------------------------------" << endl;
	
	std::cout << "Nota 1 do aluno 2:";
	double nota4;
	std::cout << aluno1.getNota(4, &nota4) <<endl;
	std::cout << "-------------------------------------" << endl;
	
	std::cout << "Nota 4 do aluno 2 na variável:";
	std::cout << nota1 << std::endl;
	
	
	return 0;
}
