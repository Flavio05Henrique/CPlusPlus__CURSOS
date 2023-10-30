#include "Types.h"
#include "Object.h"
#include "Sprite.h"
#include "Tiros.h"

#ifndef _BREAKOUT_JOGADOR_H_
#define _BREAKOUT_jOGADOR_H_

class Jogador : public Object
{
private:
	Sprite* sprite = nullptr;
	Tiros* tirosp = nullptr;
	float velX;
	bool keyPress = false;

public:
	Jogador(Tiros*);
	~Jogador();

	void Update();
	void Draw();
	void OnCollision();
};

#endif

