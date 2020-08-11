#include "Tetromino.h"
#include "TETRIS.h"

// Functions that draw Tetrominoes

void BlockI1(int x, int y)
{
	// Print the block on the screen
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 3, y + 1); cout << char(178);

	CurrentState = 1;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 3][tetrominoLocY + 2] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] = colour;
	}
	else CanMoveDown = true;

	// Statement checks whether the tetromino could move left
	if (tetrominoLocX - 2 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	//Statement checks whether the tetromino could move right
	if (tetrominoLocX + 3 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	//Statement checks whether the tetromino could rotate (or switch state technically)
	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 3, tetrominoLocY + 2); cout << char(248);
}

void BlockI2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 1, y + 3); cout << char(178);

	CurrentState = 2;

	if (tetrominoLocY >= 18 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 4] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 3][tetrominoLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX + 1, tetrominoLocY - 1); cout << char(248);
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 4); cout << char(248);
}

void BlockJ1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 3;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 3] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockJ2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 4;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
}

void BlockJ3(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x, y); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 5;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockJ4(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 2, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);

	CurrentState = 6;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 1); cout << char(248);
}

void BlockL1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 7;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 3] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
}

void BlockL2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 8;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 3] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockL3(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 2, y); cout << char(178);

	CurrentState = 9;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
}

void BlockL4(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y); cout << char(178);

	CurrentState = 10;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 1] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX][tetrominoLocY] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//GotoXY(tetrominoLocX, tetrominoLocY + 1); cout << char(248);
}

void BlockO(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 0;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 3] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	CanRotate = true;

	// Print collision points
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockS1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 11;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 3] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//GotoXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
}

void BlockS2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 12;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 3] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockT1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);

	CurrentState = 13;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockT2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 14;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockT3(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 15;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockT4(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);

	CurrentState = 16;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
}

void BlockZ1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 17;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 3] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 3] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] = colour;
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	//GotoXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockZ2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 18;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 3] != 0)
	{
		NewTetromino = true;
		CanMoveDown = false;
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX + 1][tetrominoLocY] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 1] = colour;
		tetris[tetrominoLocX][tetrominoLocY + 2] = colour;
	}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	//GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	//GotoXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
}

void PrintTetromino()
{
	switch (CurrentState)
	{
	case 0: { BlockO(tetrominoLocX, tetrominoLocY); break; }
	case 1: { BlockI1(tetrominoLocX, tetrominoLocY); break; }
	case 2: { BlockI2(tetrominoLocX, tetrominoLocY); break; }
	case 3: { BlockJ1(tetrominoLocX, tetrominoLocY); break; }
	case 4: { BlockJ2(tetrominoLocX, tetrominoLocY); break; }
	case 5: { BlockJ3(tetrominoLocX, tetrominoLocY); break; }
	case 6: { BlockJ4(tetrominoLocX, tetrominoLocY); break; }
	case 7: { BlockL1(tetrominoLocX, tetrominoLocY); break; }
	case 8: { BlockL2(tetrominoLocX, tetrominoLocY); break; }
	case 9: { BlockL3(tetrominoLocX, tetrominoLocY); break; }
	case 10: { BlockL4(tetrominoLocX, tetrominoLocY); break; }
	case 11: { BlockS1(tetrominoLocX, tetrominoLocY); break; }
	case 12: { BlockS2(tetrominoLocX, tetrominoLocY); break; }
	case 13: { BlockT1(tetrominoLocX, tetrominoLocY); break; }
	case 14: { BlockT2(tetrominoLocX, tetrominoLocY); break; }
	case 15: { BlockT3(tetrominoLocX, tetrominoLocY); break; }
	case 16: { BlockT4(tetrominoLocX, tetrominoLocY); break; }
	case 17: { BlockZ1(tetrominoLocX, tetrominoLocY); break; }
	case 18: { BlockZ2(tetrominoLocX, tetrominoLocY); break; }
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