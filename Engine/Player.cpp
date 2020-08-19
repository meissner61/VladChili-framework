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
	if (x <= 0)
	{
		x = 0;
	}

	else if (x+width >= float(Graphics::ScreenWidth))
	{
		x = float(Graphics::ScreenWidth) - width;
	}

	if (y <= 0)
	{
		y = 0;
	}

	else if (y + height >= float(Graphics::ScreenHeight))
	{
		y = float(Graphics::ScreenHeight) - height;
	}

}

void Player::Draw(Graphics & gfx) const
{
	gfx.DrawRect(int(x), int(y), int(width), int(height), Colors::Green);
}

void Player::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		x -= speed * dt;	
	}

	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		x += speed * dt;
	}

	if (kbd.KeyIsPressed(VK_UP))
	{
		y -= speed * dt;
	}

	if (kbd.KeyIsPressed(VK_DOWN))
	{
		y += speed * dt;
	}

}

float Player::GetX()const
{
	return x;
}

float Player::GetY()const
{
	return y;
}

float Player::GetWidth()const
{
	return width;
}

float Player::GetHeight()const
{
	return height;
}
