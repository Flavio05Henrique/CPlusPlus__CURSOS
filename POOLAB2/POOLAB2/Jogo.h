#include <string>
using namespace std;

class Jogo
{
private:
	string nome;
	float preco;
	int horas;
	float custo;

	void caucular()
	{
		if (horas > 0)
			custo = preco / horas;
	}

public:
	void adquirir(const string& titulo, float valor)
	{
		nome = titulo;
		preco = valor;
		horas = 0;
		custo = valor;
	}
	void atualizar(float valor);
	void jogar(int tempo);
	void exibir();
};
