#include "Enemy.h"

//Enemy::Enemy(int x_in, int y_in, int vx_in, int vy_in)
//{
//	x = x_in;
//	y = y_in;
//	vx = vx_in;
//	vy = vy_in;
//}

void Enemy::Init(const Vec2 position_in, const Vec2 velocity_in)
{
	position = position_in;
	velocity = velocity_in;
}

void Enemy::Draw(Graphics & gfx) const
{
	gfx.DrawRect(int(position.x), int(position.y), int(width), int(height), Colors::Red);
}

void Enemy::Update(float dt)
{
	position += (velocity*speed * dt);

	if (position.x <= 0)
	{
		position.x = 0;
		velocity *= (-1);
		//velocity.x = -velocity.x //another way
	}

	else if (position.x + width >= float(Graphics::ScreenWidth))
	{
		position.x = float(Graphics::ScreenWidth) - width;
		velocity.x *= (-1);
	}

	if (position.y <= 0)
	{
		position.y = 0;
		velocity.y *= (-1);
	}

	else if (position.y + height >= float(Graphics::ScreenHeight))
	{
		position.y = float(Graphics::ScreenHeight) - height;
		velocity.y *= (-1);
	}
}

bool Enemy::IsColliding(Player & player)const 
{
	const float right = position.x + width;
	const float bottom = position.y + height;

	const float player_right = player.GetPosition().x + player.GetWidth();
	const float player_bottom = player.GetPosition().y + player.GetHeight();

	return (position.x <= player_right && right >= player.GetPosition().x && position.y <= player_bottom && bottom >= player.GetPosition().y);

	

}

bool Enemy::IsEaten() const
{
	return isEaten;
}


