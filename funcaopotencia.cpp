#include <iostream>

using namespace std;

	double potencia(double x, int n){
	if (n == 0)
		return 1;
	else if(n == 1)
		return x;
	
	return x * potencia(x, n - 1);
}

//exemplo
int main(){

	cout << potencia(8, 2) << endl;	
		
	return 0;
}
