#include "Jogador.h"
#include "ObjectTypes.h"

Jogador::Jogador(Tiros* tirosP)
{
	sprite = new Sprite("Resources/nave.png");
    tirosp = tirosP;

    type = JOGADOR;

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
        if (x - sprite->Width() / 2 < 155)
            MoveTo(155 + sprite->Width() / 2, y);
        Translate(-velX * gameTime, 0);
    }

    if (window->KeyDown(VK_RIGHT))
    {
        if (x + sprite->Width() / 2 > 805)
            MoveTo(805 - sprite->Width() / 2, y);
        Translate(velX * gameTime, 0);
    }

    if (window->KeyDown(VK_UP))
    {   
        if(!keyPress)
            tirosp->Atirar(x, y, -350.0f);
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

