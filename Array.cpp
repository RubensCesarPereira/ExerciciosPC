#include <iostream>
using namespace std;


//Definição da classe

class Array{
	friend ostream &operator<<(ostream &, const Array &);
	friend istream &operator>>(istream &, Array &);
	
public:
	Array(int = 10); //construtor
	Array(const Array &); //construtor de cópia
	~Array();
	int getSize() const;
	
	//operador de atribuição
	const Array &operator=(const Array &);
	
	//operador de igualdade
	bool operator==(const Array &) const;
	
	//oposto do operador == 
	bool operator!=( const Array &right) const{
		return !(*this == right); //invoca Array::operator==
	}
		
	//operador de subscrito
	int &operator[](int);
	
	const int& operator[](int subscript) const;
	
	private:
		int size; //tamanho
		int *ptr; //ponteiro para o primeiro elemento do array
		
};



#include <iostream>

using namespace std;

#include <iomanip>
using std::setw;
#include <new>
#include <cstdlib>
// #include "array1.h" //definição de classe

//construtor padrão, com tamanho default de 10
Array::Array(int arraySize){
	//valida o array
	size = (arraySize > 0 ? arraySize : 10);
	ptr = new int[size]; //aloca o array
	for (int i = 0; i < size; i ++){
		ptr[i] = 0;			//inicializa o array
	}
	
}//fim do construtor

//construtor de cópia
//DEVE receber uma referencia para evitar loop infinito
Array::Array(const Array &arrayToCopy) : size(arrayToCopy.size){
	ptr = new int[size]; //aloca o array
	
	for(int i = 0; i < size; i++)
		ptr[i] = arrayToCopy.ptr[i]; //copia p/objeto
		
} //fim do construtor de cópia

//destrutor
Array::~Array(){
	delete [] ptr; //recupera espaço alocado anteriormente
}

int Array::getSize() const{
	return size;
}

//sobrecarga do operador de atribuição
//retornando const não permite: (a1 = a2) = a3
const Array &Array::operator=(const Array &right){
	if(right != *this){
		//verifica auto atribuição
		
		//p/arrays de tamanhos diferentes, eliminar original
		//e alocar novo array
		if(size != right.size){
			delete[] ptr; //recupera o espaço
			size = right.size; //redimensiona o objeto
			ptr = new int[size]; //aloca novo espaço
		}
		
		for(int i = 0; i < size; i++)
			ptr[i] = right.ptr[i]; //copia o array
			
		return *this; //permite x = y = z, por exemplo
		
	}
}
	
	//determina se dois arrays são iguais
	//retornando verdadeiro ou falso
	
	bool Array::operator==(const Array &right) const{
		if(size != right.size)
			return false; //tamanhos diferentes
			
		for(int i = 0; i < size; i++)
			if(ptr[i] != right.ptr[i])
				return false; //elemento diferente -> array diferente	
	
		return true; //iguais				
	}
		
	//sobrecarga de subscrito
	int &Array::operator[](int subscript){
		//verifica se indice está fora do range
		if(subscript < 0 || subscript >= size){
			cout << "\nErro: indice " << subscript
				 << " fora do range" << endl;
				 
			exit(1);
		} //end if
		
		return ptr[subscript];
	}
	
	//sobrecarga para arrays constantes
	const int &Array::operator[](int subscript) const{
		//verifica limites
		if(subscript < 0 || subscript >= size ){
			cout << "\nErro: Indice " << subscript
				 << " fora dos limites" << endl;
				 
			exit(1);
		}
		
		return ptr[subscript];
	}
	
	//sobrecarga de leitura
	istream &operator>>(istream &input, Array &a){
		for(int i = 0; i < a.size; i++)
			input >> a.ptr[i];
			
		return input; //permite cin >> x >> y;
		
	} 
	
	//sobrecarga de saída
	ostream &operator<<(ostream &output, const Array &a){
		int i;
		
		for(i = 0; i < a.size; i++){
			output << setw(12) << a.ptr[i];
			
			if((i + 1) % 4 == 0)
				output << endl;
		} //end for
		
		if(i % 4 != 0)
			output << endl;
			
		return output; //permite cout << x << y;
		
	}
	

#include <iostream>

using namespace std;

int main(){
	
	Array inteiro1(7);
	Array inteiro2;
	
	//imprime inteiro1 (tamanho e conteudo)
	cout << "Tamanho do array 1 é "
		 << inteiro1.getSize()
		 << "\n Array apos inicializacao:\n" << inteiro1;
		 
	//imprime inteiro2 (tamanho e conteudo)
	cout << "Tamanho do array 2 é "
		 << inteiro2.getSize()
		 << "\n Array apos inicializacao:\n" << inteiro2;
		 
	//le e imprime inteiro 1 e inteiro 2
	cout << "\n Entre com 17 inteiros:\n";
	cin >> inteiro1 >> inteiro2;
	
	cout << "\nAgora os arrays contem:\n"
		 << "inteiro1:\n" << inteiro1
		 << "inteiro2:\n" << inteiro2;
		 
	//usando(!=)
	cout << "\n usando != \n";
	
	if(inteiro1 != inteiro2)
		cout << "inteiro1 e inteiro2 sao diferentes\n";
		
	//criando array inteiros3 usando inteiro1 para inicializar
	
	Array inteiro3(inteiro1); //construtor de cópia
	
	cout << "\n Tamanho do array inteiros3 eh "
		 << inteiro3.getSize()
		 << "\nApos inicializar: \n" << inteiro3;
		 
	cout << "\n Atribuicao: \n";
	inteiro1 = inteiro2; //observar diferença de tamanho
	
	cout << "inteiro1: \n" << inteiro1
	     << " inteiro2:\n" << inteiro2;
		 
	//usando (==)
	cout << "\n usando == \n";
	
	if(inteiro1 == inteiro2)
		cout << "inteiro1 e inteiro2 sao iguais\n";
		
	//usando indice
	cout << "\ninteiro[5] é " << inteiro1[5];
	
	cout << "\n\nAtribuicao a inteiro1[5]\n";
	inteiro1[5] = 1000;
	cout << "inteiro1: \n" << inteiro1;
	
	//tentando acessar posicao fora do array
	cout << "\nInteiro1[15]" << endl;
	inteiro1[15] = 1000; //ERRO		 	 
		 	
	return 0;
			 
}
















