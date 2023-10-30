#include <iostream>
#include "Jogo.h"

void Jogo::atualizar(float valor)
{
	preco = valor;
	caucular();
}

void Jogo::jogar(int tempo)
{
	horas = tempo;
	caucular();
}

void Jogo::exibir()
{
	cout << "------------------------------------------" << endl;
	cout << nome << endl;
	cout << "------------------------------------------" << endl;
	cout << "Preço: " << preco << endl;
	cout << "Horas:" << horas << endl;
	cout << "Custo: " << custo << endl;
}