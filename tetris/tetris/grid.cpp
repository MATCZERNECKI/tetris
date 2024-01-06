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
			DrawRectangle(column * CellSize+11, row * CellSize+11, CellSize-1, CellSize-1, colors[cellValue]);
		}
	}
}

bool Grid::iscelloutside(int row, int column)
{
	if (row >= 0 && row < NumRows && column >= 0 && column < NumCols)
	{
		return false;
	}
	return true;
}

bool Grid::iscellempty(int row, int column)
{
	if (grid[row][column] == 0)
	{
		return true;
	}
	return false;
}

int Grid::clearfullrows()
{
	int completed = 0;
	for (int row = NumRows - 1; row >= 0; row--)
	{
		if (isrowfull(row))
		{
			clearrow(row);
			completed++;
		}
		else if (completed > 0)
		{
			moverowdown(row, completed);
		}
	}
	return completed;
}

bool Grid::isrowfull(int row)
{
	for (int column = 0; column < NumCols; column++)
	{
		if (grid[row][column] == 0)
		{
			return false;
		}
	}
	return true;
}

void Grid::clearrow(int row)
{
	for (int column = 0; column < NumCols; column++)
	{
		grid[row][column] = 0;
	}
}

void Grid::moverowdown(int row, int numrows)
{
	for (int column = 0; column < NumCols; column++)
	{
		grid[row + numrows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}