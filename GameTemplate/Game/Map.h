#pragma once
#include "IGameObject.h"

class Map:public IGameObject
{
public:
	Map();
	~Map();
	void Update();
	void Draw();
};

