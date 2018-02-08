#include "Object.h"

Object::Object(RectI  r, Type t, Vec2 pos)
	:
	rect(r),
	type(t),
	position(pos)
{
	switch(type)
	{
		case Type::Hero:
		{
			c = Colors::Red;
			break;
		}
		case Type::Enemy:
		{
			c = Colors::Blue;
			break;
		}
		case Type::Obstacle:
		{
			c = Colors::Gray;
			break;
		}
		default:
		{
			c = Colors::White;
			break;
		}
	}
}

void Object::Draw(Graphics & gfx)
{
	for (int i = 0; i < rect.GetWidth(); i++)
	{
		for (int j = 0; j < rect.GetHeight(); j++)
		{
			Vec2 pos = position;
			pos.x += i;
			pos.y += j;
			if (gfx.GetScreenRect().IsInside({ int(pos.x),int(pos.y) }))
			{
				gfx.PutPixel(pos.x, pos.y, c);
			}
		}
	}
}

std::string Object::ToString()
{
	std::string s = "(";
	s += std::to_string( int(position.x));
	s += ',';
	s += std::to_string(int(position.y));
	s += ')';
	return s;
}

Object::Type Object::GetType()
{
	return type;
}

void Object::SetPosition(Vec2 pos)
{
	position = pos;
}

int Object::GetWidth() const
{
	return rect.GetWidth();
}

int Object::GetHeight() const
{
	return rect.GetHeight();
}

RectI Object::GetRect() const
{
	return RectI(position.x,position.y,GetWidth(),GetHeight());
}
