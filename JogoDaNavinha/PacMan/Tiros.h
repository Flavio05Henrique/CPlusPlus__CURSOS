#include "Tiro.h"
#include "Image.h"
#include <array>
#include "Scene.h"


#ifndef _BREAKOUT_TIROS_H_
#define _BREAKOUT_TIROS_H_

class Tiros
{
private:
	Image* img = nullptr;
	Scene* scene;
	std::array<Tiro*, 20> tirosList;
	int indexTiro;

public:
	Tiros(Scene*);
	~Tiros();

	void Atirar();
};

#endif