#pragma once
#include "Graphics.h"
#include "Player.h"
#include "Vec2.h"
class Goal
{

public:
	Goal(Graphics& gfx, const Vec2& position_in);
	void Draw(Graphics & gfx, float x, float y);
	bool IsColliding(Player& player);
	void DrawTest(Graphics& gfx);
	void Update(Vec2& pos_in);
	//void UpdateColor();

private:


	Vec2 position;
	bool pickedUp = false;
	int timesCaught = 0;
	Color c{ 255, 255, 255 };
	bool coloInreaseing = false;

public:
	static constexpr float width = 20;
	static constexpr float height = 20;
};