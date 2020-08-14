#pragma once
#include "Graphics.h"
class Player
{

public:
	/*Player(float x, float y, Color color);*/
	void ClampToScreen();
	void Draw(Graphics& gfx, Color color);
	void Update();
	




//private:

	float speed = 20.0f;

	float x;
	float y;
	Color color;

	static constexpr int width = 24;
	static constexpr int height = 24;


};