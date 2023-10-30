/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Player do jogo Breakout
//
**********************************************************************************/

#include "Player.h"
#include "Breakout.h"

// ---------------------------------------------------------------------------------

Player::Player(Image * img)
{
	sprite = new Sprite(img);
	velX = 150.0f;

	x = window->Width() / 2 - sprite->Width() / 2;
	y = window->Height() - sprite->Height() * 1.4;
}

Player::~Player()
{
	delete sprite;
}

void Player::Update()
{
	if (window->KeyDown(VK_LEFT))
	{
		Translate(-velX * gameTime, 0);
	}

	if (window->KeyDown(VK_RIGHT))
	{
		Translate(velX * gameTime, 0);
	}

	if (x < 0)
		MoveTo(0, y);

	if (x + sprite->Width() > window->Width())
		x - sprite->Width();
}

void Player::Draw()
{
	sprite->Draw(x, y, z);
}

float Player::PlayerWidth()
{
	return sprite->Width();
}


// ---------------------------------------------------------------------------------
