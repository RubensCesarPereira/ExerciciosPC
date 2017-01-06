#include <iostream>

using namespace std;

int main(){
	
	int alt, larg, largura, altura;
	
	cout << "Digite a largura: ";
	
	cin >> larg;
	
	cout << endl << "Digite a altura: ";
	cin >> alt;
	
	if(larg <= 25 && alt <= 25){
		largura = larg;
		altura = alt;
		cout << endl;
	
	for(int i = 0; i < altura; i++){
		for(int j = 0; j < largura; j++){
			cout << "*";
		}
		
		cout << endl;
	}
	} else{
		cout << "O numero maximo de ambos os lados deve ser 25" << endl;
	}
	
	return 0;
	
}
