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

*Verificar se o encapsulamento dos atributos e métodos está correto

*/

#include <iostream>

using namespace std;

#define nTipos 8 //define quantos "espaços" para produtos de tipos diferentes máquina possui

class VM
{

public:
	
	VM(); //construtor
	
	bool liga_desliga(); //liga ou desliga a máquina, invertendo o estado atual
	bool set_item(int n_item); //escolhe um dos itens disponíveis de acordo com o número digitado pelo usuário
	void setTroco(int n_item);
	float devolve_troco(); //libera o troco
	bool libera_produto(int n_item); //libera o produto escolhido
 	float set_preco(float preco); //
	int set_quantidade(int quantidade);
	bool destranca(int s);
	
	void setSaldo(float s); //
	float getSaldo();
	

private:
	
	int quantidadeItem[nTipos];
	string modelo;
	bool ligado;
	float precoItem[nTipos]; //vetor com o preço de cada item em 
	float saldo;
	float troco;
	bool trancado;   	
	bool motor[nTipos];
    
};

VM::VM(){ //construtor
	for(int i = 0; i < nTipos; i++){
		quantidadeItem[i] = 10;
	}
	
	modelo = " ";
	
	ligado = false;
	
	for(int i = 0; i < nTipos; i++){
		precoItem[i] = 2.00;
	}
	
	saldo = 0;
	troco = 0;
	trancado = false; 
	
}

bool VM::liga_desliga(){ 
	ligado = !ligado;
	
	if (ligado){
		return true; 
	} else{
		return false;
	}
}

void VM::setSaldo(float s){
	saldo = s;	
}

float VM::getSaldo(){
	return saldo;
	
}


bool VM::set_item(int n_item){ //cin >> "Digite o número do item" >>  
	
	if(quantidadeItem[n_item] > 0){
		quantidadeItem[n_item]--;
		return true;
		
	} else {
		return false;
		cout << "Item indisponível, escolha outro" << endl;
		
	}
	
	   	
}

void VM::setTroco(int item){
	troco = saldo - precoItem[item];
	
}


bool VM:: libera_produto(int n_item){
	if(saldo >= precoItem[n_item]){
		return true;
	}
	else{
		return false;	
	}
}
	
float VM::devolve_troco(){
	return troco;
}

int main()
{
    VM maq1; //declara um objeto maq1 da classe VM
    
    float saldo;
    int opcao;
    
    maq1.liga_desliga(); //liga a máquina
    if (maq1.liga_desliga())
    	cout << "A máquina ligou" << endl;
    
    
    cout << "$   Insira as moedas $   " << endl; 
    cout << "(Digite o valor inserido)" << endl;
    cin >> saldo; //como se o usuário inserisse moedas
    maq1.setSaldo(saldo); //coloca o valor inserido no atributo saldo 
    //VERIFICAR SE É POSSÍVEL CHAMAR O MÉTODO DIRETAMENTE:
 	//cin >> maq.setSaldo(x); algo assim
    
    cout << "Saldo: " << maq1.getSaldo() << endl; //mostra o saldo atual 
    
    cout << "Digite o numero do produto desejado:" << endl; //menu 
    cout << " (1)   Cheetos " << endl;
    cout << " (2)   Doritos " << endl;
    cout << " (3)    Kitkat " << endl;
    cout << " (4)  Amendoim " << endl;
    cout << " (5)   Bolinho  " << endl;
    cout << " (6)       Bis" << endl;
    cout << " (7)   Torcida" << endl;
    cout << " (8)    Cookie " << endl;
    
    cin >> opcao; //armazena o valor inserido na variável opcao
    if(maq1.set_item(opcao)){
    	cout << "Produto selecionado" << endl;
	}
	else{
		cout << "Item indisponível, escolha outro" << endl;
	}; 
    
    maq1.libera_produto(opcao); //chama a função que libera o produto, abre o compartimento etc
    
  	if(maq1.libera_produto(opcao)){
		cout << "Produto liberado ;)" << endl;
		maq1.setTroco(opcao); //cálculo do troco
    	cout << "Troco: " << maq1.devolve_troco() << endl; 
	}
	else{
		cout << "Saldo insuficiente" << endl;	
	}
    
    return 0;       
}
