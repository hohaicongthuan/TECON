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

char key;

bool NewTetromino = false;

//============================================================

// Hàm vẽ các Tetromino

void BlockI(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x + 2][y] = 1;
}

void BlockJ(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x + 1][y + 1] = 1;
}

void BlockL(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x - 1][y + 1] = 1;
}

void BlockO(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x][y + 1] = 1;
	tetris[x + 1][y + 1] = 1;
}

void BlockS(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x][y + 1] = 1;
	tetris[x - 1][y + 1] = 1;
}

void BlockT(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x + 1][y] = 1;
	tetris[x][y + 1] = 1;
}

void BlockZ(int x, int y)
{
	tetris[x][y] = 1;
	tetris[x - 1][y] = 1;
	tetris[x][y + 1] = 1;
	tetris[x + 1][y + 1] = 1;
}

//============================================================

// Hàm di chuyển các tetromino

void MoveBlockILeft(int x, int y)
{
	if (((x - 2) > 2) || ((x - 1) > 2))
	{
		tetris[x - 2][y] = tetris[x - 1][y];
		tetris[x - 1][y] = tetris[x][y];
		tetris[x][y] = tetris[x + 1][y];
		tetris[x + 1][y] = tetris[x + 2][y];
		tetris[x - 1][y - 1] = tetris[x][y - 1];
		tetris[x - 1][y + 1] = tetris[x][y + 1];
		tetris[x - 1][y + 2] = tetris[x][y + 2];

		tetris[x + 2][y] = 0;
		tetris[x][y - 1] = 0;
		tetris[x][y + 1] = 0;
		tetris[x][y + 2] = 0;

		tetrominoLocX = x - 1;
		tetrominoLocY = y;
	}
}

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
	int r = (rand() % (20 - 3 + 1)) + 3;
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
            tetris[i][j] = 0;
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
    for (int i = 0; i <= 19; i++) tetris[n][i] = '0';
}

void MoveAllRowAbove(int n)
{
    for (int i = n; i >= 0; i--)
    {
        for (int j = 19; j >=0; j--)
        {
            tetris[i][j] = tetris[i+1][j];
        }
    }
}

int CheckFullRow()
{
    int FullRow;
    bool t = true;
    for (int i = 19; i >= 0; i--)
    {
        for (int j = 19; j >=0; j--)
        {
            if (tetris[i][j] != 1) t = false;
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
			key = getche();
			ASCIIValue = key;
			if (ASCIIValue == 27) break; // Exit infinite loop when ESC key (ASCII value is 27) is pressed
		}
		ArrayReset();
		if (NewTetro)
		{
			tetrominoLocX = Random();
			tetrominoLocY = 10;
		}
		BlockZ(tetrominoLocX, tetrominoLocY);
		PrintArray(2, 2);
	}
	//cin.get();
}
