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
#include<math.h>
#include"Object.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	menu(std::vector<Object>()),
	board(800, 600, 40, { 100,0 }),
	temp(nullptr)
{
	menu.Add(Object({ 0,0,30,30 }, Object::Type::Hero, { 0,0 }));
	menu.Add(Object({ 0,0,30,30 }, Object::Type::Enemy, { 0,0 }));
	menu.Add(Object({ 0,0,40,40 }, Object::Type::Obstacle, { 0,0 }));
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
	
	if (temp != nullptr)
	{
		if (wnd.mouse.LeftIsPressed())
		{
			Vec2 pos(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
			if (board.GetRect().IsInside(pos))
			{
				board.Add(*temp, pos);
			}
			else
			{
				temp = nullptr;
			}
		}
	}
	else
	{
		if (wnd.mouse.LeftIsPressed())
		{
			Vec2 pos(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
			temp = menu.ClickedOn(pos);
		}
	}
	if (wnd.mouse.RightIsPressed())
	{
		Vec2 pos(wnd.mouse.GetPosX(), wnd.mouse.GetPosY());
		if (board.GetRect().IsInside(pos))
		{
			board.Delete(pos);
		}
	}
}

void Game::ComposeFrame()
{
	menu.Draw(gfx);
	board.Draw(gfx);
}




