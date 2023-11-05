#include "Game.h"
#include "Sprite.h"

#ifndef _BREAKOUT_HOME_JDN_H_
#define _BREAKOUT_HOME_JDN_H_

class HomeJDN : public Game
{
private:
	Sprite* bkg = nullptr;
	bool keyPress = false;
	
public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

#endif