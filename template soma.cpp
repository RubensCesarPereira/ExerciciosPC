#include <iostream>

using namespace std;

template <typename Tgenerico>
	Tgenerico Soma(Tgenerico o1, Tgenerico o2){
		
		return o1 + o2;
		
	}
	
string Soma(char x, char y){
	
	char retorno[3];
	retorno[0] = x;
	retorno[1] = y;
	retorno[2] = '\0';
	return retorno;
	
}
	
	
	
	
int main(){
	
	double d1 = 2.5;
	double d2 = 2.0;
	
	cout << Soma(d1, d2) << endl;
	
	int i1 = 1;
	int i2 = 5;
	
	cout << Soma(i1, i2) << endl;
	
	string s1 = "teste";
	string s2 = "string";
	
	cout << Soma(s1, s2) << endl;
	
	char c1 = 'a';
	char c2 = 'b';
	
	cout << Soma(c1, c2) << endl;
	
	
	return 0;
}
