#include "Tiro.h"
#include "ObjectTypes.h"
#include "Inimigo.h"

Tiro::Tiro(Image* img, int tipo)
{
	sprite = new Sprite(img);

	type = tipo;

	velY = 0.0f;

	int larguraSprite = sprite->Width() / 2;
	int alturaSprite = sprite->Height() / 2;

	BBox(new Rect(larguraSprite * -1, alturaSprite * -1, larguraSprite, alturaSprite));

	positionInitialX = -10000.0f;
	positionInitialY = 10000.0f;

	MoveTo(positionInitialX, positionInitialY);
}

Tiro::~Tiro()
{
	delete sprite;
}

void Tiro::Update()
{
	Translate(0, velY * gameTime);

	if (y < -150 || y > window->Height()) {
		velY = 0.0f;
		MoveTo(positionInitialX, positionInitialY);
	}
}

void Tiro::Draw()
{
	sprite->Draw(x, y, Layer::LOWER);
}

void Tiro::OnCollision(Object* obj)
{
	if (obj->Type() == INIMIGO && type == TIROJOGADOR)
	{
		velY = 0.0f;
		MoveTo(positionInitialX, positionInitialY);
	}

	if (obj->Type() == JOGADOR && type == TIROINIMIGO)
	{
		velY = 0.0f;
		MoveTo(positionInitialX, positionInitialY);
	}
}

void Tiro::Fogo(float posicaoJogadorX, float posicaoJogadorY, float direcaoYDoTiro)
{
	MoveTo(posicaoJogadorX, posicaoJogadorY);
	velY = direcaoYDoTiro;
}



