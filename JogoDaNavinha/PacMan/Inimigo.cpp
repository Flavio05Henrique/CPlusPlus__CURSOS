#include "Inimigo.h"
#include "ObjectTypes.h"
#include <random>

Inimigo::Inimigo(Tiros* Tiros, float alturaInicial)
{
	sprite = new Sprite("Resources/NaveInimiga.png");
	tiros = Tiros;

	type = INIMIGO;

	velX = 250.0f;
	vida = 10;
	altura = alturaInicial;
	esperaI = 10.0f;
	esperaV = 10.f;

	int larguraSprite = sprite->Width() / 2;
	int alturaSprite = sprite->Height() / 2;

	BBox(new Rect(larguraSprite * -1, alturaSprite * -1, larguraSprite, alturaSprite));

	positionInitialX = -10000.0f;
	positionInitialY = 10000.0f;

	MoveTo(positionInitialX, positionInitialY);
}

Inimigo::~Inimigo()
{
	delete sprite;
}

void Inimigo::Update()
{
	EntraInimigo();
	MovimentaInimigo();
	ParaAtiraVolta();
}

void Inimigo::Draw()
{
	sprite->Draw(x, y, Layer::MIDDLE);
}

void Inimigo::OnCollision(Object* obj)
{
		
	if (vida > 0 && obj->Type() == TIROJOGADOR)
	{
		if (imune == false) {
			vida--;
		}
			
	}
	if (vida == 0) {
		MoveTo(positionInitialX, positionInitialY);
		vida = 10;
		imune = true;
	}
}



void Inimigo::EntraInimigo()
{
	if (x == positionInitialX) {
		MoveTo(window->Width() / 2, -100);
		velY = 150.0f;
		velX = -150.0f;
	}

	if ((int)y < altura) {
		Translate(0, velY * gameTime);
		imune = true;
	}
	else
	{
		imune = false;
	}
}

void Inimigo::MovimentaInimigo()
{
	if ((int)y >= 100)
	{
		Translate(velX * gameTime, 0);
	}

	if (x - sprite->Width() / 2 < 155)
	{
		MoveTo(155 + sprite->Width() / 2, y);
		velX = velX * -1;
	}

	if (x + sprite->Width() / 2 > 805)
	{
		MoveTo(805 - sprite->Width() / 2, y);
		velX = velX * -1;
	}
}

void Inimigo::ParaAtiraVolta()
{
	if (esperaI < 1.0f) {
		velX = 0.0f;
		if (!atirol) {
			tiros->Atirar(x, y + sprite->Height() / 2, 350.0f);
			atirol = true;
		}
	}
	else
	{
		esperaI = esperaI - 5 * gameTime;
	}

	if (esperaI < 1.0f)
	{
		esperaV = esperaV - 5 * gameTime;
	}

	if (esperaV < 1.0f)
	{
		atirol = false;
		esperaI = 10.0f;
		esperaV = 5.0f;
		if (DecideDirecao() == 1)
		{
			velX = -150.0f;
		}
		else
		{
			velX = 150.0f;
		}
	}

}

int Inimigo::DecideDirecao()
{
	std::random_device rd;
	std::mt19937 mt(rd());

	int min = 1;
	int max = 2;

	std::uniform_int_distribution<int> dist(min, max);

	return dist(mt);
}