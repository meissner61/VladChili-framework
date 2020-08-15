/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
	//player1(10.0f,10.0f,c)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> xDist(0, 770);
	std::uniform_int_distribution<int> yDist(0, 570);


	enemy1.vx = 1;
	enemy1.vy = 1;
	enemy1.x = xDist(rng);
	enemy1.y = yDist(rng);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		player.x -= player.speed;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		player.x += player.speed;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		player.y -= player.speed;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		player.y += player.speed;
	}

	//if (wnd.mouse.LeftIsPressed())


	player.ClampToScreen();
	enemy1.Update();
	enemy1.IsColliding(player);

}

void Game::ComposeFrame()
{

	//Color c2(255, 255, 255);

	if (enemy1.isEaten == false)
	{
		enemy1.Draw(gfx);
	}



	player.Draw(gfx);
}
