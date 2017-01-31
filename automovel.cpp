#include <iostream>
#include <string>
using namespace std;

class Pneu{
	
	public:
		
		Pneu(string m = " ", float p = 0);
		
		void set_marca(string m);
		string get_marca() const;
		
	private:
		string marca;
		float pressao;
		
};

Pneu::Pneu(string m, float p){
	marca = m;
	pressao = p;
}
		
void Pneu::set_marca(string m){
	marca = m;
}
string Pneu::get_marca() const{
	return marca;
}
		

class Motor{
	
	public:
		Motor(float c = 0, float p =0);
		void set_combustivel(float c);
		float get_combustivel() const;
		
	private:
		float combustivel, potencia;
		
};


Motor::Motor(float c, float p){
	combustivel = c;
	potencia = p;
}
void Motor::set_combustivel(float c){
	combustivel = c;
}
float Motor::get_combustivel() const{
	return combustivel;
}

class Automovel{
	
	public:
		
		Automovel(string m, float k, Pneu p, Motor mt){
			marca = m;
			km = k;
			this.set_marca(p.marca);
			this.set_combustivel(p.combustivel);
		};
		
	private:
		string marca;
		float km;
		Pneu p1, p2, p3, p4;
		Motor m;
		
};

int main(){
	
	Motor m1(200, 300);
	
	Automovel carro();
	
	cout << carro.get_cosbustivel();
	
	
}


