#include <iostream>
#include <windows.h>

using namespace std;

int tetris[30][30];

void GotoXY( int x, int y ) //Hàm di chuyển con trỏ console
    {
    COORD p = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
    }

void NoCursorType() //Hàm ẩn con trỏ console
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void ArrayReset()
{
    for (int i = 0; i <= 19; i++)
        for (int j = 0; j <= 19; j++)
            tetris[i][j] = 0;
}

void PrintArray(int x, int y) //In mảng bắt đầu từ vị trí có toạ độ (x, y)
{
    GotoXY(x, y);
    for (int i = 0; i <= 19; i++)
        {
            for (int j = 0; j <= 19; j++)
            {
                if (tetris[i][j] = 0) cout << "T"; //Tạm hiển thị là "T"
                else if (tetris[i][j] = -1) cout << "A"; //Tạm hiển thị là "A"
                else if (tetris[i][j] = 1) cout << "O"; //Tạm hiển thị là "O"
            }
            cout << "\n";
            GotoXY(x, y++);
        }
}

//Check full rows
//and delete full rows
//and return a value of deleted rows

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

int main(void)
{
    ArrayReset();
	PrintArray(2, 2);
	cin.get();
}
