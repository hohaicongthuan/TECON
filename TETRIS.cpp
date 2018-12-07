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

int Score = -10, HighScore = 0,
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

//============================================================

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

	for (int i = 0; i <= 20; i++)
		tetris[i][20] = 1;
}

void PrintArray(int x, int y) // In mảng bắt đầu từ vị trí có toạ độ (x, y)
{
    GotoXY(x, y);
    for (int i = 0; i <= 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (tetris[j][i] == 0) cout << " "; //char(176); // Tạm hiển thị là "T"
                /* else if (tetris[j][i] == -1) cout << "A"; // Tạm hiển thị là "A" */
                else if (tetris[j][i] == 1) cout << char(178); // Tạm hiển thị là "O"
            }
            cout << "\n";
            GotoXY(x, y++);
        }
}

// Check full rows
// and delete full rows
// and return a value of deleted rows

void DeleteRow(int n)
{
    for (int i = 0; i <= 20; i++) tetris[i][n] = 0;
}

void MoveAllRowAbove(int n)
{
    for (int i = n; i >= 0; i--)
    {
        for (int j = 20; j >= 0; j--)
        {
            tetris[j][i] = tetris[j][i - 1];
        }
    }
}

int CheckFullRow() // Function that checks and returns a number of full rows
{
    int FullRow = 0;
	bool t = false;
    for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 19; j++)
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
	GotoXY(69, 1);
	cout << tetrominoLocX << " ";
	GotoXY(69, 2);
	cout << tetrominoLocY << " ";
	GotoXY(73, 3);
	if (CanMoveRight) cout << "True "; else cout << "False";
	GotoXY(73, 4);
	if (CanMoveLeft) cout << "True "; else cout << "False";
	GotoXY(73, 5);
	if (CanMoveDown) cout << "True "; else cout << "False";
	GotoXY(71, 6);
	if (CanRotate) cout << "True "; else cout << "False";
	GotoXY(73, 7);
	cout << CurrentState;
}

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

//=============================================================

// Hàm vẽ các Tetromino

void BlockI1(int x, int y)
{
	// Print the block on the screen
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 3, y + 1); cout << char(178);

	CurrentState = 1;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX + 2][tetrominoLocY + 1] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 2][tetrominoLocY] = 1;
		}
	else CanMoveDown = true;

	// Statement checks whether the tetromino could move left
	if (tetrominoLocX - 2 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	//Statement checks whether the tetromino could move right
	if (tetrominoLocX + 3 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	//Statement checks whether the tetromino could rotate (or switch state technically)
	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY - 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 2] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 3, tetrominoLocY + 2); cout << char(248);
}

void BlockI2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 1, y + 3); cout << char(178);

	CurrentState = 2;

	if (tetrominoLocY >= 18 ||
		tetris[tetrominoLocX][tetrominoLocY - 2] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 3] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY - 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 2] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 2][tetrominoLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX + 1, tetrominoLocY - 1); cout << char(248);
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 4); cout << char(248);
}

void BlockJ1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 3;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY - 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockJ2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 4;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY - 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY + 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY - 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
}

void BlockJ3(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x, y); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 5;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY - 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY - 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY - 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockJ4(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 2, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);

	CurrentState = 6;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY - 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY - 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0)
		CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 1); cout << char(248);
}

void BlockL1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 7;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 2] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY + 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY - 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
}

void BlockL2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 8;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY - 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY - 1] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockL3(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 2, y); cout << char(178);

	CurrentState = 9;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY - 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY - 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY - 1] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
}

void BlockL4(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y); cout << char(178);

	CurrentState = 10;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX - 1][tetrominoLocY] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY - 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY - 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	GotoXY(tetrominoLocX, tetrominoLocY + 1); cout << char(248);
}

void BlockO(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 0;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	CanRotate = true;

	// Print collision points
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockS1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 11;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 2] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY + 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY - 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	GotoXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
}

void BlockS2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 12;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY - 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockT1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);

	CurrentState = 13;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY - 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockT2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 14;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY - 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY - 1] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockT3(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 2, y + 1); cout << char(178);

	CurrentState = 15;

	if (tetrominoLocY >= 20 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY - 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY - 1] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
}

void BlockT4(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);

	CurrentState = 16;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY - 1] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 >= 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
}

void BlockZ1(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x + 1, y + 2); cout << char(178);
	GotoXY(x + 2, y + 2); cout << char(178);

	CurrentState = 17;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
		tetris[tetrominoLocX + 1][tetrominoLocY + 2] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 18) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY - 1] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY + 1] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
	GotoXY(tetrominoLocX + 2, tetrominoLocY + 3); cout << char(248);
}

void BlockZ2(int x, int y)
{
	GotoXY(x + 1, y + 1); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x, y + 2); cout << char(178);

	CurrentState = 18;

	if (tetrominoLocY >= 19 ||
		tetris[tetrominoLocX][tetrominoLocY + 1] != 0 ||
		tetris[tetrominoLocX - 1][tetrominoLocY + 2] != 0)
		{
			NewTetromino = true;
			CanMoveDown = false;
			tetris[tetrominoLocX][tetrominoLocY] = 1;
			tetris[tetrominoLocX][tetrominoLocY - 1] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY] = 1;
			tetris[tetrominoLocX - 1][tetrominoLocY + 1] = 1;
		}
	else CanMoveDown = true;

	if (tetrominoLocX - 1 > 0) CanMoveLeft = true;
	else CanMoveLeft = false;

	if (tetrominoLocX + 1 <= 19) CanMoveRight = true;
	else CanMoveRight = false;

	if (tetris[tetrominoLocX][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX - 1][tetrominoLocY] == 0 &&
		tetris[tetrominoLocX][tetrominoLocY + 1] == 0 &&
		tetris[tetrominoLocX + 1][tetrominoLocY + 1] == 0)
	CanRotate = true;
	else CanRotate = false;

	// Print collision points
	GotoXY(tetrominoLocX + 1, tetrominoLocY + 2); cout << char(248);
	GotoXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);
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

//============================================================

int main()
{
    ArrayReset();
	khung();
	NextPiece = Random(18);

	// Print variables (once)
	GotoXY(65, 1); cout << "X = ";
	GotoXY(65, 2); cout << "Y = ";
	GotoXY(65, 3); cout << "MoveR = ";
	GotoXY(65, 4); cout << "MoveL = ";
	GotoXY(65, 5); cout << "MoveD = ";
	GotoXY(65, 6); cout << "Rot = ";
	GotoXY(65, 7); cout << "State = ";

	while (1) // Infinite loop (or game loop, technically)
    {
		if (kbhit()) // Function that checks keys are pressed or not
		{
			key = getche();
			ASCIIValue = key;
			if (ASCIIValue == 27) break; // Exit infinite loop when ESC key (ASCII value is 27) is pressed
			if (ASCIIValue == 97) 
			{
				if (CanMoveLeft) tetrominoLocX -= 1;
				PrintArray(1, 1);
				PrintTetromino();
				
				// Print out the key that user pressed
				GotoXY(0, 22);
				cout << "Key pressed: ";

				PrintVariables();
			}
			if (ASCIIValue == 100) 
			{
				if (CanMoveRight) tetrominoLocX += 1;
				PrintArray(1, 1);
				PrintTetromino();

				// Print out the key that user pressed
				GotoXY(0, 22);
				cout << "Key pressed: ";

				PrintVariables();
			}
			if (ASCIIValue == 115) 
			{
				if (CanMoveDown) if (tetrominoLocY < 20) tetrominoLocY += 1;
				PrintArray(1, 1);
				PrintTetromino();

				// Print out the key that user pressed
				GotoXY(0, 22);
				cout << "Key pressed: ";

				PrintVariables();
			}
			if (ASCIIValue == 119) // Change state of a tetromino when 'W' key is pressed
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
					PrintArray(1, 1);
					PrintTetromino();

					// Print out the key that user pressed
					GotoXY(0, 22);
					cout << "Key pressed: ";

					PrintVariables();
				}
				
		}

		// Statement checks whether a new tetromino should be generated
		if (NewTetromino)
		{
			tetrominoLocX = Random(16) + 2;
			tetrominoLocY = 1;
			CurrentState = NextPiece;
			NextPiece = Random(18);
			GotoXY(0, 0);
			khung();
			Score += CheckFullRow() * 10;
			NewTetromino = false;
			
			// Print score
			GotoXY(22, 12);
			cout << "Your Score: " << Score;

			//Print next piece
			GotoXY(27, 2);
			cout << "Next piece";
			PrintNextPiece(30, 4);
			

			// Print array
			int t = 1;
			GotoXY(44, t);
			for (int i = 0; i <= 20; i++)
				{
					for (int j = 0; j < 20; j++) cout << tetris[j][i];
					GotoXY(44, t++);
				}
			
			PrintArray(1, 1);
			PrintTetromino();

			// Print out the key that user pressed
			GotoXY(0, 22);
			cout << "Key pressed: ";

			PrintVariables();
		}
		
		if (DelayTime == 20000)
		{
			tetrominoLocY += 1;
			DelayTime = 0;
			
			PrintArray(1, 1);
			PrintTetromino();
			
			// Print out the key that user pressed
			GotoXY(0, 22);
			cout << "Key pressed: ";

			PrintVariables();
		}
		else DelayTime++;

		//Statement ends the current game
		for (int i = 0; i <= 19; i++) 
			if (tetris[i][0] != 0)
			{
				ArrayReset();
				PrintArray(1, 1);
				Score = -10;
				NewTetromino = true;
			}

		GotoXY(13, 22);
	}
	//cin.get();
}
