#include "Goal.h"

Goal::Goal(Graphics& gfx, int x_in, int y_in)
{
	x = x_in;
	y = y_in;
	Draw( gfx,x,y);
}

void Goal::Draw(Graphics & gfx, int x, int y)
{
	gfx.DrawRect(x, y, width, height,Colors::Blue);
}

bool Goal::IsColliding(Player& player)
{
	const int right = x + width;
	const int bottom = y + height;

	const int player_right = player.GetX() + player.GetWidth();
	const int player_bottom = player.GetY() + player.GetHeight();

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
	gfx.DrawRect(x, y, width, height, Colors::Blue);
}

void Goal::Update(int x_in, int y_in)
{
	x = x_in;
	y = y_in;
}
