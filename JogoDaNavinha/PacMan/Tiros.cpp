#include "Tiros.h"


Tiros::Tiros(Scene* scene)
{
	img = new Image("Resources/foguete.png");
	indexTiro = 0;

	for (int i = 0; i < tirosList.size(); i++)
	{
		Tiro* tiro = new Tiro(i, img);
		tirosList[i] = tiro;
		scene->Add(tirosList[i], STATIC);
	}
}

Tiros::~Tiros()
{
	delete img;
}

void Tiros::Atirar()
{
	if (indexTiro == tirosList.size())
		indexTiro = 0;
	
	tirosList[indexTiro]->Stop();
	tirosList[indexTiro]->Fogo();
	indexTiro++;
	
}
