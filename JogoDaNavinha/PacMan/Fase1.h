#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Tiros.h"
#include "Image.h"

class Fase1 : public Game
{
private:
	Image* imgBkg = nullptr;
	Sprite* backg1 = nullptr;
	Sprite* backg2 = nullptr;
	Scene* scene = nullptr;
	Tiros* tiros = nullptr;
	Tiros* tirosInimigo = nullptr;
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

