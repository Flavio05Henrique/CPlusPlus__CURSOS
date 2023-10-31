#include "Tiro.h"

Tiro::Tiro(Image* img)
{
	sprite = new Sprite(img);

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

	if (y < -150) {
		velY = 0.0f;
		MoveTo(positionInitialX, positionInitialY);
	}
}

void Tiro::Draw()
{
	sprite->Draw(x, y, Layer::LOWER);
}

void Tiro::OnCollision()
{

}

void Tiro::Fogo(float posicaoJogadorX, float posicaoJogadorY)
{
	MoveTo(posicaoJogadorX, posicaoJogadorY);
	velY = -350.0f;
}



