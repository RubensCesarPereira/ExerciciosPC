#include <iostream>

using namespace std;

int main(){ 
	
	int numeros[2];
	
	for(int i = 0; i < 3; i++){
		cin >> numeros[i];
	}
	
	
	//apenas para mostrar os números lidos:
	cout << "Numeros lidos: " << endl;
	for(int j = 0; j < 3; j++){
		cout  << numeros[j] << endl;
	}
	
	return 0; 
}
