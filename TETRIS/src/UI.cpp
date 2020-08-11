#include "UI.h"
#include "TETRIS.h"

// User Interface
// This part was written by Trang Ha Kieu

void khung()
{
    GotoXY(0, 0);

    //Draw first row
    for (int i = 1; i <= 42; i++)
    {
        GotoXY(i, 0);
        cout << char(205);
    }
    GotoXY(0, 0); cout << char(201);
    GotoXY(43, 0); cout << char(187);
    GotoXY(21, 0); cout << char(203);

    //Draw next 20 rows
    for (int i = 1; i <= 20; i++)
    {
        GotoXY(0, i); cout << char(186);
        GotoXY(21, i); cout << char(186);
        GotoXY(43, i); cout << char(186);
    }

    //Draw last row
    for (int i = 1; i <= 42; i++)
    {
        GotoXY(i, 21);
        cout << char(205);
    }
    GotoXY(0, 21); cout << char(200);
    GotoXY(43, 21); cout << char(188);
    GotoXY(21, 21); cout << char(202);
}

void xoakhungbenphai()
{
    for (int j = 1; j <= 20; j++)
    {
        GotoXY(22, j);
        for (int i = 22; i <= 41; i++)
            cout << " ";
    }
}

//giao dien welcome
void welcome()
{
    //hàng đầu tiên
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(201);
    for (int i = 1; i <= 41; ++i)
        cout << char(205);
    cout << char(187) << endl;

    //hàng thứ 1
    cout << char(186);
    for (int i = 1; i <= 40; ++i)
        cout << " ";
    cout << " " << char(186) << endl;

    //hang thứ 2 (hàng chữ thứ 1)
    cout << char(186);
    cout << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << char(201) << char(205) << char(203) << char(205) << char(187) << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(186) << endl;

    // hàng thứ 3 (hàng chữ thứ 2)
    cout << char(186);
    cout << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << " " << " " << char(186) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(186) << endl;

    // hàng thứ 4 (hàng chữ thứ 3)
    cout << char(186);
    cout << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << " " << " " << char(186) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(186) << endl;

    //hàng thứ 5 (hàng chữ thứ 4)
    cout << char(186);
    cout << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << " " << " " << char(186) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(186) << endl;

    //hàng thứ 6(hàng chữ thứ 5)
    cout << char(186);
    cout << " " << " " << " ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << " " << " " << char(202) << " " << " " << " "; //T
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << char(186) << endl;

    //hàng thứ 7 đến hàng thứ 14 (7 hàng)
    for (int j = 1; j <= 8; ++j)
    {
        cout << char(186);
        for (int i = 1; i <= 40; ++i)
            cout << " ";
        cout << " " << char(186) << endl;
    }
    //hàng thứ 15
    cout << char(186);
    for (int i = 1; i <= 40; ++i)
        cout << " ";
    cout << " " << char(186) << endl;

    //hàng thứ 16 đến hàng thứ 20 (5 hàng)
    for (int j = 1; j <= 5; ++j)
    {
        cout << char(186);
        for (int i = 1; i <= 40; ++i)
            cout << " ";
        cout << " " << char(186) << endl;
    }

    //hàng cuối cùng
    cout << char(200);
    for (int i = 1; i <= 41; ++i)
        cout << char(205);
    cout << char(188) << endl;
    Sleep(1500);
    //ham tra con tro ve vi tri ghi chu "press any key to continue"
    COORD p = { 8,15 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);

    //ham lam nhap nhay dong chu "press any key to continue"
    cout << "Press any key to continue";
    Sleep(500);

    while (!_kbhit()) {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
        for (int j = 1; j <= 25; j++)
            cout << " ";
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
        Sleep(500);
        cout << "Press any key to continue";
        Sleep(500);

    }

}

//giao dien menu1
void khungmenu()
{
    khung();
    //cac option trong menu
    GotoXY(7, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "New game";
    GotoXY(7, 9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Help";
    GotoXY(7, 12);
    cout << "Credit";
    GotoXY(7, 15);
    cout << "Exit";
}

void khungmenu1()
{
    GotoXY(7, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "New game";
    GotoXY(7, 9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Help";
}

void khungmenu2()
{
    GotoXY(7, 6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "New game";
    GotoXY(7, 9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Help";
    GotoXY(7, 12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Credit";
}

void khungmenu3()
{
    GotoXY(7, 9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Help";
    GotoXY(7, 12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Credit";
    GotoXY(7, 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Exit";
}

void khungmenu4()
{
    GotoXY(7, 12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Credit";
    GotoXY(7, 15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Exit";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void help()
{
    xoakhungbenphai();
    GotoXY(22, 2); cout << "Use A, S, D, W keys";
    GotoXY(22, 3); cout << "to move left, down,";
    GotoXY(22, 4); cout << "right & rotate the ";
    GotoXY(22, 5); cout << "blocks. ";
    GotoXY(22, 7); cout << "Put the blocks in ";
    GotoXY(22, 8); cout << "full rows to earn";
    GotoXY(22, 9); cout << "score.";
    GotoXY(22, 11); cout << "Level up w/ every";
    GotoXY(22, 12); cout << "100 score earned.";
    GotoXY(22, 14); cout << "Blocks' falling ";
    GotoXY(22, 15); cout << "speed increase as ";
    GotoXY(22, 16); cout << "the level increase.";

    GotoXY(22, 19); cout << "*Press Esc to";
    GotoXY(22, 20); cout << "control menu";
}

void credit()
{
    xoakhungbenphai();
    GotoXY(22, 2); cout << "  This is project";
    GotoXY(22, 3); cout << "   homework in a";
    GotoXY(22, 4); cout << "  university class.";
    GotoXY(22, 6); cout << "Class:";
    GotoXY(22, 7); cout << "IT001.J13.MTCL - VN";
    GotoXY(22, 9); cout << "Programer:";
    GotoXY(22, 10); cout << "Ho Hai Cong Thuan";
    GotoXY(22, 11); cout << "ID: 18521469";
    GotoXY(22, 12); cout << "Ha Kieu Trang";
    GotoXY(22, 13); cout << "ID: 18521522";
    GotoXY(22, 19); cout << "*Press Esc to";
    GotoXY(22, 20); cout << "control menu";
}

// Unused function

/* void gameover()
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

} */