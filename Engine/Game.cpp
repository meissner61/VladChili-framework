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
	gfx( wnd ),
	rng( rd() ),
	xDist(0, Graphics::ScreenWidth - Enemy::width),
	yDist(0, Graphics::ScreenHeight - Enemy::height),
	vDist(-1, 1),
	goal( gfx, xDist(rng), yDist(rng))
	//player1(10.0f,10.0f,c)
{
	//enemy1.Init(200, 300, 1, 1);

	for (int i = 0; i < nEnemy; i++)
	{
		enemies[i].Init(xDist(rng), yDist(rng), vDist(rng), vDist(rng));
	}
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
	//if (wnd.mouse.LeftIsPressed())


	//Clamp to screen needs to be called after Update
	player.Update(wnd.kbd);
	player.ClampToScreen();

	for (int i = 0; i < nEnemy; i++)
	{
		enemies[i].Update();
		
		if (enemies[i].IsColliding(player))
		{
			player.isEaten = true;
		}

	}
	
	if (goal.IsColliding(player))
	{
		goal.Update(xDist(rng),yDist(rng));
	}

	//goal.UpdateColor();
	

}

void Game::ComposeFrame()
{

	//Color c2(255, 255, 255);



	for (int i = 0; i < nEnemy; i++)
	{

		enemies[i].Draw(gfx);
		
	}
	//if (!enemy1.IsEaten())
	//{
	//	enemy1.Draw(gfx);
	//}
	
	if (!player.isEaten)
	{
		player.Draw(gfx);
	}

	//goal.Draw(gfx, xDist(rng), yDist(rng)); //just looks funny because it goes nuts!
	goal.DrawTest(gfx);
}
