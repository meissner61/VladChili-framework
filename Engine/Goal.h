#pragma once
#include "Graphics.h"
#include "Player.h"
class Goal
{

public:
	Goal(Graphics& gfx, float x, float y);
	void Draw(Graphics & gfx, float x, float y);
	bool IsColliding(Player& player);
	void DrawTest(Graphics& gfx);
	void Update(float x_in, float y_in);
	//void UpdateColor();

private:


	float x;
	float y;
	bool pickedUp = false;
	int timesCaught = 0;
	Color c{ 255, 255, 255 };
	bool coloInreaseing = false;

public:
	static constexpr float width = 20;
	static constexpr float height = 20;
};