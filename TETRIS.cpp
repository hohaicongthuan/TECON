// TETRIS GAME BY CONG THUAN HO HAI & KIEU TRANG HA
// Well's size (Matrix size) 20 x 20
// 100% console interface

//============================================================

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

//============================================================

using namespace std;

//============================================================

int tetris[30][30]; // Khai báo mảng
char a[50][50];

int Score = 0, HighScore = 0,
	tetrominoLocX = 0, tetrominoLocY = 0, // Tetromino Location X & Y
	DelayTime = 1, count = 0,
	ASCIIValue;

unsigned short int	CurrentState = 0,
					NextPiece = 0;

// Quy ước các trạng thái của tetrominoes
// Vì "switch... case" không hỗ trợ dữ liệu chuỗi
// nên đành phải quy ước thành số nguyên

	// 'I1' = 1		'L4' = 10
	// 'I2' = 2		'S1' = 11
	// 'J1' = 3		'S2' = 12
	// 'J2' = 4		'T1' = 13
	// 'J3' = 5		'T2' = 14
	// 'J4' = 6		'T3' = 15
	// 'L1' = 7		'T4' = 16
	// 'L2' = 8		'Z1' = 17
	// 'L3' = 9		'Z2' = 18

char key; // Stores keys that user pressed

bool	NewTetromino = true,
		CanMoveRight = true,
		CanMoveLeft = true,
		CanMoveDown = true,
		CanRotate = true;
//============================================================

// Functions define
int Random(int n);
void GotoXY(int x, int y);
void NoCursorType();
void ArrayReset();
void PrintArray(int x, int y);
void ArrayDebug();
void DeleteRow(int n);
void MoveAllRowAbove(int n);
int CheckFullRow();
void PrintVariables();
void khung();
void BlockI1(int x, int y);
void BlockI2(int x, int y);
void BlockJ1(int x, int y);
void BlockJ2(int x, int y);
void BlockJ3(int x, int y);
void BlockJ4(int x, int y);
void BlockL1(int x, int y);
void BlockL2(int x, int y);
void BlockL3(int x, int y);
void BlockL4(int x, int y);
void BlockO(int x, int y);
void BlockS1(int x, int y);
void BlockS2(int x, int y);
void BlockT1(int x, int y);
void BlockT2(int x, int y);
void BlockT3(int x, int y);
void BlockT4(int x, int y);
void BlockZ1(int x, int y);
void BlockZ2(int x, int y);
void PrintTetromino();
void PrintNextPiece(int x, int y);
void Refresh();
void InputProcess();
void first_ui(int);
void second_ui(int);
void gameover(int);
void Colour(int n);

//=============================================================

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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 3][tetrominoLocY + 1] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 2] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 3] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 2] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 2] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 2] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 1] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 2] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 2] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 2] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 2] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 2] = 1;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 2] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 2] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 2] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 2] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 2] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 2] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 2] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 1] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 2] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 2] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY + 2] = 1;
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
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 2] = 1;
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
			case 0: { BlockO(tetrominoLocX, tetrominoLocY); break;}
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

//=============================================================

int Random(int n) // Generate a random number
{
	srand((int)time(0));
	int r = (rand() % n);
	return r;
}

void GotoXY(int x, int y) // Hàm di chuyển con trỏ console
{
	COORD p = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void NoCursorType() // Hàm ẩn con trỏ console
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void ArrayReset()
{
    for (int i = 0; i <= 30; i++)
        for (int j = 0; j <= 30; j++)
            tetris[j][i] = 0;

	for (int i = 0; i <= 21; i++)
	{
		tetris[i][22] = 1;
		tetris[21][i] = 1;
		tetris[0][i] = 1;
	}
}

void PrintArray(int x, int y) // In mảng bắt đầu từ vị trí có toạ độ (x, y)
{
    GotoXY(x, y);
    for (int i = 1; i <= 21; i++)
        {
            for (int j = 1; j <= 20; j++)
            {
                if (tetris[j][i] == 0) cout << " ";
                else if (tetris[j][i] == 1) cout << char(178);
            }
            cout << "\n";
            GotoXY(x, y++);
        }
}

void ArrayDebug() // Print the actual array storing information
{
	int t = 1;
	GotoXY(44, t);
	for (int i = 0; i <= 22; i++)
	{
		for (int j = 0; j < 22; j++) cout << tetris[j][i];
		GotoXY(44, t++);
	}
}

// Check full rows
// and delete full rows
// and return a value of deleted rows

void DeleteRow(int n)
{
    for (int i = 1; i <= 20; i++) tetris[i][n] = 0;
}

void MoveAllRowAbove(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 20; j >= 1; j--)
        {
            tetris[j][i] = tetris[j][i - 1];
        }
    }
}

int CheckFullRow() // Function that checks and returns a number of full rows
{
    int FullRow = 0;
	bool t = false;
    for (int i = 1; i <= 21; i++)
	{
		for (int j = 1; j <= 21; j++)
		{
			if (tetris[j][i] == 0) 
			{
				t = false;
				break;
			}
			t = true;
		}
		if (t)
		{
			FullRow++;
			DeleteRow(i);
			MoveAllRowAbove(i);
		}
	}
	return FullRow;
}

void PrintVariables()
{
	GotoXY(71, 1);
	cout << tetrominoLocX << " ";
	GotoXY(71, 2);
	cout << tetrominoLocY << " ";
	GotoXY(75, 3);
	if (CanMoveRight) cout << "True "; else cout << "False";
	GotoXY(75, 4);
	if (CanMoveLeft) cout << "True "; else cout << "False";
	GotoXY(75, 5);
	if (CanMoveDown) cout << "True "; else cout << "False";
	GotoXY(73, 6);
	if (CanRotate) cout << "True "; else cout << "False";
	GotoXY(75, 7);
	cout << CurrentState << " ";
}

void Refresh()
{
	PrintArray(1, 1);
	PrintTetromino();
				
	// Print out the key that user pressed
	GotoXY(0, 22);
	cout << "Key pressed: ";

	PrintVariables();
}

void InputProcess() // Function processing user's input
{
	if (ASCIIValue == 97) // Moves current tetromino to the left if the 'a' key is pressed
	{
		if (CanMoveLeft) tetrominoLocX--;
		Refresh();
	}
	if (ASCIIValue == 100) // Moves current tetromino to the right if the 'd' key is pressed
	{
		if (CanMoveRight) tetrominoLocX++;
		Refresh();
	}
	if (ASCIIValue == 115) // Moves current tetromino down if the 's' key is pressed
	{
		if (CanMoveDown) if (tetrominoLocY < 20) tetrominoLocY++;
		Refresh();
	}
	if (ASCIIValue == 119) // Change state of a tetromino when 'w' key is pressed
	{
		if (CanRotate)
			switch (CurrentState)
			{
				case 1: { CurrentState = 2; break; }
				case 2: { CurrentState = 1; break; }
				case 3: { CurrentState = 4; break; }
				case 4: { CurrentState = 5; break; }
				case 5: { CurrentState = 6; break; }
				case 6: { CurrentState = 3; break; }
				case 7: { CurrentState = 8; break; }
				case 8: { CurrentState = 9; break; }
				case 9: { CurrentState = 10; break; }
				case 10: { CurrentState = 7; break; }
				case 11: { CurrentState = 12; break; }
				case 12: { CurrentState = 11; break; }
				case 13: { CurrentState = 14; break; }
				case 14: { CurrentState = 15; break; }
				case 15: { CurrentState = 16; break; }
				case 16: { CurrentState = 13; break; }
				case 17: { CurrentState = 18; break; }
				case 18: { CurrentState = 17; break; }
			}
		Refresh();
	}		
}

void Colour(int n) // Function that changes console text colour
{
    // 1 is bright red		2 is bright green		3 is bright blue
	// 4 is bright pink		5 is bright yellow		6 is white
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (n)
    {
        case 1: { SetConsoleTextAttribute(hConsole, 12); break; }
        case 2: { SetConsoleTextAttribute(hConsole, 10); break; }
        case 3: { SetConsoleTextAttribute(hConsole, 9); break; }
        case 4: { SetConsoleTextAttribute(hConsole, 13); break; }
        case 5: { SetConsoleTextAttribute(hConsole, 14); break; }
        case 6: { SetConsoleTextAttribute(hConsole, 15); break; }
    }

}

//============================================================
//User Interface

void khung()
{
    // system("cls");
    // hàng đầu tiên
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(201);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(203);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(187) << endl;

    //hàng thứ 2 đến hàng thứ 19
    for(int j = 1; j <= 20; ++j)
    {
        cout << char(186);
        for(int i = 1; i <= 20; ++i)
            cout << " ";
        cout << char(186);
        for(int i = 1; i <= 20; ++i)
            cout << " ";
        cout << char(186) << endl;
    }

    //hàng cuối cùng
    cout << char(200);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(202);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(188) << endl;
}

//giao dien welcome
void first_ui(int)
{
    //hàng đầu tiên
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(201);
    for(int i = 1; i <= 41; ++i)
        cout << char(205);
    cout << char(187) << endl;

    //hàng thứ 1
    cout << char(186);
    for(int i = 1; i <= 40; ++i)
        cout << " ";
    cout << " " << char(186) << endl;

    //hang thứ 2 (hàng chữ thứ 1)
    cout << char(186);
    cout << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << char(201) << char(205) << char(203) << char(205) << char(187) << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(201) << char(205) << char(205) << char(205) << char(187) << " "; //E
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(201) << char(205) << char(203) << char(205) << char(187) << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(201) << char(205) << char(205) << char(205) << char(187) << " "; //R
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << " " << char(203) << " " << " ";                                       //I
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << char(201) << char(205) << char(205) << char(205) << char(187) << " "; //S
    cout << " " << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(186) << endl;

    // hàng thứ 3 (hàng chữ thứ 2)
    cout << char(186);
    cout << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << " " << " " << char(186) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(186) << " " << " " << " " << " " << " "; //E
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << " " << " " << char(186) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(186) << " " << " " << " " << char(186) << " "; //R
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << " " << char(186) << " " << " "; // I
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << char(186) << " " << " " << " " << " " << " "; //S
    cout << " " << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(186) << endl;

    // hàng thứ 4 (hàng chữ thứ 3)
    cout << char(186);
    cout << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << " " << " " << char(186) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(204) << char(205) << char(205) << char(205) << char(185) << " "; //E
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << " " << " " << char(186) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(204) << char(205) << char(203) << char(205) << char(188) << " "; //R
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << " " << char(186) << " " << " "; // I
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << char(200) << char(205) << char(205) << char(205) << char(187) << " "; //S
    cout << " " << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(186) << endl;

    //hàng thứ 5 (hàng chữ thứ 4)
    cout << char(186);
    cout << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << " " << " " << char(186) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(186) << " " << " " << " " << " " << " "; //E
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << " " << " " << char(186) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(186) << " " << char(186) << " " << " " << " "; //R
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << " " << char(186) << " " << " "; // I
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << " " << " " << " " << " " << char(186) << " "; //S
    cout << " " << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(186) << endl;

    //hàng thứ 6(hàng chữ thứ 5)
    cout << char(186);
    cout << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << " " << " " << char(202) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(200) << char(205) << char(205) << char(205) << char(188) << " "; //E
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << " " << " " << char(202) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(200) << " " << char(200) << char(205) << char(188) << " "; //R
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << " " << char(202) << " " << " "; // I
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << char(200) << char(205) << char(205) << char(205) << char(188) << " "; //S
    cout << " " << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(186) << endl;

    //hàng thứ 7 đến hàng thứ 14 (7 hàng)
    for(int j = 1; j <= 8; ++j)
        {
            cout << char(186);
            for(int i = 1; i <= 40; ++i)
                cout << " ";
            cout << " " << char(186) << endl;
        }
    //hàng thứ 15
    cout << char(186);
    for(int i = 1; i <= 40; ++i)
        cout << " ";
    cout << " " << char(186) << endl;

    //hàng thứ 16 đến hàng thứ 20 (5 hàng)
    for(int j = 1; j <= 5; ++j)
        {
            cout << char(186);
            for(int i = 1; i <= 40; ++i)
                cout << " ";
            cout << " " << char(186) << endl;
        }

    //hàng cuối cùng
    cout << char(200);
    for(int i = 1; i <= 41; ++i)
        cout << char(205);
    cout << char(188) << endl;
    Sleep(1500);
    //ham tra con tro ve vi tri ghi chu "press any key to continue"
    COORD p = { 8,15 };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );

    //ham lam nhap nhay dong chu "press any key to continue"
    cout << "Press any key to continue";
    Sleep(500);

    while(!kbhit()) {
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
        for(int j = 1; j <= 25; j++)
            cout << " ";
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
        Sleep(500);
        cout << "Press any key to continue";
        Sleep(500);

    }

}

//giao dien menu
void second_ui(int)
{
    system("cls");
    //hàng đầu tiên
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(201);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(203);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(187) << endl;

    //hàng thứ 2 đến hàng thứ 19
    for(int j = 1; j <= 20; ++j)
    {
        cout << char(186);
        for(int i = 1; i <= 20; ++i)
            cout << " ";
        cout << char(186);
        for(int i = 1; i <= 20; ++i)
            cout << " ";
        cout << char(186) << endl;
    }

    //hàng cuối cùng
    cout << char(200);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(202);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(188) << endl;

    //cac option trong menu
    GotoXY(7,6);
    cout << "New game";
    GotoXY(7,9);
    cout << "Help";
    GotoXY(7,12);
    cout << "Credit";
    GotoXY(7,15);
    cout << "Exit";
}

void gameover(int)
{
    //vẽ khung
    //hàng đầu tiên
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << char(201);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(203);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(187) << endl;

    //hàng thứ 2 đến hàng thứ 19
    for(int j = 1; j <= 20; ++j)
    {
        cout << char(186);
        for(int i = 1; i <= 20; ++i)
            cout << " ";
        cout << char(186);
        for(int i = 1; i <= 20; ++i)
            cout << " ";
        cout << char(186) << endl;
    }

    //hàng cuối cùng
    cout << char(200);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(202);
    for(int i = 1; i <= 20; ++i)
        cout << char(205);
    cout << char(188) << endl;

    //chữ GAME
    //hàng đầu tiên
    GotoXY (1,4);
    //G
    cout << char(218) << char(196) << char(196) << char(191);
    cout << " ";
    //A
    cout << char(218) << char(196) << char(196) << char(191);
    cout << " ";
    //M
    cout << char(218) << char(191) << " " << char(218) << char(191);
    cout << " ";
    //E
    cout << char(218) << char(196) << char(196) << char(191);

    //hàng thứ 2
    GotoXY(1,5);
    //G
    cout << char(179) << " " << " " << " ";
    cout << " ";
    //A
    cout << char(179) << " " << " " << char(179);
    cout << " ";
    //M
    cout << char(179) << char(192) << char(191) << char(217) << char(179);
    cout << " ";
    //E
    cout << char(179);

    //hàng thứ 3
    GotoXY(1,6);
    //G
    cout << char(179) << " " << " " << char(194);
    cout << " ";
    //A
    cout << char(195) << char(196) << char(196) << char(180);
    cout << " ";
    //M
    cout << char(179) << " " << " " << " " << char(179);
    cout << " ";
    //E
    cout << char(195) << char(196) << char(196) << " ";

    //hang thu 4
    GotoXY(1,7);
    //G
    cout << char(179) << " " << " " << char(179);
    cout << " ";
    //A
    cout << char(179) << " " << " " << char(179);
    cout << " ";
    //M
    cout << char(179) << " " << " " << " " << char(179);
    cout << " ";
    //E
    cout << char(179);

    //hang thu 5
    GotoXY(1,8);
    //G
    cout << char(192) << char(196) << char(196) << char(217);
    cout << " ";
    //A
    cout << char(192) << " " << " " << char(217);
    cout << " ";
    //M
    cout << char(192) << " " << " " << " " << char(217);
    cout << " ";
    //E
    cout << char(192) << char(196) << char(196) << char(217);

    //chu Over
    //hàng đầu tiên
    GotoXY (2,10);
    //O
    cout << char(218) << char(196) << char(196) << char(191);
    cout << " ";
    //V
    cout << char(218) << " " << " " << char(191);
    cout << " ";
    //E
    cout << char(218) << char(196) << char(191);
    cout << " ";
    //R
    cout << char(218) << char(196) << char(196)  << char(191);

    //hang thu 2
    GotoXY (2,11);
    //O
    cout << char(179) << " " << " " << char(179);
    cout << " ";
    //V
    cout << char(179) << " " << " " << char(179);
    cout << " ";
    //E
    cout << char(179) << " " << " ";
    cout << " ";
    //R
    cout << char(179) << " " << " "  << char(179);

    //hang thu 3
    GotoXY (2,12);
    //O
    cout << char(179) << " " << " " << char(179);
    cout << " ";
    //V
    cout << char(179) << " " << " " << char(179);
    cout << " ";
    //E
    cout << char(195) << char(196) << " ";
    cout << " ";
    //R
    cout << char(179) << char(218) << char(196) << char(217);

    //hang thu 4
    GotoXY (2,13);
    //O
    cout << char(179) << " " << " " << char(179);
    cout << " ";
    //V
    cout << char(92) << " " << " " << char(47);
    cout << " ";
    //E
    cout << char(179) << " " << " ";
    cout << " ";
    //R
    cout << char(179) << char(179) << " " << " ";

    //hang thu 5
    GotoXY (2,14);
    //O
    cout << char(192) << char(196) << char(196) << char(217);
    cout << " ";
    //V
    cout << " " << char(92) << char(47) << " ";
    cout << " ";
    //E
    cout << char(192) << char(196) << char(217);
    cout << " ";
    //R
    cout << char(192) << char(192) << char(196) << char(217);

}

//============================================================

int main() // Main function
{
    ArrayReset();
	khung();
	NextPiece = Random(18);
	NoCursorType(); // Hide console cursor

	// Print once
	GotoXY(67, 1); cout << "X = ";
	GotoXY(67, 2); cout << "Y = ";
	GotoXY(67, 3); cout << "MoveR = ";
	GotoXY(67, 4); cout << "MoveL = ";
	GotoXY(67, 5); cout << "MoveD = ";
	GotoXY(67, 6); cout << "Rot = ";
	GotoXY(67, 7); cout << "State = ";

	while (1) // Infinite loop (or game loop, technically)
    {
		if (kbhit()) // Function that checks keys are pressed or not
		{
			key = getche();
			ASCIIValue = key;
			// Statements process user's input
			if (ASCIIValue == 27) break; // Exit infinite loop when ESC key (ASCII value is 27) is pressed
			InputProcess();
		}

		// Statement checks whether a new tetromino should be generated
		if (NewTetromino)
		{
			tetrominoLocX = Random(16) + 2;
			tetrominoLocY = 1;
			CurrentState = NextPiece;
			NextPiece = Random(18);
			Score += CheckFullRow() * 5;
			NewTetromino = false;

			ArrayDebug();
			GotoXY(0, 0);
			khung();
			Refresh();

			// Print score
			GotoXY(23, 12);
			cout << "Your Score: " << Score;

			//Print next piece
			GotoXY(27, 2);
			cout << "Next piece";
			PrintNextPiece(30, 4);
		}
		
		// Statement controls the dropping speed of tetrominoes
		// The bigger the value, the slower the tetrominoes will drop
		if (DelayTime == 10000)
		{
			tetrominoLocY++;
			DelayTime = 0;
			
			Refresh();
		}
		else DelayTime++;

		//Statement ends the current game
		for (int i = 1; i <= 20; i++) 
			if (tetris[i][2] != 0)
			{
				ArrayReset();
				PrintArray(1, 1);
				Score = 0;
				NewTetromino = true;
			}

		GotoXY(13, 22); // Move console cursor to "Key pressed: " position
	}
	//cin.get();
}
