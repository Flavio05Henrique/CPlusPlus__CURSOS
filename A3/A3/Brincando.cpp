#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct jogador
{
	char nome[20] = "nome";
	string sobreNome = "sobrenome";
	int dataDeNascimento = 1;
	int dataDoRegistro = 1;
	unsigned partidasGanhas = 0;
	float salarioPorPartida = 0.0;
};

int main() {
	jogador alex;
	// jogador alex = {"Alex", 2000, 2023, 300, 5000.55} // Outra forma de inicializar.
	strcpy(alex.nome, "Alex");
	alex.sobreNome = "santos";
	alex.dataDeNascimento = 2000;
	alex.dataDoRegistro = 2023;
	alex.partidasGanhas = 300;
	alex.salarioPorPartida = 5000.55;

	int idadeEstimada = alex.dataDoRegistro - alex.dataDeNascimento;
	float dinheiroGanhoNaCarreira = alex.partidasGanhas * alex.salarioPorPartida;

	cout << "----------------------------------------------" << endl;
	cout << "Exibindo dados do jogador: " << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Nome: " << alex.nome << " " << alex.sobreNome << " | "
		<< "Data de nascimento: " << alex.dataDeNascimento << " | "
		<< "Data de registro: " << alex.dataDoRegistro << " | "
		<< "Idade estimada: " << idadeEstimada << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Exibindo dados da carreira: " << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Partidas ganhas: " << alex.partidasGanhas << " "
		<< "Salario por partida: " << alex.salarioPorPartida << " "
		<< "Dinheiro ganho durante carreira: " << fixed << dinheiroGanhoNaCarreira << endl;

	cout << strlen(alex.nome) << endl;

	for (int i = 0; i < strlen(alex.nome); i++) {
		cout << alex.nome[i];
	}
}