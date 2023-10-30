#include <iostream>
using namespace std;

void Aula1();
void Aula2VariaveisConstantesAtributos();

int main() 
{
	//Aula1();
	Aula2VariaveisConstantesAtributos();
}

void Aula1()
{
	cout << "Bem vindo ao" "C++\n";
	cout << "testando" << endl << "Fim";
	cout << endl;
	cout << "Meu primeiro programa!" << endl;
	system("pause");
}

void Aula2VariaveisConstantesAtributos()
{
	int cenouras;
	cenouras = 25;

	cout << "Eu tenho " << cenouras << " cenouras" << endl;

	cenouras -= 1;
	cout << "Eu tenho " << cenouras << " cenouras" << endl;

	cout << endl << "Formas de representar números\n";

	cout << 25 << " B10" << endl; //Decimal.
	cout << 0x19 << " B16" << endl;//Hexadecimal, base16, deve começar com 0x.
	cout << 031 << " B8" << endl;//Octal, base8, deve começar com 0.
	cout << 0b11001 << " B2" << endl;//Binário, base2, deve começar com 0b.

	cin >> cenouras;

	cout << "Novo cenouras: " << cenouras << endl;

	cout << "Multiplas leituras: " << endl;

	int mamao, abacaxi, papaia;

	cin >> mamao >> abacaxi >> papaia;
	cout << mamao << abacaxi << papaia << endl;
}