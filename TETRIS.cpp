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

int Score = 0, HighScore = 0,
	tetrominoLocX = 0, tetrominoLocY = 0,
	DelayTime = 10, count = 0,
	ASCIIValue;

unsigned short int CurrentState = 0;

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

char key;

bool NewTetromino = false;

//============================================================

// Hàm vẽ các Tetromino

void BlockI1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x + 2][y] = 1;

	CurrentState = 1;
}

void BlockJ1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x + 1][y + 1] = 1;

	CurrentState = 3;
}

void BlockL1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x - 1][y + 1] = 1;

	CurrentState = 7;
}

void BlockO(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x][y + 1] = 1;
	tetris[x + 1][y + 1] = 1;

	CurrentState = 0;
}

void BlockS1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x][y + 1] = 1;
	tetris[x - 1][y + 1] = 1;

	CurrentState = 11;
}

void BlockT1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x][y + 1] = 1;

	CurrentState = 13;
}

void BlockZ1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x][y + 1] = 1;
	tetris[x + 1][y + 1] = 1;

	CurrentState = 17;
}

//============================================================



//============================================================

bool CheckDrop() // Check whether tetrominoes should be dropped or not
{
	if (count == DelayTime) return true;
	else
	{
		count++;
		return false;
	}
}

bool NewTetro() // Check whether a new tetromino should be generated
{
	if (tetrominoLocY >= 23) return true;
	else return false;
}

int Random() // Generate a random number
{
	srand((int)time(0));
	int r = (rand() % (17)) + 5;
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
}

void PrintArray(int x, int y) // In mảng bắt đầu từ vị trí có toạ độ (x, y)
{
    GotoXY(x, y);
    for (int i = 2; i <= 21; i++)
        {
            for (int j = 4; j <= 23; j++)
            {
                if (tetris[j][i] == 0) cout << "T"; // Tạm hiển thị là "T"
                else if (tetris[j][i] == -1) cout << "A"; // Tạm hiển thị là "A"
                else if (tetris[j][i] == 1) cout << "O"; // Tạm hiển thị là "O"
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
    for (int i = 0; i <= 30; i++) tetris[i][n] = '0';
}

void MoveAllRowAbove(int n)
{
    for (int i = n; i >= 0; i--)
    {
        for (int j = 30; j >=0; j--)
        {
            tetris[j][i] = tetris[j][i + 1];
        }
    }
}

int CheckFullRow()
{
    int FullRow;
    bool t = true;
    for (int i = 21; i >= 2; i--)
    {
        for (int j = 23; j >=4; j--)
        {
            if (tetris[j][i] != 1) t = false;
            break;
        }
        if (t)
        {
            FullRow++;
            DeleteRow(i);
        }
        t = true;
    }
    return FullRow;
}

int main()
{
    ArrayReset();
	while (1) // Infinite loop
    {
        ArrayReset();

		if (kbhit()) // Function that checks keys are pressed or not
		{
			key = getch();
			ASCIIValue = key;
			switch (ASCIIValue)
			{
				case 27: break; // Exit infinite loop when ESC key (ASCII value is 27) is pressed
				case 97: tetrominoLocX -= 1; // Move a tetromino to the left when 'A' key is pressed
				case 100: tetrominoLocX += 1; // Move a tetromino to the right when 'D' key is pressed
				case 115: tetrominoLocY += 1; // Move a tetromino down faster when 'S' key is pressed
				case 119: // Change state of a tetromino when 'W' key is pressed
					{
						switch (CurrentState)
						{
							case 1: CurrentState = 2;
							case 2: CurrentState = 1;
							case 3: CurrentState = 4;
							case 4: CurrentState = 5;
							case 5: CurrentState = 6;
							case 6: CurrentState = 3;
							case 7: CurrentState = 8;
							case 8: CurrentState = 9;
							case 9: CurrentState = 10;
							case 10: CurrentState = 7;
							case 11: CurrentState = 12;
							case 12: CurrentState = 11;
							case 13: CurrentState = 14;
							case 14: CurrentState = 15;
							case 15: CurrentState = 16;
							case 16: CurrentState = 13;
							case 17: CurrentState = 18;
							case 18: CurrentState = 17;
						}
					}
			}
		}
		
		tetrominoLocX = Random();
		tetrominoLocY = 12;
		BlockZ1(tetrominoLocX, tetrominoLocY);
		PrintArray(0, 0);
		
	}
	//cin.get();
}
