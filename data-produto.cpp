#include <iostream>

using namespace std;

class Data {
	public:
		Data(int udia=1, int umes=1, int uano=2012);
		int getDia();
		int getMes();
		int getAno();
		void setDia(int d);
		void setMes(int m);
		void setAno(int a);
		string toString();
	private:
		int dia, mes, ano;
};

class Produto {
	public:
		Produto(int cod, string descr, const Data &val);
		int getCodigo();
		string getDescricao();
		Data getValidade();
		string toString();
		
	private:
		int codigo;
		string descricao;
		Data validade;
};

int main()
{
	// Cria um objeto Data e já ajusta os seus atributos
	Data d1(5,5,2007);

	Produto p1(56,"Bolo de chocolate", d1);

	// Alternativa: cria-se um objeto "anônimo" na própria chamada
	// ao construtor de Produto

	Produto p2(57,"Bolo de laranja", Data(12,7,2007));
	
	// Escreve os dados de p1 e p2
	cout << p1.toString() << endl;
	cout << p2.toString() << endl;
	
	return 0;
}
