/*

Leila Aparecida da Silva - 628166

Anotações pra gente ter uma base do que fazer:

Fluxo genérico de funcionamento

- A máquina é ligada (liga_desliga)
- Usuário insere as moedas (setSaldo)
- Escolhe o produto (set_item)
- A máquina calcula se o saldo é suficiente;
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
	void set_item(int n_item); //escolhe um dos itens disponíveis de acordo com o número digitado pelo usuário


private:
	
	float devolve_troco(); //libera o troco
	string libera_produto(int n_item); //libera o produto escolhido
 	float set_preco(float preco); //
	int set_quantidade(int quantidade);
	bool destranca(int s);
	
	void setSaldo(float s); //
	void setTroco(float t);
	float getSaldo();
	
	int quantidadeItem[nTipos];
	string modelo;
	bool ligado;
	float precoItem[nTipos]; //vetor com o preço de cada item em 
	float saldo;
	float troco;
	bool trancado;   	
	bool motor[nTipos];
    
};

VM::VM(){
	for(int i = 0; i < nTipos; i++){
		quantidadeItem[i] = 0;
	}
	
	modelo = " ";
	
	ligado = false;
	
	for(int i = 0; i < nTipos; i++){
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

void VM::set_item(int n_item){ //cin >> "Digite o número do item" >>  
	
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


string VM:: libera_produto(int n_item){
	if(this.saldo >= this.precoItem[n_item]){
		return "Produto liberado ;)";
	else
		return "Saldo insuficiente";	
	
}
	
float VM::devolve_troco(float t){
	return troco;
}

int main()
{
    VM maq1; //declara um objeto maq1 da classe VM
    
    float saldo;
    int opcao;
    
    maq1.liga_desliga(); //liga a máquina
    
    cout << "Digite a quantidade de dinheiro inserido: " << endl;
    cin >> saldo;
    maq1.setSaldo(saldo);
    maq1.getSaldo();
    
    cout << "Digite o número do produto desejado:" << endl;
    cout << " (1)   Salgadinho 1 " << endl;
    cout << " (2)   Salgadinho 2 " << endl;
    cout << " (3)   Salgadinho 3 " << endl;
    cout << " (4)         Doce 1 " << endl;
    cout << " (5)         Doce 2 " << endl;
    cout << " (6) Refrigerante 1 " << endl;
    cout << " (7) Refrigerante 2 " << endl;
    cout << " (8) Refrigerante 3 " << endl;
    
    cin >> opcao;
    maq1.set_item(opcao);
    
    
    
    m1.libera_produto();
    
    
    
    return 0;       
}
