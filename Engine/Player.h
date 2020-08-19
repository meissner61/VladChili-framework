#pragma once
#include "Graphics.h"
#include "Keyboard.h"
class Player
{

public:
	/*Player(float x, float y, Color color);*/
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd,float dt);
	float GetX()const;
	float GetY()const;
	float GetWidth() const;
	float GetHeight()const;
	bool isEaten = false;




private:

	float speed = 5.0f*60.0f;

	float x = 0.0f;
	float y = 0.0f;
	//Color color;

	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;


};