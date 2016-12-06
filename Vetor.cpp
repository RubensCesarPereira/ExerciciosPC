#include <iostream>
#include <math.h>

using namespace std;

//classe com funções para trabalhar com vetores

class Vetor{

	public:
		Vetor(double x = 0, double y = 0, double z = 0); //construtor
		void setX(double vx);
		void setY(double vy);
		void setZ(double vz);
		double getX();
		double getY();
		double getZ();
		double norma(Vetor v);
		Vetor soma(Vetor v);
		double produtoEscalar(Vetor v); //operator*
		Vetor produtoVetorial(); //operatorx
		void imprime();
	
	
	private:
		int x;
		int y;
		int z;

};

		Vetor::Vetor(double x, double y, double z){
			setX(x);
			setY(y);
			setZ(z);	
		} //construtor
		
		void Vetor::setX(double vx){
			x = vx;
		}
		
		void Vetor::setY(double vy){
			y = vy;
		}
		
		void Vetor::setZ(double vz){
			z = vz;
		}
		
		double Vetor::getX(){
			return x;
		}
		
		double Vetor::getY(){
			return y;
		}
		double Vetor::getZ(){
			return z;
		}
		double Vetor::norma(Vetor v){
			return sqrt(x*x + y*y + z*z);
		}
		
		Vetor Vetor::soma(Vetor v){
			Vetor a;
			a.setX(x + v.getX());
			a.setY(y + v.getY());
			a.setZ(z + v.getZ());
			
			return a;
		}
		
		double Vetor::produtoEscalar(Vetor v){ //operator*
			return x*v.getX() + y*v.getY() + z*v.getZ();
		}
		Vetor Vetor::produtoVetorial(){ //operatorx
		
	
		}
		
		void Vetor::imprime(){
			cout << x << "," << y << "," << z << endl; 
		}


int main(int argc, char** argv) {
	
	Vetor u(1,2,3);
	Vetor w;
	
	cout << "u = ";
	u.imprime(); 
	
	cout << "w = ";
	w.imprime(); 
	
	u.soma(w);
	
	
	
	
	return 0;
}
