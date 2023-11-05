#include "HomeJDN.h"
#include "Fase1.h"
#include "Engine.h"

void HomeJDN::Init()
{
	bkg = new Sprite("Resources/InicioDoJogoDaNaVinha.png");
}

void HomeJDN::Finalize()
{
	delete bkg;
}

void HomeJDN::Update()
{
	if (window->KeyDown(VK_RETURN) && !keyPress)
	{
		keyPress = true;
		Engine::Next<Fase1>();
	}
}

void HomeJDN::Draw()
{
	bkg->Draw(window->CenterX(), window->CenterY(), Layer::MIDDLE);
}