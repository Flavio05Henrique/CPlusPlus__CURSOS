#include "Engine.h"
#include "Fase1.h"
#include "Jogador.h"
#include <array>

void Fase1::Init()
{
	scene = new Scene();
	tiros = new Tiros(scene);

	Jogador* jogador = new Jogador(tiros);
	scene->Add(jogador, MOVING);

}

void Fase1::Update()
{
	if (!keyPress && window->KeyDown('B'))
	{
		viewBBox = !viewBBox;
		keyPress = true;
	}
	else if (window->KeyUp('B'))
	{
		keyPress = false;
	}

	scene->Update();
}

void Fase1::Draw() 
{
	scene->Draw();
	if(viewBBox) 
	{
		scene->DrawBBox();
	}
}

void Fase1::Finalize()
{
	delete scene;
	delete tiros;
}

 