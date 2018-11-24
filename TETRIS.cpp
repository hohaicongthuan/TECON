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
	tetrominoLocX = 0, tetrominoLocY = 0, // Tetromino Location X & Y
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

bool NewTetromino = true,
	 CanMoveRight = true,
	 CanMoveLeft = true,
	 CanMoveDown = true;

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

int Random() // Generate a random number
{
	srand((int)time(0));
	int r = (rand() % (19) + 1);
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
    for (int i = 0; i <= 20; i++)
        {
            for (int j = 0; j <= 20; j++)
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

int CheckFullRow() // Function that checks and returns a number of full rows
{
    int FullRow = 0;
    bool t = true;
    for (int i = 21; i >= 2; i--)
    {
        for (int j = 23; j >=4; j--)
        {
            if (tetris[j][i] != 1)
			{
				t = false;
				break;
			}
        }
        if (t)
        {
            FullRow++;
            DeleteRow(i);
			MoveAllRowAbove(i);
        }
        t = true;
    }
    return FullRow;
}

//=============================================================

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
	GotoXY(x, y); cout << char(178);
	GotoXY(x + 1, y); cout << char(178);
	GotoXY(x, y + 1); cout << char(178);
	GotoXY(x - 1, y + 1); cout << char(178);

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
			if (ASCIIValue == 97) if (tetrominoLocX > 1) tetrominoLocX -= 1;
			if (ASCIIValue == 100) if (tetrominoLocX < 19) tetrominoLocX += 1;
			if (ASCIIValue == 115) if (tetrominoLocY < 18) tetrominoLocY += 1;;
			/* if (ASCIIValue == 119) // Change state of a tetromino when 'W' key is pressed
				{
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
				} */
				
		}
		PrintArray(1, 1);

		if (NewTetromino)
		{
			tetrominoLocX = Random();
			tetrominoLocY = 1;
			NewTetromino = false;
		}

		BlockS1(tetrominoLocX + 1, tetrominoLocY + 1);

		GotoXY(tetrominoLocX + 2, tetrominoLocY + 2); cout << char(248);
		GotoXY(tetrominoLocX + 1, tetrominoLocY + 3); cout << char(248);
		GotoXY(tetrominoLocX, tetrominoLocY + 3); cout << char(248);

		if (DelayTime == 20)
		{
			tetrominoLocY += 1;
			DelayTime = 0;
		}
		else DelayTime++;

		if (tetrominoLocY > 18 ||
			tetris[tetrominoLocX + 1][tetrominoLocY + 1] != 0 ||
			tetris[tetrominoLocX][tetrominoLocY + 2] != 0 ||
			tetris[tetrominoLocX - 1][tetrominoLocY + 2] != 0)
			{
				NewTetromino = true;
				tetris[tetrominoLocX][tetrominoLocY] = 1;
				tetris[tetrominoLocX + 1][tetrominoLocY] = 1;
				tetris[tetrominoLocX][tetrominoLocY + 1] = 1;
				tetris[tetrominoLocX - 1][tetrominoLocY + 1] = 1;
			}

		int t = 1;
		GotoXY(23, t);
		for (int i = 0; i <= 20; i++)
			{
				for (int j = 0; j <= 20; j++) cout << tetris[j][i];
				GotoXY(23, t++);
			}

		GotoXY(0, 21);
		cout << Score;
	}
	//cin.get();
}
