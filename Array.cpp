#ifndef ARRAY1_H
#define ARRAY1_H

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
		return !(this == right); //invoca Array::operator==
	}
		
	//operador de subscrito
	int &operator[](int);
	
	private:
		int size; //tamanho
		int *ptr; //ponteiro para o primeiro elemento do array
		
};

#endif

#include <iostream>

using namespace std;

#include <iompanip>
using std::setw;
#include <new>
#include <cstdlib>
#include "array1.h" //definição de classe

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
	if(right != this){
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
	} 
	
	//slide 7
	
	
}
