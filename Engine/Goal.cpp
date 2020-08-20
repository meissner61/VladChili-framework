#include "Goal.h"

Goal::Goal(Graphics& gfx, const Vec2& pos_in)
{
	position = pos_in;
	Draw( gfx,position.x, position.y);
}

void Goal::Draw(Graphics & gfx, float x, float y)
{
	gfx.DrawRect(int(position.x), int(position.y), int(width), int(height),c);
}

bool Goal::IsColliding(Player& player)
{
	const float right = position.x + width;
	const float bottom = position.y + height;

	const float player_right = player.GetPosition().x + player.GetWidth();
	const float player_bottom = player.GetPosition().y + player.GetHeight();

	if (position.x <= player_right && right >= player.GetPosition().x && position.y <= player_bottom && bottom >= player.GetPosition().y)
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

	gfx.DrawRect(int(position.x), int(position.y), int(width), int(height), c);

}

void Goal::Update(Vec2& pos_in)
{
	position = pos_in;

	timesCaught++;
}

