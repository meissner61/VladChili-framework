#include "Enemy.h"

//Enemy::Enemy(int x_in, int y_in, int vx_in, int vy_in)
//{
//	x = x_in;
//	y = y_in;
//	vx = vx_in;
//	vy = vy_in;
//}

void Enemy::Init(int x_in, int y_in, int vx_in, int vy_in)
{
	x = x_in;
	y = y_in;
	vx = vx_in;
	vy = vy_in;
}

void Enemy::Draw(Graphics & gfx) const
{
	gfx.DrawRect(x, y, width, height, Colors::Red);
}

void Enemy::Update()
{
	x += vx * speed;
	y += vy * speed;

	if (x <= 0)
	{
		x = 0;
		vx *= (-1);
	}

	else if (x + width >= Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - width;
		vx *= (-1);
	}

	if (y <= 0)
	{
		y = 0;
		vy *= (-1);
	}

	else if (y + height >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - height; 
		vy *= (-1);
	}
}

bool Enemy::IsColliding(Player & player) 
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

bool Enemy::IsEaten() const
{
	return isEaten;
}


