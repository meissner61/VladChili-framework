#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"
#include "Mouse.h"
class Player
{

public:
	/*Player(float x, float y, Color color);*/
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	void Update(const Keyboard& kbd,float dt);
	void MouseMove(const Mouse& mouse, float dt);
	Vec2 GetPosition()const;
	float GetWidth() const;
	float GetHeight()const;
	bool isEaten = false;




private:

	float speed = 5.0f*60.0f;
	Vec2 moveVector;
	Vec2 position = Vec2(200.0f, 200.0f);
	//Color color;

	static constexpr float width = 20.0f;
	static constexpr float height = 20.0f;


};