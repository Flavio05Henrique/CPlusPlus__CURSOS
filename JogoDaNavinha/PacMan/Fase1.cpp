#include "Engine.h"
#include "Fase1.h"
#include "Jogador.h"
#include "Inimigo.h";
#include "Image.h"
#include "ObjectTypes.h"

void Fase1::Init()
{
	scene = new Scene();
	tiros = new Tiros(scene, new Image("Resources/foguete.png"),TIROJOGADOR);
	tirosInimigo = new Tiros(scene, new Image("Resources/TiroNaveAlien.png"), TIROINIMIGO);

	imgBkg = new Image("Resources/Espaco.jpg");

	backg1 = new Sprite(imgBkg);
	backg2 = new Sprite(imgBkg);

	backgVel = 150.0f;
	backgX = window->Width() / 2;
	backgY1 = window->Height() - backg1->Height() / 2;
	backgY2 = backgY1 - backg1->Height();

	Jogador* jogador = new Jogador(tiros);
	scene->Add(jogador, MOVING);

	Inimigo* inimigo = new Inimigo(tirosInimigo);
	scene->Add(inimigo, MOVING);

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
	scene->CollisionDetection();

	if (backgY1 - backg1->Height() / 2 > window->Height())
		backgY1 = backgY2 - backg2->Height();
	if (backgY2 - backg2->Height() / 2 > window->Height())
		backgY2 = backgY1 - backg2->Height();

	backgY1 += backgVel * gameTime;
	backgY2 += backgVel * gameTime;
}

void Fase1::Draw() 
{
	backg1->Draw(backgX, backgY1, Layer::BACK);
	backg2->Draw(backgX, backgY2, Layer::BACK);
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
	delete imgBkg;
}

 