#pragma once
#include <vector>
#include <raylib.h>

class Grid {
public:
	Grid();
	void Initialize();
	void Print();
	void Draw();
	bool iscelloutside(int row, int column);
	bool iscellempty(int row, int column);
	int clearfullrows();
	int grid[20][10];

private:
	bool isrowfull(int row);
	void clearrow(int row);
	void moverowdown(int row, int numrows);
	int NumRows;
	int NumCols;
	int CellSize;
	std::vector<Color> colors;
};