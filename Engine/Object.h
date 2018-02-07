#pragma once
#include"Rect.h"
#include"Graphics.h"
#include<string>
class Object
{
public:
	enum class Type
	{
		Hero,
		Obstacle,
		Enemy
	};
private:
	RectI rect;
	Type type;
	Vec2 position;
	Color c;
public:
	Object(RectI r, Type t, Vec2 pos);
	Object(const Object& o) = default;
	void Draw(Graphics& gfx);
	std::string ToString();
	Type GetType();
	void SetPosition(Vec2 pos);
	int GetWidth()const;
	int GetHeight()const;
	RectI GetRect()const;
};