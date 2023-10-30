#include "Tiro.h"

Tiro::Tiro(float X, Image* img)
{
	sprite = new Sprite(img);

	velY = 0.0f;
	stop = true;

	int larguraSprite = sprite->Width() / 2;
	int alturaSprite = sprite->Height() / 2;

	BBox(new Rect(larguraSprite * -1, alturaSprite * -1, larguraSprite, alturaSprite));

	float positionInitialX = X * sprite->Width() + (10 * X) + 100;
	float positionInitialY = 500.0f;

	MoveTo(positionInitialX, positionInitialY);
}

Tiro::~Tiro()
{
	delete sprite;
}

void Tiro::Update()
{
	if (stop == false) {
		Translate(0, velY * gameTime);

		if (y < -150) {
			velY = 0.0f;
			MoveTo(window->Width() / 2, window->Height() * 0.85);
		}
	}
}

void Tiro::Draw()
{
	sprite->Draw(x, y, Layer::UPPER);
}

void Tiro::OnCollision()
{

}

void Tiro::Fogo()
{
	velY = -350.0f;
}

void Tiro::Stop()
{
	stop = false;
}

