#include <raylib.h>
#include "grid.h"

int main()
{
	Color DarkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "tetris");

	SetTargetFPS(60);

	Grid grid = Grid();
	grid.Print();

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(DarkBlue);
		grid.Draw();

		EndDrawing();
	}

	CloseWindow();
}