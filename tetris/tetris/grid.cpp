#include "grid.h"
#include <iostream>

Grid::Grid()
{
	NumRows = 20;
	NumCols = 10;
	CellSize = 30;
	Initialize();
	colors = GetCellsColors();
}

void Grid::Initialize()
{
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++)
		{
			grid[row][column] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++) 
		{
			std::cout << grid[row][column] << " ";
		}
		std::cout << std::endl;
	}
}

std::vector<Color> Grid::GetCellsColors()
{
	Color DarkGrey = { 26, 31, 40, 255 };
	Color green = { 47, 230, 23, 255 };
	Color red = { 232, 18, 18, 255 };
	Color orange = { 226, 116, 17, 255 };
	Color yellow = { 237, 234, 4, 255 };
	Color purple = { 166, 0, 247, 255 };
	Color cyan = { 21, 204, 209, 255 };
	Color blue = { 13, 64, 216, 255 };

	return { DarkGrey, green, red, orange, yellow, purple, cyan, blue };
}

void Grid::Draw()
{
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++)
		{
			int cellValue = grid[row][column];
			DrawRectangle(column * CellSize+1, row * CellSize+1, CellSize-1, CellSize-1, colors[cellValue]);
		}
	}
}