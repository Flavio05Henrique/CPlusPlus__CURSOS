#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Tiros.h"
#include "Image.h"
#include "Jogador.h"



#ifndef _BREAKOUT_FASE1_H_
#define _BREAKOUT_FASE1_H_

class Fase1 : public Game
{
private:
	Image* imgBkg = nullptr;
	Sprite* backg1 = nullptr;
	Sprite* backg2 = nullptr;
	Sprite* gameOver = nullptr;
	Scene* scene = nullptr;
	Tiros* tiros = nullptr;
	Tiros* tirosInimigo = nullptr;
	Jogador* jogador = nullptr;
	float backgX;
	float backgY1;
	float backgY2;
	float backgVel;

	bool viewBBox = false;
	bool keyPress = false; 

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};


#endif
