#include <iostream>

using namespace std;

class Contador{
	
	public:
		Contador(int c = 0){contador = c;};
		int getContador(){return contador;};
		void operator++(){++contador;};
    private:
    	int contador;
};

int main(){
	
	Contador c1, c2;
	
	++c1;
	++c2;
	++c2;
	++c2;
	
	cout << "c1: " << c1.getContador() << endl;
	cout << "c2: " << c2.getContador() << endl;	
	
	return 0;
}
