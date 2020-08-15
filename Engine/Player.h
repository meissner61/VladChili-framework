#pragma once
#include "Graphics.h"
#include "Keyboard.h"
class Player
{

public:
	/*Player(float x, float y, Color color);*/
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd);
	int GetX();
	int GetY();
	static int GetWidth();
	static int GetHeight();
	bool isEaten = false;




private:

	float speed = 10.0f;

	int x = 0;
	int y = 0;
	//Color color;

	static constexpr int width = 20;
	static constexpr int height = 20;


};