#include "Types.h"
#include "Object.h"
#include "Sprite.h"
#include "Tiros.h"

#ifndef _BREAKOUT_INIMIGO_H_
#define _BREAKOUT_INIMIGO_H_

class Inimigo : public Object
{
private:
	Sprite* sprite = nullptr;
	Tiros* tiros = nullptr;
	float velX;
	float velY;
	float positionInitialX;
	float positionInitialY;
	bool imune;
	float esperaI;
	float esperaV;
	uint vida;

public:
	Inimigo(Tiros*);
	~Inimigo();

	int spriteW();
	int spriteH();

	void Update();
	void Draw();
	void OnCollision(Object*);
};

inline int Inimigo::spriteW()
{
	return sprite->Width();
};

inline int Inimigo::spriteH()
{
	return sprite->Height();
};
#endif // !_BREAKOUT_INIMIGO_H_

