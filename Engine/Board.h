#pragma once
#include"Object.h"
#include<vector>
#include<fstream>
class Board
{
private:
	Vec2 position;
	std::vector<Object*>board;
	int width;
	int height;
	int sample;
public:
	Board(int w, int h,int s, Vec2 pos);
	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;
	void  Add(const Object& o, Vec2 pos);
	void Delete(Vec2 pos);
	Rect<float> GetRect()const;
	void Draw(Graphics& gfx);
	void SaveToFile(std::string& name, Object::Type t);
	~Board();
};