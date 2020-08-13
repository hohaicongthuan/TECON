#include "GameSave.h"
#include "TETRIS.h"

struct SaveContent {
    tm* DateTime;

    int tetris[30][30];

    int Score = 0, HighScore = 0,
        tetrominoLocX = 0, tetrominoLocY = 0,
        DelayTime = 1, count = 0,
        ASCIIValue,
        dem = 1,
        Level = 1,
        FallingSpeed = 10000;

    unsigned short int	CurrentState = 0,
        NextPiece = 0,
        colour;

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
};

// Get the current time from the system
tm* GetTime() {
	time_t Now = time(0);
	tm* TimeNow = localtime(&Now);

	TimeNow->tm_year += 1900;
	TimeNow->tm_mon += 1;
	TimeNow->tm_hour += 1;
	TimeNow->tm_min += 1;
	TimeNow->tm_sec += 1;

	return TimeNow;
}

// Transfer all current values from global variables
// to the struct x
void TransferSaveContent(SaveContent& x) {
    x.ASCIIValue = ASCIIValue;
    x.CanMoveDown = CanMoveDown;
    x.CanMoveLeft = CanMoveLeft;
    x.CanMoveRight = CanMoveRight;
    x.CanRotate = CanRotate;
    x.colour = colour;
    x.CurrentState = CurrentState;
    x.DateTime = GetTime();
    x.DelayTime = DelayTime;
    x.dem = dem;
    x.disable = disable;
    x.FallingSpeed = FallingSpeed;
    x.fullrow = fullrow;
    x.GamePlay = GamePlay;
    x.HighScore = HighScore;
    x.key = key;
    x.Level = Level;
    x.NewTetromino = NewTetromino;
    x.NextPiece = NextPiece;
    x.Pause = Pause;
    x.Score = Score;
    x.tetrominoLocX = tetrominoLocX;
    x.tetrominoLocY = tetrominoLocY;
    
    for (int i = 0; i < 30; i++)
        for (int j = 0; j < 30; j++)
            x.tetris[i][j] = tetris[i][j];
}

void SaveRead() {
	ifstream SaveGame;
    SaveContent savcontnt;

    // Open the file as read-only
	SaveGame.open("SaveGame.sav", ios::in | ios::binary);
    SaveGame.seekg(0);
    SaveGame.read((char*)&savcontnt, sizeof(SaveContent));

	SaveGame.close();
}

void SaveWrite() {
	ofstream SaveGame;
    SaveContent savcontnt;
    TransferSaveContent(savcontnt);

	// Open the file as write-only
	SaveGame.open("SaveGame.sav", ios::out | ios::binary);
	// Move the put pointer to the beginning of the file,
	// which means old data of the file will be overwritten
	SaveGame.seekp(0);
    SaveGame.write((char*)&savcontnt, sizeof(SaveContent));

	SaveGame.close();
}
