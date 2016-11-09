/* Classe Aluno

- Nome: string
- RA: int {const}
- nro_notas: int
- *ptr: double* //ponteiro para o vetor de notas
- contador: int {static}

+ aluno(nome: string, nro_notas: int)
+ setNome(nome: string): void
+ getNome(): string 
+ getRA()? int {const}
+ getNroNotas(): int {const}
+ setNota(pos: int, valor: double): bool
+ getNota(pos: int, valor: double): bool
+ getProxRA(): int {static}


Aluno(string nome, int nro_notas): RA(cont_ra){

}




*/

#include <iostream>
#include <string>

#define numNotas 3

using std::string;

class Aluno{
	
	public:
		Aluno(); //construtor
		Aluno(string nome, int nro_notas);
		~Aluno();
		void setNome(string n);
		string getNome() const;
		int getRA() const;
		int getNroNotas() const;
		bool setNota(int pos, double *valor);
		bool getNota(int pos, double *valor) const;
		static const int getProxRA();
		
		
	private:
		string nome;
		const int RA;
		int nro_notas;
		double *ptr;
	
	static int cont_ra;	
};

int Aluno::cont_ra;

Aluno::Aluno(): RA(cont_ra){
	
	nome = " ";
	cont_ra ++;
	ptr = new double [numNotas]; //número padrao de notas
	RA = Aluno::cont_ra;
	
	for(int i = 0; i < numNotas; i++){
		ptr[i] = 0;
	}
}


Aluno::Aluno(string nome, int nro_notas ): RA(cont_ra){
	
	setNome(nome);
	cont_ra ++;
	ptr = new double [nro_notas];
	RA = cont_ra;
	
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

string Aluno::getNome() const{
	return nome;
}

int Aluno::getRA() const{
	return RA;
}

int Aluno::getNroNotas() const{
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

bool Aluno::getNota(int pos, double *valor) const{
	if(pos >= 0 && pos <= getNroNotas()){
		*valor = ptr[pos];
		return true;
	}
	else
		return false;
	
	
}

const int Aluno::getProxRA() const{
	return RA;
}



#include <iostream>


int main(int argc, char** argv) {
	
	Aluno aluno1;
	std::cout << aluno1.getNome() << std::endl;
	std::cout << aluno1.getRA() << std::endl;
	std::cout << aluno1.getNroNotas() << std::endl;
	
	double nota1;
	std::cout << aluno1.getNota(1, nota1) << std::endl;
	std::cout << nota1 << std::endl;
	return 0;
}
