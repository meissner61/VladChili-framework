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

void Player::Draw(Graphics & gfx, Color color) const
{
	gfx.DrawRect(x, y, width, height, color);
}

void Player::Update()
{


}
