#pragma once

#include <fstream>
#include <ctime>

/* extern struct SaveContent {
    tm* DateTime;
    
    int tetris[30][30];

    int Score, HighScore,
        tetrominoLocX, tetrominoLocY,
        DelayTime, count, ASCIIValue,
        dem, Level, FallingSpeed;

    unsigned short int	CurrentState,
        NextPiece, colour;
    
    char	key; // Stores keys that user pressed

    bool	NewTetromino,
            CanMoveRight,
            CanMoveLeft,
            CanMoveDown,
            CanRotate,
            Pause,
            fullrow,
            GamePlay, // Checks whether the programme is in gameplay state or not
            disable; //để tạm dừng màn hình bên trái
}; */

tm* GetTime();
void TransferSaveContent(SaveContent &x);
void SaveRead();
void SaveWrite();
