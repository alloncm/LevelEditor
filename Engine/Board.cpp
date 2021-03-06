#include "Board.h"

Board::Board(int w, int h, int s, Vec2 pos)
	:
	position(pos),
	board((w/s)*(h/s)),
	width(w/s),
	height(h/s),
	sample(s)
{
	std::fill(board.begin(), board.end(), nullptr);
}

void Board::Add(const Object& o, Vec2 pos)
{
	Vec2 temp = pos;
	pos -= position;			//to make the board think he is on a normal screen with now menu
	pos.x /= sample;
	pos.y /= sample;
	Vec2_<int> n(pos.x, pos.y);
	board[n.y*width + n.x] = new Object(o);
	board[n.y*width + n.x]->SetPosition({float((n.x)*sample + position.x),float((n.y)*sample + position.y)});
}

void Board::Delete(Vec2 pos)
{
	pos -= position;			//to make the board think he is on a normal screen with now menu
	pos.x /= sample;
	pos.y /= sample;
	Vec2_<int> n(pos.x, pos.y);
	if (board[n.y*width + n.x] != nullptr)
	{
		delete board[n.y*width + n.x];
		board[n.y*width + n.x] = nullptr;
	}
}

Rect<float> Board::GetRect() const
{
	return Rect<float>(position.x,position.y,width*sample,height*sample);
}

void Board::Draw(Graphics & gfx)
{
	for (int i = 0; i < board.size(); i++)
	{
		if (board[i] != nullptr)
		{
			board[i]->Draw(gfx);
		}
	}
}

void Board::SaveToFile(std::string & name,Object::Type t)
{
	std::ofstream fout(name);
	fout.exceptions(std::ios::badbit | std::ios::failbit);

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i]!=nullptr&&board[i]->GetType() == t)
		{
			fout << board[i]->ToString() << '\n';
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < board.size(); i++)
	{
		delete board[i];
		board[i] = nullptr;
	}
}
