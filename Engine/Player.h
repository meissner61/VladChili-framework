#pragma once
#include "Graphics.h"
class Player
{

public:
	/*Player(float x, float y, Color color);*/
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	void Update();
	




//private:

	float speed = 20.0f;

	int x;
	int y;
	//Color color;

	static constexpr int width = 10;
	static constexpr int height = 10;


};