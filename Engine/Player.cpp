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

	else if (x+width >= Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - width;
	}

	if (y <= 0)
	{
		y = 0;
	}

	else if (y + height >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - height;
	}

}

void Player::Draw(Graphics & gfx) const
{
	gfx.DrawRect(x, y, width, height, Colors::Green);
}

void Player::Update(const Keyboard& kbd)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		x -= speed;
	}

	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		x += speed;
	}

	if (kbd.KeyIsPressed(VK_UP))
	{
		y -= speed;
	}

	if (kbd.KeyIsPressed(VK_DOWN))
	{
		y += speed;
	}

}

int Player::GetX()
{
	return x;
}

int Player::GetY()
{
	return y;
}

int Player::GetWidth()
{
	return width;
}

int Player::GetHeight()
{
	return height;
}
