#include "Player.h"

//Player::Player(float x_in, float y_in, Color color_in)
//
//{	
//	x = x_in;
//	y = y_in;
//	color = color_in;
//
//
//
//}

void Player::ClampToScreen()
{
	if (position.x <= 0)
	{
		position.x = 0;
	}

	else if (position.x +width >= float(Graphics::ScreenWidth))
	{
		position.x = float(Graphics::ScreenWidth) - width;
	}

	if (position.y <= 0)
	{
		position.y = 0;
	}

	else if (position.y + height >= float(Graphics::ScreenHeight))
	{
		position.y = float(Graphics::ScreenHeight) - height;
	}

}

void Player::Draw(Graphics & gfx) const
{
	gfx.DrawRect(int(position.x), int(position.y), int(width), int(height), Colors::Green);
}

void Player::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		position.x -= speed * dt;
	}

	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		position.x += speed * dt;
	}

	if (kbd.KeyIsPressed(VK_UP))
	{
		position.y -= speed * dt;
	}

	if (kbd.KeyIsPressed(VK_DOWN))
	{
		position.y += speed * dt;
	}

}

void Player::MouseMove(const Mouse & mouse, float dt)
{
	Vec2 mousePos;
	

	if (mouse.LeftIsPressed())
	{
		mousePos = Vec2(mouse.GetPosX(), mouse.GetPosY());
		moveVector = mousePos - position;
		position += moveVector * dt * 2;
	}

	
}

Vec2 Player::GetPosition() const
{
	return position;
}



float Player::GetWidth()const
{
	return width;
}

float Player::GetHeight()const
{
	return height;
}
