#include "Goal.h"

Goal::Goal(Graphics& gfx, float x_in, float y_in)
{
	x = x_in;
	y = y_in;
	Draw( gfx,x,y);
}

void Goal::Draw(Graphics & gfx, float x, float y)
{
	gfx.DrawRect(int(x), int(y), int(width), int(height),c);
}

bool Goal::IsColliding(Player& player)
{
	const float right = x + width;
	const float bottom = y + height;

	const float player_right = player.GetX() + player.GetWidth();
	const float player_bottom = player.GetY() + player.GetHeight();

	if (x <= player_right && right >= player.GetX() && y <= player_bottom && bottom >= player.GetY())
	{
		//isEaten = true;
		return true;
	}
	else
		return false;
}

void Goal::DrawTest(Graphics & gfx)
{
	gfx.DrawRect(10, 10, int(width)*timesCaught, 10, Colors::Cyan);

	gfx.DrawRect(int(x), int(y), int(width), int(height), c);

}

void Goal::Update(float x_in, float y_in)
{
	x = x_in;
	y = y_in;

	timesCaught++;
}

