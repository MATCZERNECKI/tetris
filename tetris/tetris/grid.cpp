#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
	NumRows = 20;
	NumCols = 10;
	CellSize = 30;
	Initialize();
	colors = GetCellColors();
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