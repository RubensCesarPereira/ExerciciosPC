//	Leila Aparecida da Silva - 628166
//	Usando Composição

#include <iostream>

using namespace std;

class Ponto{
	
	public:
		Ponto(); //construtor
		~Ponto(); //destrutor
		void setX(double vx = 0);
		void setY(double vy = 0);
		double getX() const;
		double getY() const;
		void print() const;
	private:
		double x;
		double y;
};

void Ponto::setX(double vx){
	x = vx;
}

void Ponto::setY(double vy){
	y = vy;
}

double Ponto::getX() const{
	return x;
}

double Ponto::getY() const{
	return y;
}

void Ponto::print() const{
	
}

class Circulo{
	
	public:
		Circulo(); //construtor
		~Circulo(); //destrutor
		void setRaio(double r);
		double getRaio() const;
		
    private:
		Ponto pt; 
		double raio;
};

Circulo::Circulo(){
	
}

Circulo::~Circulo(){
	
}

void Circulo::setRaio(double r){
	raio = r;
}

double Circulo::getRaio() const{
	return raio;
}

class Cilindro{
	
	public:
		   Cilindro(); //construtor
		   ~Cilindro(); //destrutor
		   
		   	
    private:
			Circulo circ;
			double altura;
};


int main(){
	
	
}
