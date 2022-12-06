// TECON GAME (Tetris clone) BY THUAN HAI CONG HO & TRANG KIEU HA
// Well's size (Matrix size) 20 x 20
// 100% ASCII interface

//============================================================

#pragma once

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iterator>

using namespace std;

//============================================================
// "extern" keyword is used to avoid multiple definitions
// it makes variables visible to other source files that want
// to use them but variables are only defined in one place
// In this case, these variables are defined in TETRIS.cpp

extern const int	KEY_ESC;
extern const int	KEY_UP[];
extern const int	KEY_DOWN[];
extern const int	KEY_LEFT[];
extern const int	KEY_RIGHT[];
extern const int	KEY_SELECT[];

extern int tecon[30][30]; // Khai báo mảng

extern int  Score, HighScore,
            teconnyLocX, teconnyLocY, // Teconny Location X & Y
            DelayTime, count,
            ASCIIValue,
            dem,
            Level,
            FallingSpeed;

extern unsigned short int	CurrentState,
                            NextPiece,
                            colour;

// Quy ước các trạng thái của teconny
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

extern char key; // Stores keys that user pressed

extern bool	NewTeconny,
            CanMoveRight,
            CanMoveLeft,
            CanMoveDown,
            CanRotate,
            Pause,
            fullrow,
            GamePlay, // Checks whether the programme is in gameplay state or not
            disable; // để tạm dừng màn hình bên trái


int Random(int n);
int CheckFullRow();

void Colour(int n);
void GotoXY(int x, int y);
void NoCursorType();
void ArrayReset();
void PrintArray(int x, int y);
void ArrayDebug();
void DeleteRow(int n);
void MoveAllRowAbove(int n);
void Refresh();
void InputProcess();
void PrintVariables();

bool isUpKey(int x);
bool isDownKey(int x);
bool isLeftKey(int x);
bool isRightKey(int x);
bool isSelectKey(int x);
