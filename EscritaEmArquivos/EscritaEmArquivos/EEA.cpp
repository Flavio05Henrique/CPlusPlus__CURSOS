#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

struct Euu {
	char nome[50];
	int idade;
};

int main() {

	/*char nome[50];
	char fruta[50];
	char jogo[50];*/

	Euu Eu;

	strcpy(Eu.nome, "Flavio");
	Eu.idade = 22;

	ofstream arq;

	arq.open("Test.txt");

	/*cout << "digite seu nome: " << endl;
	cin >> nome;
	cout << "digite sua fruta fovorita: " << endl;
	cin >> fruta;
	cout << "digite seu jogo favorito:  " << endl;
	cin >> jogo;

	arq << "Nome: " << nome << " Fruta: " << fruta << " Jogo: " << jogo;
	arq << " nada ";*/

	arq << Eu.nome << Eu.idade;

	arq.close();

	
}