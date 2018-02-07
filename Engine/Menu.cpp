#include "Menu.h"

Menu::Menu(std::vector<Object> o)
{
	Elements = o;
}

void Menu::Add(Object o)
{
	Elements.emplace_back(o);
}

void Menu::Draw(Graphics & gfx)
{
	int padding = 20;
	int x = 0;
	int y = 0;
	for (int i = 0; i < Elements.size(); i++)
	{
		Vec2 pos(x, i*Elements[i].GetHeight()+padding*(i+1));
		Elements[i].SetPosition(pos);
		Elements[i].Draw(gfx);
	}

	//line for the menu
	x = 100;
	for (int i = 0; i < gfx.ScreenHeight; i++)
	{
		gfx.PutPixel(x, i, Colors::Blue);
	}
}

int Menu::Size() const
{
	return Elements.size();
}

Object Menu::operator[](int i)
{
	assert(i < Elements.size());
	return Elements[i];
}

Object* Menu::ClickedOn(Vec2 pos)
{
	for (int i = 0; i < Elements.size(); i++)
	{
		if (Elements[i].GetRect().IsInside({int(pos.x),int(pos.y)}))
		{
			return &Elements[i];
		}
	}
	return nullptr;
}
