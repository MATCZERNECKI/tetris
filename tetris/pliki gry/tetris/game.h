#pragma once
#include "grid.h"
#include <vector>
#include "blocks.cpp"

class Game
{
public:
	Game();
	void Draw();
	void HandleInput();
	void movedown();
	bool gameover;
	int score;

private:
	Block getrandomblock();
	std::vector<Block> getallblocks();
	void moveleft();
	void moveright();
	bool isblockoutside();
	void rotateblock();
	void lockblock();
	bool blockfits();
	void resetgame();
	void updatescore(int linescleared, int movedownpoints);
	Grid grid;
	std::vector<Block> blocks;
	Block currentblock;
	Block nextblock;
};