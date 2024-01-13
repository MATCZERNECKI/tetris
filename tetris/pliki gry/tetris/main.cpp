#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>
#include <vector>

double lastupdatetime = 0;

bool eventtriggered(double interval)
{
	double currenttime = GetTime();
	if (currenttime - lastupdatetime >= interval)
	{
		lastupdatetime = currenttime;
		return true;
	}
	return false;
}

int main()
{
	InitWindow(500, 620, "tetris");
	SetTargetFPS(60);

	Font font = LoadFontEx("font / tetris - 2 - bombliss - credits - font.ttf", 64, 0, 0);

	Game game = Game();

	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		if (eventtriggered(0.4))
		{
			game.movedown();
		}
		BeginDrawing();
		ClearBackground(DarkBlue);
		DrawTextEx(font, "Score", { 355, 15 }, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 365, 175 }, 38, 2, WHITE);
		if (game.gameover == true)
		{
			DrawTextEx(font, "Game Over", { 315, 450 }, 38, 2, WHITE);
		}
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightblue);
		char scoretext[20];
		sprintf_s(scoretext, sizeof(scoretext), "%d", game.score);
		Vector2 textsize = MeasureTextEx(font, scoretext, 38, 2);
		DrawTextEx(font, scoretext, { 320 + (170 - textsize.x)/2, 65}, 38, 2, WHITE);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightblue);
		game.Draw();

		EndDrawing();
	}

	CloseWindow();
}