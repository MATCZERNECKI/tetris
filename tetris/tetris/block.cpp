#include "block.h"

Block::Block()
{
	cellsize = 30;
	rotationstate = 0;
	colors = GetCellColors();
	rowoffset = 0;
	columnoffset = 0;
}

void Block::Draw()
{
	std::vector<Position> tiles = getcellpositions();
	for (Position item : tiles)
	{
		DrawRectangle(item.column * cellsize + 1, item.row *cellsize + 1, cellsize - 1, cellsize - 1, colors[id]);
	}
}

void Block::Move(int rows, int columns)
{
	rowoffset += rows;
	columnoffset += columns;
}

std::vector<Position> Block::getcellpositions()
{
	std::vector<Position> tiles = cells[rotationstate];
	std::vector<Position> movedtiles;
	for (Position item : tiles)
	{
		Position newpos = Position(item.row + rowoffset, item.column + columnoffset);
		movedtiles.push_back(newpos);
	}
	return movedtiles;
};