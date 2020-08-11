// TETRIS GAME BY CONG THUAN HO HAI & KIEU TRANG HA
// Well's size (Matrix size) 20 x 20
// 100% console interface

//============================================================

#include "TETRIS.h"
#include "Tetromino.h"

//============================================================

// Define input keys here
const int	KEY_ESC = 27;
const int	KEY_UP[] = { 72, 119 };
const int	KEY_DOWN[] = { 80, 115 };
const int	KEY_LEFT[] = { 75, 97 };
const int	KEY_RIGHT[] = { 77, 100 };
const int	KEY_SELECT[] = { 13, 102 };

//============================================================

int tetris[30][30]; // Khai báo mảng

int Score = 0, HighScore = 0,
    tetrominoLocX = 0, tetrominoLocY = 0, // Tetromino Location X & Y
    DelayTime = 1, count = 0,
    ASCIIValue,
    dem = 1,
    Level = 1,
    FallingSpeed = 10000;

unsigned short int	CurrentState = 0,
                    NextPiece = 0,
                    colour;

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

char	key; // Stores keys that user pressed

bool	NewTetromino = true,
        CanMoveRight = true,
        CanMoveLeft = true,
        CanMoveDown = true,
        CanRotate = true,
        Pause = false,
        fullrow = false,
        GamePlay = false, // Checks whether the programme is in gameplay state or not
        disable = false; //để tạm dừng màn hình bên trái

//============================================================

bool isUpKey(int x) {
    auto ArraySize = size(KEY_UP);

    for (int i = 0; i < ArraySize; i++) {
        if (KEY_UP[i] == x) return true;
    }

    return false;
}

bool isDownKey(int x) {
    auto ArraySize = size(KEY_DOWN);

    for (int i = 0; i < ArraySize; i++) {
        if (KEY_DOWN[i] == x) return true;
    }

    return false;
}

bool isLeftKey(int x) {
    auto ArraySize = size(KEY_LEFT);

    for (int i = 0; i < ArraySize; i++) {
        if (KEY_LEFT[i] == x) return true;
    }

    return false;
}

bool isRightKey(int x) {
    auto ArraySize = size(KEY_RIGHT);

    for (int i = 0; i < ArraySize; i++) {
        if (KEY_RIGHT[i] == x) return true;
    }

    return false;
}

bool isSelectKey(int x) {
    auto ArraySize = size(KEY_SELECT);

    for (int i = 0; i < ArraySize; i++) {
        if (KEY_SELECT[i] == x) return true;
    }

    return false;
}

int Random(int n) // Generate a random number
{
    srand((int)time(0));
    int r = (rand() % n);
    return r;
}

void GotoXY(int x, int y) // Hàm di chuyển con trỏ console
{
    COORD p = { x, y };
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
            switch (tetris[j][i])
            {
            case 0: { Colour(0); cout << " "; break; }
            case 1: { Colour(1); cout << char(178); break; }
            case 2: { Colour(2); cout << char(178); break; }
            case 3: { Colour(3); cout << char(178); break; }
            case 4: { Colour(4); cout << char(178); break; }
            case 5: { Colour(5); cout << char(178); break; }
            case 6: { Colour(6); cout << char(178); break; }
            }
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
        for (int j = 0; j < 22; j++)
            switch (tetris[j][i])
            {
            case 0: { Colour(6); cout << tetris[j][i]; break; }
            case 1: { Colour(1); cout << tetris[j][i]; break; }
            case 2: { Colour(2); cout << tetris[j][i]; break; }
            case 3: { Colour(3); cout << tetris[j][i]; break; }
            case 4: { Colour(4); cout << tetris[j][i]; break; }
            case 5: { Colour(5); cout << tetris[j][i]; break; }
            case 6: { Colour(6); cout << tetris[j][i]; break; }
            }
        Colour(6); // Set the text colour back to white
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
    fullrow = false;
    for (int i = 1; i <= 21; i++)
    {
        for (int j = 1; j <= 21; j++)
        {
            if (tetris[j][i] == 0)
            {
                t = false;
                fullrow = t;
                break;
            }
            t = true;
            fullrow = t;
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
    Colour(colour);
    PrintTetromino();
    Colour(6);

    // Print out the key that user pressed
    GotoXY(0, 22);
    cout << "Key pressed: ";

    PrintVariables();

    // Print score
    GotoXY(35, 12);
    cout << Score;

    //Print next piece
    GotoXY(27, 3); cout << "       ";
    GotoXY(27, 4); cout << "       ";
    GotoXY(27, 5); cout << "       ";
    GotoXY(27, 6); cout << "       ";
    GotoXY(27, 7); cout << "       ";
    PrintNextPiece(30, 4);

    GotoXY(30, 10);
    cout << Level;
}

void InputProcess() // Function processing user's input
{
    if (isLeftKey(ASCIIValue) && !Pause) // Moves current tetromino to the left if the 'a' key is pressed
    {
        if (CanMoveLeft) tetrominoLocX--;
        Refresh();
    }
    if (isRightKey(ASCIIValue) && !Pause) // Moves current tetromino to the right if the 'd' key is pressed
    {
        if (CanMoveRight) tetrominoLocX++;
        Refresh();
    }
    if (isDownKey(ASCIIValue) && !Pause) // Moves current tetromino down if the 's' key is pressed
    {
        if (CanMoveDown) if (tetrominoLocY < 20) tetrominoLocY++;
        Refresh();
    }
    if (ASCIIValue == 32)
        if (Pause)
        {
            Pause = false;
            GotoXY(29, 15);
            cout << "      "; // Delete "Paused" text
            GotoXY(13, 22); // Move console cursor to "Key pressed: " position
        }
        else
        {
            Pause = true;
            GotoXY(29, 15);
            cout << "Paused"; // Print "Paused" text out
            GotoXY(13, 22); // Move console cursor to "Key pressed: " position
        }
    if (isUpKey(ASCIIValue) && !Pause) // Change state of a tetromino when 'w' key is pressed
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
