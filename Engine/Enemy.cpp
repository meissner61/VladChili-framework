#include "Enemy.h"

//Enemy::Enemy(int x_in, int y_in, int vx_in, int vy_in)
//{
//	x = x_in;
//	y = y_in;
//	vx = vx_in;
//	vy = vy_in;
//}

void Enemy::Init(float x_in, float y_in, float vx_in, float vy_in)
{
	x = x_in;
	y = y_in;
	vx = vx_in;
	vy = vy_in;
}

void Enemy::Draw(Graphics & gfx) const
{
	gfx.DrawRect(int(x), int(y), int(width), int(height), Colors::Red);
}

void Enemy::Update(float dt)
{
	x += (vx * speed)*dt;
	y += (vy * speed)*dt;

	if (x <= 0)
	{
		x = 0;
		vx *= (-1);
	}

	else if (x + width >= float(Graphics::ScreenWidth))
	{
		x = float(Graphics::ScreenWidth) - width;
		vx *= (-1);
	}

	if (y <= 0)
	{
		y = 0;
		vy *= (-1);
	}

	else if (y + height >= float(Graphics::ScreenHeight))
	{
		y = float(Graphics::ScreenHeight) - height; 
		vy *= (-1);
	}
}

bool Enemy::IsColliding(Player & player)const 
{
	const float right = x + width;
	const float bottom = y + height;

	const float player_right = player.GetX() + player.GetWidth();
	const float player_bottom = player.GetY() + player.GetHeight();

	return (x <= player_right && right >= player.GetX() && y <= player_bottom && bottom >= player.GetY());

	

}

bool Enemy::IsEaten() const
{
	return isEaten;
}


