#pragma once
#include "Graphics.h"
#include "Player.h"

class Enemy
{
public:

	void Draw(Graphics& gfx) const;
	void Update();
	void IsColliding(Player& player);

//private:

	float speed = 5.0f;
	int x;
	int y;
	int vx;
	int vy;

	bool isEaten = false;

	//Color color;

	static constexpr int width = 20;
	static constexpr int height = 20;

};