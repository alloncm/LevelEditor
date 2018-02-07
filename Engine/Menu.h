#pragma once
#include"Object.h"
#include<vector>
#include<cassert>
class Menu
{
private:
	std::vector<Object> Elements;

public:
	Menu(std::vector<Object> o);
	void Add(Object o);
	void Draw(Graphics& gfx);
	int Size()const;
	Object operator[](int i);
	Object* ClickedOn(Vec2 pos);
};
