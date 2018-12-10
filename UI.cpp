#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

//mục lục hàm
void gotoxy(int x,int y); //hàm di chuyển con trỏ đến vị trí (x,y)
void khung(void); // hàm vẽ khung
void welcome(void); // hàm vẽ  giao diện vào game
void MenuLighting(void); //hàm chọn các option trong menu
void KhungMenu(void);// vẽ hàm highlight chữ New Game
void Menu2(void);// vẽ hàm highlight chữ Help
void Menu3(void);// vẽ hàm highlight chữ Credit
void Menu4(void);// vẽ hàm highlight chữ Exit
void gameover(void); // hàm vẽ giao diện kết thúc màn chơi
//char a[50][50];

//ham gotoxy
void gotoxy(int x,int y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = {x,y} ;
    SetConsoleCursorPosition(hStdout,position ) ;
}

void khung(void)
{
    //hàng đầu tiên
    gotoxy(0,0);
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
}

//giao dien welcome
void welcome(void)
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

void MenuLighting(void)
{
    system("cls");
    KhungMenu();
    char key;
    int ASCIIValue;
    int dem = 1;

    while(1)
    {
        if(kbhit())
        {
            key = getch();
            ASCIIValue = key;
            if(ASCIIValue == 97) dem--;
            if(ASCIIValue == 100) dem++;
            if(dem < 1)
            {
                dem = 1;
                continue;
            }
            if(dem > 4)
            {
                dem = 4;
                continue;
            }
            if(dem == 1)
            {
                gotoxy(7,6);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
                cout << "New game";
                gotoxy(7,9);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
                cout << "Help";
            }
            if(dem == 2)
            {
                gotoxy(7,6);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
                cout << "New game";
                gotoxy(7,9);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
                cout << "Help";
                gotoxy(7,12);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
                cout << "Credit";
            }
            if(dem == 3)
            {
                gotoxy(7,9);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
                cout << "Help";
                gotoxy(7,12);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
                cout << "Credit";
                gotoxy(7,15);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
                cout << "Exit";
            }
            if(dem == 4)
            {
                gotoxy(7,12);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
                cout << "Credit";
                gotoxy(7,15);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "Exit";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
            }
        }
    }
}

//giao dien menu1
void KhungMenu(void)
{
    khung();
    //cac option trong menu
    gotoxy(7,6);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << "New game";
    gotoxy(7,9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << "Help";
    gotoxy(7,12);
    cout << "Credit";
    gotoxy(7,15);
    cout << "Exit";
}

void Menu2(void)
{
    khung();
    //cac option trong menu
    gotoxy(7,6);
    cout << "New game";
    gotoxy(7,9);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << "Help";
    gotoxy(7,12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << "Credit";
    gotoxy(7,15);
    cout << "Exit";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
}

void Menu3(void)
{
    khung();
    //cac option trong menu
    gotoxy(7,6);
    cout << "New game";
    gotoxy(7,9);
    cout << "Help";
    gotoxy(7,12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << "Credit";
    gotoxy(7,15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << "Exit";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
}

void Menu4(void)
{
    khung();
    //cac option trong menu
    gotoxy(7,6);
    cout << "New game";
    gotoxy(7,9);
    cout << "Help";
    gotoxy(7,12);
    cout << "Credit";
    gotoxy(7,15);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
    cout << "Exit";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
}

void gameover(void)
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
    gotoxy (1,4);
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
    gotoxy(1,5);
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
    gotoxy(1,6);
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
    gotoxy(1,7);
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
    gotoxy(1,8);
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
    gotoxy (2,10);
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
    gotoxy (2,11);
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
    gotoxy (2,12);
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
    gotoxy (2,13);
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
    gotoxy (2,14);
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

/*
    khung(1);
    int dem = 0;
    gotoxy (22,2); cout << "HOW TO PLAY:";
    gotoxy (22,4); cout << "Your objective is to";
    gotoxy (22,5); cout << "earn highest scores as";
    gotoxy (22,6); cout << "long as possible by";
    gotoxy (22,7); cout << "destroying Tetromino";
    gotoxy (22,8); cout << "blocks.";
    gotoxy (22,18); cout << "Press d to continue";

    gotoxy (22,2); cout << "To destroy the";
    gotoxy (22,3); cout << "blocks, please place";
    gotoxy (22,4); cout << "the blocks to make a";
    gotoxy (22,5); cout << "full blocks row, and";
    gotoxy (22,6); cout << "then the blocks row";
    gotoxy (22,7); cout << "will be disappeared";
    gotoxy (22,8); cout << "and you will earn ";
    gotoxy (22,9); cout << "scores.";
    gotoxy (22,18); cout << "Press d to continue";
*/

int main()
{
    //ham an con tro
    CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);

    welcome();
//    getch();
//
    MenuLighting();
//    khung();
//    gameover();
    gotoxy(0,22);
    return 0;
}
