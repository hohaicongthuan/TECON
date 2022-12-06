// TECON GAME (Tetris clone) BY THUAN HAI CONG HO & TRANG KIEU HA
// Well's size (Matrix size) 20 x 20
// 100% ASCII interface

#include "Teconny.h"
#include "TECON.h"

// Functions that draw Tetrominoes

void BlockI1(int x, int y)
{
	// Print the block on the screen
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 3, y + 1); cout << char(178);

	CurrentState = 1;

	if (teconnyLocY >= 20 ||
		tecon[teconnyLocX][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 1][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 3][teconnyLocY + 2] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 3][teconnyLocY + 1] = colour;
	}
	else CanMoveDown = true;

	// Statement checks whether the tetromino could move left
	if (teconnyLocX - 2 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	//Statement checks whether the tetromino could move right
	if (teconnyLocX + 3 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	//Statement checks whether the tetromino could rotate (or switch state technically)
	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY + 2] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY + 3] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 1, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 3, teconnyLocY + 2); cout << char(248);
}

void BlockI2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 1, y + 3); cout << char(178);

	CurrentState = 2;

	if (teconnyLocY >= 18 ||
		tecon[teconnyLocX + 1][teconnyLocY + 4] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 2] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 3] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 3][teconnyLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX + 1, teconnyLocY - 1); cout << char(248);
	//GotoXY(teconnyLocX + 1, teconnyLocY + 4); cout << char(248);
}

void BlockJ1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 3;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 1][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 3] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY + 2] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 1, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 3); cout << char(248);
}

void BlockJ2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 4;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX][teconnyLocY + 3] != 0 ||
		tecon[teconnyLocX + 1][teconnyLocY + 3] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 2] = colour;
		tecon[teconnyLocX][teconnyLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX][teconnyLocY] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX, teconnyLocY + 3); cout << char(248);
	//GotoXY(teconnyLocX + 1, teconnyLocY + 3); cout << char(248);
}

void BlockJ3(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x, y); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 5;

	if (teconnyLocY >= 20 ||
		tecon[teconnyLocX][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 1][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 2] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX][teconnyLocY + 1] = colour;
		tecon[teconnyLocX][teconnyLocY] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 1] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY + 2] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 1, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 2); cout << char(248);
}

void BlockJ4(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 2, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);

	CurrentState = 6;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX + 1][teconnyLocY + 3] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 1] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 2] = colour;
		tecon[teconnyLocX + 2][teconnyLocY] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX + 1, teconnyLocY + 3); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 1); cout << char(248);
}

void BlockL1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 7;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX + 1][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX][teconnyLocY + 3] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 1] = colour;
		tecon[teconnyLocX][teconnyLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY + 2] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX + 1, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX, teconnyLocY + 3); cout << char(248);
}

void BlockL2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 8;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX + 1][teconnyLocY + 3] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 3] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 2] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX + 1, teconnyLocY + 3); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 3); cout << char(248);
}

void BlockL3(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 2, y); cout << char(178);

	CurrentState = 9;

	if (teconnyLocY >= 20 ||
		tecon[teconnyLocX + 1][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX][teconnyLocY + 2] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 2][teconnyLocY] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY + 2] == 0 &&
		tecon[teconnyLocX][teconnyLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX + 1, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX, teconnyLocY + 2); cout << char(248);
}

void BlockL4(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y); cout << char(178);

	CurrentState = 10;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX + 1][teconnyLocY + 3] != 0 ||
		tecon[teconnyLocX][teconnyLocY + 1] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 2] = colour;
		tecon[teconnyLocX][teconnyLocY] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX + 1, teconnyLocY + 3); cout << char(248);
	//GotoXY(teconnyLocX, teconnyLocY + 1); cout << char(248);
}

void BlockO(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 0;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX + 1][teconnyLocY + 3] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 3] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 2] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	CanRotate = true;

	// Print collision points
	//GotoXY(teconnyLocX + 1, teconnyLocY + 3); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 3); cout << char(248);
}

void BlockS1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 11;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX + 2][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 1][teconnyLocY + 3] != 0 ||
		tecon[teconnyLocX][teconnyLocY + 3] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 2] = colour;
		tecon[teconnyLocX][teconnyLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX + 2, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 1, teconnyLocY + 3); cout << char(248);
	//GotoXY(teconnyLocX, teconnyLocY + 3); cout << char(248);
}

void BlockS2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 12;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX + 1][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 3] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY + 2] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX + 1, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 3); cout << char(248);
}

void BlockT1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);

	CurrentState = 13;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 1][teconnyLocY + 3] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 2] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY + 2] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 1, teconnyLocY + 3); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 2); cout << char(248);
}

void BlockT2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 14;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX + 1][teconnyLocY + 3] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 2] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 2] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 1] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX + 1, teconnyLocY + 3); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 2); cout << char(248);
}

void BlockT3(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 15;

	if (teconnyLocY >= 20 ||
		tecon[teconnyLocX][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 1][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 2] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY + 2] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 1, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 2); cout << char(248);
}

void BlockT4(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);

	CurrentState = 16;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX + 1][teconnyLocY + 3] != 0 ||
		tecon[teconnyLocX][teconnyLocY + 2] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 2] = colour;
		tecon[teconnyLocX][teconnyLocY + 1] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX + 1, teconnyLocY + 3); cout << char(248);
	//GotoXY(teconnyLocX, teconnyLocY + 2); cout << char(248);
}

void BlockZ1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 17;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX + 1][teconnyLocY + 3] != 0 ||
		tecon[teconnyLocX + 2][teconnyLocY + 3] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY + 2] = colour;
		tecon[teconnyLocX + 2][teconnyLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX + 1, teconnyLocY + 3); cout << char(248);
	//GotoXY(teconnyLocX + 2, teconnyLocY + 3); cout << char(248);
}

void BlockZ2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 18;

	if (teconnyLocY >= 19 ||
		tecon[teconnyLocX + 1][teconnyLocY + 2] != 0 ||
		tecon[teconnyLocX][teconnyLocY + 3] != 0)
	{
		NewTeconny = true;
		CanMoveDown = false;
		tecon[teconnyLocX + 1][teconnyLocY + 1] = colour;
		tecon[teconnyLocX + 1][teconnyLocY] = colour;
		tecon[teconnyLocX][teconnyLocY + 1] = colour;
		tecon[teconnyLocX][teconnyLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (teconnyLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (teconnyLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tecon[teconnyLocX + 1][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX][teconnyLocY + 1] == 0 &&
		tecon[teconnyLocX + 1][teconnyLocY + 2] == 0 &&
		tecon[teconnyLocX + 2][teconnyLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(teconnyLocX + 1, teconnyLocY + 2); cout << char(248);
	//GotoXY(teconnyLocX, teconnyLocY + 3); cout << char(248);
}

void PrintTeconny()
{
	switch (CurrentState)
	{
	case 0: { BlockO(teconnyLocX, teconnyLocY); break; }
	case 1: { BlockI1(teconnyLocX, teconnyLocY); break; }
	case 2: { BlockI2(teconnyLocX, teconnyLocY); break; }
	case 3: { BlockJ1(teconnyLocX, teconnyLocY); break; }
	case 4: { BlockJ2(teconnyLocX, teconnyLocY); break; }
	case 5: { BlockJ3(teconnyLocX, teconnyLocY); break; }
	case 6: { BlockJ4(teconnyLocX, teconnyLocY); break; }
	case 7: { BlockL1(teconnyLocX, teconnyLocY); break; }
	case 8: { BlockL2(teconnyLocX, teconnyLocY); break; }
	case 9: { BlockL3(teconnyLocX, teconnyLocY); break; }
	case 10: { BlockL4(teconnyLocX, teconnyLocY); break; }
	case 11: { BlockS1(teconnyLocX, teconnyLocY); break; }
	case 12: { BlockS2(teconnyLocX, teconnyLocY); break; }
	case 13: { BlockT1(teconnyLocX, teconnyLocY); break; }
	case 14: { BlockT2(teconnyLocX, teconnyLocY); break; }
	case 15: { BlockT3(teconnyLocX, teconnyLocY); break; }
	case 16: { BlockT4(teconnyLocX, teconnyLocY); break; }
	case 17: { BlockZ1(teconnyLocX, teconnyLocY); break; }
	case 18: { BlockZ2(teconnyLocX, teconnyLocY); break; }
	}
}

void PrintNextPiece(int x, int y)
{
	switch (NextPiece)
	{
	case 0:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x + 2, y + 1); cout << char(178);
		GotoXY(x + 1, y + 2); cout << char(178);
		GotoXY(x + 2, y + 2); cout << char(178);
		break;
	}
	case 1:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x, y + 1); cout << char(178);
		GotoXY(x + 2, y + 1); cout << char(178);
		GotoXY(x + 3, y + 1); cout << char(178);
		break;
	}
	case 2:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x + 1, y); cout << char(178);
		GotoXY(x + 1, y + 2); cout << char(178);
		GotoXY(x + 1, y + 3); cout << char(178);
		break;
	}
	case 3:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x, y + 1); cout << char(178);
		GotoXY(x + 2, y + 2); cout << char(178);
		GotoXY(x + 2, y + 1); cout << char(178);
		break;
	}
	case 4:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x + 1, y); cout << char(178);
		GotoXY(x + 1, y + 2); cout << char(178);
		GotoXY(x, y + 2); cout << char(178);
		break;
	}
	case 5:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x, y + 1); cout << char(178);
		GotoXY(x, y); cout << char(178);
		GotoXY(x + 2, y + 1); cout << char(178);
		break;
	}
	case 6:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x + 1, y); cout << char(178);
		GotoXY(x + 2, y); cout << char(178);
		GotoXY(x + 1, y + 2); cout << char(178);
		break;
	}
	case 7:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x, y + 1); cout << char(178);
		GotoXY(x + 2, y + 1); cout << char(178);
		GotoXY(x, y + 2); cout << char(178);
		break;
	}
	case 8:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x + 1, y); cout << char(178);
		GotoXY(x + 1, y + 2); cout << char(178);
		GotoXY(x + 2, y + 2); cout << char(178);
		break;
	}
	case 9:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x, y + 1); cout << char(178);
		GotoXY(x + 2, y + 1); cout << char(178);
		GotoXY(x + 2, y); cout << char(178);
		break;
	}
	case 10:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x + 1, y); cout << char(178);
		GotoXY(x + 1, y + 2); cout << char(178);
		GotoXY(x, y); cout << char(178);
		break;
	}
	case 11:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x + 2, y + 1); cout << char(178);
		GotoXY(x + 1, y + 2); cout << char(178);
		GotoXY(x, y + 2); cout << char(178);
		break;
	}
	case 12:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x + 1, y); cout << char(178);
		GotoXY(x + 2, y + 1); cout << char(178);
		GotoXY(x + 2, y + 2); cout << char(178);
		break;
	}
	case 13:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x, y + 1); cout << char(178);
		GotoXY(x + 2, y + 1); cout << char(178);
		GotoXY(x + 1, y + 2); cout << char(178);
		break;
	}
	case 14:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x + 1, y); cout << char(178);
		GotoXY(x + 1, y + 2); cout << char(178);
		GotoXY(x + 2, y + 1); cout << char(178);
		break;
	}
	case 15:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x, y + 1); cout << char(178);
		GotoXY(x + 1, y); cout << char(178);
		GotoXY(x + 2, y + 1); cout << char(178);
		break;
	}
	case 16:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x + 1, y); cout << char(178);
		GotoXY(x + 1, y + 2); cout << char(178);
		GotoXY(x, y + 1); cout << char(178);
		break;
	}
	case 17:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x, y + 1); cout << char(178);
		GotoXY(x + 1, y + 2); cout << char(178);
		GotoXY(x + 2, y + 2); cout << char(178);
		break;
	}
	case 18:
	{
		GotoXY(x + 1, y + 1); cout << char(178);
		GotoXY(x + 1, y); cout << char(178);
		GotoXY(x, y + 1); cout << char(178);
		GotoXY(x, y + 2); cout << char(178);
		break;
	}
	}
}