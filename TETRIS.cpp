// TETRIS GAME BY CONG THUAN HO HAI & KIEU TRANG HA
// Well's size (Matrix size) 20 x 20
// 100% console interface

//============================================================

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>

//============================================================

using namespace std;

//============================================================

int tetris[30][30]; // Khai báo mảng

int Score = 0, HighScore = 0,
	tetrominoLocX = 0, tetrominoLocY = 0,
	DelayTime = 10, count = 0,
	ASCIIValue;

char key;

string CurrentState = "";

bool NewTetromino = false;

//============================================================

// Hàm vẽ các Tetromino

void BlockI1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x + 2][y] = 1;

	CurrentState = "I1";
}

void BlockJ1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x + 1][y + 1] = 1;

	CurrentState = "J1";
}

void BlockL1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x - 1][y + 1] = 1;

	CurrentState = "L1";
}

void BlockO(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x][y + 1] = 1;
	tetris[x + 1][y + 1] = 1;

	CurrentState = "";
}

void BlockS1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x][y + 1] = 1;
	tetris[x - 1][y + 1] = 1;

	CurrentState = "S1";
}

void BlockT1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x][y + 1] = 1;

	CurrentState = "T1";
}

void BlockZ1(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x][y + 1] = 1;
	tetris[x + 1][y + 1] = 1;

	CurrentState = "Z1";
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
        if (kbhit()) // Function that checks keys are pressed or not
		{
			key = getch();
			ASCIIValue = key;
			if (ASCIIValue == 27) break; // Exit infinite loop when ESC key (ASCII value is 27) is pressed
		}
		ArrayReset();
		tetrominoLocX = Random();
		tetrominoLocY = 12;
		BlockZ1(tetrominoLocX, tetrominoLocY);
		PrintArray(0, 0);
		switch (CurrentState)
		{
			case 'I1': CurrentState = "I2";
			case 'I2': CurrentState = "I1";
			case 'J1': CurrentState = "J2";
			case 'J2': CurrentState = "J3";
			case 'J3': CurrentState = "J4";
			case 'J4': CurrentState = "J1";
			case 'L1': CurrentState = "L2";
			case 'L2': CurrentState = "L3";
			case 'L3': CurrentState = "L4";
			case 'L4': CurrentState = "L1";
			case 'S1': CurrentState = "S2";
			case 'S2': CurrentState = "S1";
			case 'T1': CurrentState = "T2";
			case 'T2': CurrentState = "T3";
			case 'T3': CurrentState = "T4";
			case 'T4': CurrentState = "T1";
			case 'Z1': CurrentState = "Z2";
			case 'Z2': CurrentState = "Z1";
		}
	}
	//cin.get();
}
