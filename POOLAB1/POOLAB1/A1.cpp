#include <iostream>
#include <string>
using namespace std;

struct Jogo
{
	string nome;
	float preco;
	int horas;
	float custo;
};

Jogo adquirir(const string& titulo, float valor);
void atualiza(Jogo& jogo, float valor);
void joga(Jogo& jogo, int tempo);
void exibir(const Jogo& jogo);

void main()
{
	Jogo game;
	game = adquirir("Pokemon", 150.50);
	
	atualiza(game, 200.99);
	joga(game, 100);
	exibir(game);
}

Jogo adquirir(const string& titulo, float valor)
{
	Jogo game;

	game.nome = titulo;
	game.preco = valor;
	game.horas = 0;
	game.custo = valor;

	return game;
}

void atualiza(Jogo& jogo, float valor)
{
	jogo.preco = valor;

	if (jogo.horas > 0)
		jogo.custo = jogo.preco / jogo.horas;
}

void joga(Jogo& jogo, int tempo)
{
	jogo.horas = tempo;

	if(jogo.horas > 0)
		jogo.custo = jogo.preco / jogo.horas;
}

void exibir(const Jogo& jogo)
{
	cout << "------------------------------------------" << endl;
	cout << jogo.nome << endl;
	cout << "------------------------------------------" << endl;
	cout << "Preço: " << jogo.preco << endl;
	cout << "Horas:" << jogo.horas << endl;
	cout << "Custo: " << jogo.custo << endl;
}