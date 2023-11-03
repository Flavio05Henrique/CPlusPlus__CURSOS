#include "Inimigo.h"
#include "ObjectTypes.h"
#include <string>

Inimigo::Inimigo(Tiros* Tiros)
{
	sprite = new Sprite("Resources/NaveInimiga.png");
	tiros = Tiros;

	type = INIMIGO;

	velX = 250.0f;
	vida = 10;
	esperaI = 4.0f;
	esperaV = 2.0f;

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
	if (x == positionInitialX) {
		MoveTo(window->Width() / 2, -100);
		velY = 150.0f;
		velX = -150.0f;
	}

	if ((int)y < 100) {
		Translate(0, velY * gameTime);
		imune = true;
	} else
	{
		imune = false;
	}

	if ((int)y == 100)
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
	
	if (esperaI < 1.0f) {
		velX = 0.0f;
		tiros->Atirar(x, y + sprite->Height() / 2, 350.0f);
	}
	else 
	{
		esperaI = esperaI - gameTime;
	}

	if (esperaI < 1.0f)
	{
		esperaV = esperaV - gameTime;
	} 
	
	if (esperaV < 1.0f)
	{
		velX = -150.0;
		esperaI = 10.0f;
		esperaV = 5.0f;
	}

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