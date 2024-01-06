#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main()
{
	Color DarkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "tetris");

	SetTargetFPS(60);

	Grid grid = Grid();
	grid.Print();

	iblock block = iblock();

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(DarkBlue);
		grid.Draw();
		block.Draw();

		EndDrawing();
	}

	CloseWindow();
}