#include "game.h"
#include <random>

Game::Game()
{
	grid = Grid();
	blocks = getallblocks();
	currentblock = getrandomblock();
	nextblock = getrandomblock();
	gameover = false;
	score = 0;
}

Block Game::getrandomblock()
{
	if (blocks.empty())
	{
		blocks = getallblocks();
	}
	srand(time(NULL));
	int randomindex = rand() % blocks.size();
	Block block = blocks[randomindex];
	blocks.erase(blocks.begin() + randomindex);
	return block;
}

std::vector<Block> Game::getallblocks()
{
	return { iblock(), jblock(), lblock(), oblock(), sblock(), tblock(), zblock() };
}

void Game::Draw()
{
	grid.Draw();
	currentblock.Draw(11, 11);
	switch(nextblock.id)
	{
	case 3:
		nextblock.Draw(255, 290);
		break;
	case 4:
		nextblock.Draw(255, 280);
		break;
	default:
		nextblock.Draw(270, 270);
		break;
	}
}

void Game::HandleInput()
{
	int keypressed = GetKeyPressed();
	if (gameover && keypressed != 0)
	{
		gameover = false;
		resetgame();
	}
	switch (keypressed)
	{
	case KEY_LEFT:
		moveleft();
		break;

	case KEY_RIGHT:
		moveright();
		break;

	case KEY_DOWN:
		movedown();
		updatescore(0, 1);
		break;

	case KEY_UP:
		rotateblock();
	}
}

void Game::moveleft()
{
	if (!gameover)
	{
		currentblock.Move(0, -1);
		if (isblockoutside() || blockfits() == false)
		{
			currentblock.Move(0, 1);
		}
	}
}

void Game::moveright()
{
	if (!gameover)
	{
		currentblock.Move(0, 1);
		if (isblockoutside() || blockfits() == false)
		{
			currentblock.Move(0, -1);
		}
	}
}

void Game::movedown() 
{
	if (!gameover)
	{
		currentblock.Move(1, 0);
		if (isblockoutside() || blockfits() == false)
		{
			currentblock.Move(-1, 0);
			lockblock();
		}
	}
}

bool Game::isblockoutside()
{
	std::vector<Position> tiles = currentblock.getcellpositions();
	for (Position item : tiles)
	{
		if (grid.iscelloutside(item.row, item.column))
		{
			return true;
		}
	}
	return false;
}

void Game::rotateblock()
{
	if (!gameover)
	{
		currentblock.Rotate();
		if (isblockoutside())
		{
			currentblock.UndoRotation();
		}
	}
}

void Game::lockblock()
{
	std::vector<Position> tiles = currentblock.getcellpositions();
	for (Position item : tiles)
	{
		grid.grid[item.row][item.column] = currentblock.id;
	}
	currentblock = nextblock;
	if (blockfits() == false)
	{
		gameover = true;
	}
	nextblock = getrandomblock();
	int rowscleared = grid.clearfullrows();
	updatescore(rowscleared, 0);
}

bool Game::blockfits()
{
	std::vector<Position> tiles = currentblock.getcellpositions();
	for (Position item : tiles)
	{
		if (grid.iscellempty(item.row, item.column) == false)
		{
			return false;
		}
	}
	return true;
}

void Game::resetgame()
{
	grid.Initialize();
	blocks = getallblocks();
	currentblock = getrandomblock();
	nextblock = getrandomblock();
	score = 0;
}

void Game::updatescore(int linescleared, int movedownpoints)
{
	switch (linescleared)
	{
	case 1:
		score += 100;
		break;

	case 2:
		score += 300;
		break;

	case 3:
		score += 500;
		break;

	default:
		break;
	}

	score += movedownpoints;
}
