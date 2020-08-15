#pragma once
#include "Graphics.h"
#include "Player.h"
class Goal
{

public:
	Goal(Graphics& gfx, int x, int y);
	void Draw(Graphics & gfx, int x, int y);
	bool IsColliding(Player& player);
	void DrawTest(Graphics& gfx);
	void Update(int x_in, int y_in);

private:


	int x;
	int y;
	bool pickedUp = false;
	int timesCaught = 0;

public:
	static constexpr int width = 20;
	static constexpr int height = 20;
};