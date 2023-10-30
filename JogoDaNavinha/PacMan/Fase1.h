#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Tiros.h"

class Fase1 : public Game
{
private:
	Sprite * backg = nullptr;
	Scene* scene = nullptr;
	Tiros* tiros = nullptr;

	bool viewBBox = false;
	bool keyPress = false; 

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

