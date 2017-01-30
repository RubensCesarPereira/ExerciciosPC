#include <iostream>

using namespace std;

template< class T>
class vetor //vetores de inteiros
{

public:
	template< class T >	
   vetor(int=10); 	//construtor. O parâmetro int define o tamanho do vetor
   ~vetor(); 		//destrutor
   int get_tamanho() const;	//retorna o tamanho do vetor
   bool SetValor(int pos, T val);	//altera o valor da posição "pos" para "val". 
   									//retorna "true" em caso de sucesso e falso em caso de insucesso
   bool GetValor(int pos, T& val) const; 	// em caso de sucesso, retorna "true" e o valor da posição "pos" em "val" (passada por referência). 
   void imprime() const; //método auxiliar para impressão do vetor na tela (console)

private:
   int tam;  			//tamanho do vetor
   T *ptrvalores;		//ponteiro para a primeira posição do vetor

   
};




template< class T >
vetor<T>::vetor(int t)
{
   if (t > 0) 
     tam = t;
   else
     tam = 10;                 

   ptrvalores = new T[tam];

   for (int i=0;i<tam;i++)
      SetValor(i,0);
}

template< class T>
vetor<T>::~vetor()
{
   delete [] ptrvalores;
}

template< class T>
int vetor::get_tamanho() const{
    return tam;   
}

template< class T>
bool vetor<T>::SetValor(int pos, T val)
{
   if (pos >=0 && pos < tam)
      {
      ptrvalores[pos] = val; 
      return true;
      }
   else 
      return false;   
}

template< class T>
bool vetor<T>::GetValor(int pos, T& val) const
{
    if (pos >= 0 && pos < tam)
      {
         val =ptrvalores[pos];
         return true;
      }
    else
        return false;
}

template< class T>
void vetor<T>::imprime() const
{
     T valor;
     for (int i=0;i<get_tamanho();i++){
        GetValor(i, valor);
        std::cout << valor << " ";
        }
     std::cout << std::endl;
}


int main(){
	
	vetor <int> Par;
	
	return 0;
}
