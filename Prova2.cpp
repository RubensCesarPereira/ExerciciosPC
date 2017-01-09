#include <iostream>

using namespace std;

class Vetor2d{
	
	public:
		Vetor2d(int Vx, int Vy): x(Vx), y(Vy){/*vazio*/}
		Vetor2d():x(0), y(0){/*vazio*/}
		friend ostream & operator<<(ostream & saida, const Vetor2d& v);
		const Vetor2d operator* (const  Vetor2d& v) const;
		const Vetor2d operator++ (int k);	
		friend const Vetor2d operator* (int k, const  Vetor2d& v);
		bool operator!=(const Vetor2d& v)const;
		int getX() const;
		int getY() const;	
	private:
		int x, y;

};

class Vetor3d : public Vetor2d {
	
	public:
		Vetor3d(int Vx, int Vy, int Vz);
		~Vetor3d();
		void setZ(int Vz);
		int getZ() const;
		friend ostream & operator<<(ostream & saida, const Vetor3d& v);
	private:
		int z;	
		
};

Vetor3d::Vetor3d(int Vx, int Vy, int Vz): Vetor2d (Vx, Vy){
	
	z = Vz;
}

Vetor3d::~Vetor3d(){
}

void Vetor3d::setZ(int Vz){
	z = Vz;
}

int Vetor3d::getZ() const{
	return z;
}

ostream & operator<<(ostream & saida, const Vetor2d& v){
	saida << "(" << v.x << "," << v.y << ")";
	return saida;
}

int Vetor2d::getX() const{
	return x;
}

int Vetor2d::getY() const{
	return y;
}

ostream & operator<<( ostream & saida, const Vetor3d& v){
	
	saida << "(" << v.getX() << "," << v.getY() << "," << v.getZ() << ")";
	return saida;
}

const Vetor2d Vetor2d::operator*(const Vetor2d& v) const{
		return Vetor2d(x * v.x,y * v.y);
}

const Vetor2d Vetor2d::operator++(int k){
	Vetor2d rescopia = *this;
	x++;
	y++;
	return rescopia;
}

const Vetor2d operator*(int k, const Vetor2d& v){
	Vetor2d b;
	b.x = k * v.x;
	b.y= k * v.y;
	return b;	
}

bool Vetor2d::operator!=(const Vetor2d& v) const{
	
	if((x != v.x) || (y != v.y))
		return true;
	else
		return false;		
}

int main(){
	
	Vetor2d A(2,3), B(4,5), C;
	cout << "A=" << A<< endl;
	cout << "B=" << B << endl;
	C = A * B;
	cout << "C = A * B = " << C << endl;
	cout << "C++(incrementa x e y) = " << C++ << endl;
	cout << "C = " << C << endl;
	C = 2 * C;
	cout << "C = 2 * C = " <<  C << endl;
	if (C!=B)
		cout << "C e B são diferentes" << endl;
		
	Vetor2d v1(5,6);
	Vetor3d v2(7,8,9);
	cout << "v1= " << v1 << endl;
	cout << "v2= " << v2 << endl;

	return 0;	

}
