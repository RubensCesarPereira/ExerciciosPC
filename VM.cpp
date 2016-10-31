/*

Leila Aparecida da Silva - 628166

Anotações pra gente ter uma base do que fazer:

Fluxo genérico de funcionamento

- A máquina é ligada (liga_desliga)
- Usuário insere as moedas (setSaldo)
- Escolhe o produto (escolhe_item)
- A máquina libera o produto
- A máquina calcula o troco (setTroco)
- Devolve o troco (devolve_troco)

*Verificar se o saldo é suficiente para a compra
*Verificar se o encapsulamento dos atributos e métodos está correto
*Há necessidade de criar métodos get? Talvez utilizar os retornos destes no programa principal,
	para mostrar o que acontece após uma instrução. 
	 
*/

#include <iostream>

using namespace std;

#define nTipos 8 //define quantos "espaços" para produtos de tipos diferentes máquina possui

class VM
{

public:
	
	VM(); //construtor
	
	void liga_desliga(); //liga ou desliga a máquina, invertendo o estado atual
	void escolhe_item(int n_item); //escolhe um dos itens disponíveis de acordo com o número digitado pelo usuário


private:
	
	float devolve_troco(); //libera o troco
	bool libera_produto(int n_item); //libera o produto escolhido
 	float set_preco(float preco); //
	int set_quantidade(int quantidade);
	bool destranca(int s);
	
	void setSaldo(float s); //
	void setTroco(float t);
	
	int quantidadeItem[nTipos];
	string modelo;
	bool ligado;
	float precoItem[nTipos]; //vetor com o preço de cada item em 
	float saldo;
	float troco;
	bool trancado;   	
	bool motor[nSlots];
    
};

VM::VM(){
	for(int i = 0 i < nTipos; i++){
		quantidadeItem[i] = 0;
	}
	
	modelo = " ";
	
	ligado = false;
	
	for(int i = 0 i < nTipos; i++){
		precoItem[i] = 0;
	}
	
	saldo = 0;
	troco = 0;
	trancado = false; 
	
}

void VM::liga_desliga(){
	ligado = !ligado;
	
	if (ligado){
		cout << "A máquina ligou" << endl;
	} else{
		cout << "A máquina desligou" << endl;
	}
}

void VM::set_saldo(float s){
	saldo = s;
	
	cout << "Saldo atual: " << saldo << endl; 
	
}

void VM::escolhe_item(int n_item){ //cin >> "Digite o número do item" >>  
	
	if(quantidadeItem[n_item] > 0){
	
		quantidadeItem[n_item]--;
		setTroco(n_item);
	} else {
		cout << "Item indisponível, escolha outro" << endl;
		
	}
	
	   	
}

void VM::setTroco(int item){
	troco = saldo - precoItem[item];
	
	cout << "Troco: " << 
}


bool VM:: libera_produto(int n_item){
	motor[n_item] = true;
	
	return true;
}
	
float VM::devolve_troco(float t){
	return troco;
}

int main()
{
    
    return 0;       
}
