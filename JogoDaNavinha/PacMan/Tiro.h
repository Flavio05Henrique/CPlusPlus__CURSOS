#include "Types.h"
#include "Object.h"
#include "Sprite.h"


#ifndef _BREAKOUT_TIRO_H_
#define _BREAKOUT_TIRO_H_

class Tiro : public Object
{
private:
	Sprite * sprite = nullptr;
	float positionInitialX;
	float positionInitialY;
	float velY;

public:
	Tiro(Image*, int);
	~Tiro();

	void Update();
	void Draw();
	void OnCollision(Object*);
	void Fogo(float, float, float);
};

#endif