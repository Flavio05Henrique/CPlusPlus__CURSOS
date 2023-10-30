#include "Jogador.h"

Jogador::Jogador(Tiros* tirosP)
{
	sprite = new Sprite("Resources/nave.png");
    tirosp = tirosP;

    velX = 250.0f;

    int larguraSprite = sprite->Width() / 2;
    int alturaSprite = sprite->Height() / 2;

	BBox(new Rect(larguraSprite *-1, alturaSprite *-1, larguraSprite, alturaSprite));

    float positionInitialX = window->Width() / 2;
    float positionInitialY = window->Height() - alturaSprite - 50;

	MoveTo(positionInitialX, positionInitialY);
}

Jogador::~Jogador()
{
	delete sprite;
}

void Jogador::Update()
{
    
    if (window->KeyDown(VK_LEFT))
    {
        Translate(-velX * gameTime, 0);
    }

    if (window->KeyDown(VK_RIGHT))
    {
        Translate(velX * gameTime, 0);
    }

    if (window->KeyDown(VK_UP))
    {   
        if(!keyPress)
            tirosp->Atirar();
        keyPress = true;
        return;
    }
    
    if (window->KeyUp(VK_LEFT) || window->KeyUp(VK_RIGHT) || window->KeyUp(VK_UP))
    {
        keyPress = false;
    }
    
}

void Jogador::Draw()
{
	sprite->Draw(x, y, Layer::MIDDLE);
}

void Jogador::OnCollision()
{

}

