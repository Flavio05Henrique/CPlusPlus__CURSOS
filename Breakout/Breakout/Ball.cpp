/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bola do jogo Breakout
//
**********************************************************************************/

#include "Ball.h"

// ---------------------------------------------------------------------------------

Ball::Ball(float playerX, float playerWidth, float playerY, float playerHeigth)
{
	sprite = new Sprite("Resources/Ball.png");
	
	velX = 100.0f;
	velY = 100.0f;

	x = playerX + playerWidth / 2;
	y = playerY - sprite->Height() * 1.5;
}

Ball::~Ball()
{
	delete sprite;
}

void Ball::Update()
{
	
}

void Ball::Draw()
{
	sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------
