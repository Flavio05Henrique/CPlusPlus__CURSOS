#include "Tiros.h"


Tiros::Tiros(Scene* scene, Image* Img, int tipo)
{
	img = Img;
	indexTiro = 0;

	for (int i = 0; i < tirosList.size(); i++)
	{
		Tiro* tiro = new Tiro(img, tipo);
		tirosList[i] = tiro;
		scene->Add(tirosList[i], STATIC);
	}
}

Tiros::~Tiros()
{
	delete img;
}

void Tiros::Atirar(float posicaoJogadorX, float posicaoJogadorY, float direcaoYDoTiro)
{
	if (indexTiro == tirosList.size())
		indexTiro = 0;

	tirosList[indexTiro]->Fogo(posicaoJogadorX, posicaoJogadorY, direcaoYDoTiro);
	indexTiro++;
	
}
