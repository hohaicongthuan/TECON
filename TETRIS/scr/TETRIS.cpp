// TETRIS GAME BY CONG THUAN HO HAI & KIEU TRANG HA
// Well's size (Matrix size) 20 x 20
// 100% console interface

//============================================================

#include "TETRIS.h"

//============================================================


int main() // Main function
{
	NoCursorType(); // Hide console cursor

	// Print Welcome Screen
	GotoXY(0, 0);
	welcome();
	system("cls");
    khungmenu();

	while(1)
    {
        if(_kbhit())
        {
            key = _getch();
            ASCIIValue = key;
			//coi mỗi giao diện là 1 con số, thay đổi con số là thay đổi giao diện
            if (ASCIIValue == 119 && disable == false) dem--; 
            if (ASCIIValue == 115 && disable == false) dem++;
            if (ASCIIValue == 13) disable = true;
            if (ASCIIValue == 27) 
			{
				disable = false;
				xoakhungbenphai();
			}
            if(dem < 1) //chặn highlight nếu như đã ở trên cùng mà vẫn bấm nút lên
            {
                dem = 1;
                //continue;
            }
            if(dem > 4) // chặn highlight nếu như đã ở dưới cùng mà vẫn bấm nút xuống
            {
                dem = 4;
                //continue;
            }
            if(dem == 1)
            {
                khungmenu1(); //highlight chữ New game
                //link phần của ông vào đây :3
				if (ASCIIValue == 13)
				{
					// Initialising
					ArrayReset();
					Colour(6); // Set default text colour to white
					NextPiece = Random(18); // Generate the first tetromino
					Level = 1;
					
					// Print once
					GotoXY(67, 1); cout << "X = ";
					GotoXY(67, 2); cout << "Y = ";
					GotoXY(67, 3); cout << "MoveR = ";
					GotoXY(67, 4); cout << "MoveL = ";
					GotoXY(67, 5); cout << "MoveD = ";
					GotoXY(67, 6); cout << "Rot = ";
					GotoXY(67, 7); cout << "State = ";
					GotoXY(23, 12); cout << "Your Score: ";
					GotoXY(27, 2); cout << "Next piece";
					GotoXY(23, 18); cout << "Spacebar to pause";
					GotoXY(23, 20); cout << "ESC to exit";
					GotoXY(23, 10); cout << "Level: ";
					
					while (1) // Infinite loop (or game loop, technically)
					{
						if (_kbhit()) // Function that checks keys are pressed or not
						{
							key = _getche();
							ASCIIValue = key;
							// Statements process user's input
							if (ASCIIValue == 27) break; // Exit infinite loop when ESC key (ASCII value is 27) is pressed
							InputProcess();
						}

						// Statement checks whether a new tetromino should be generated
						if (NewTetromino && !Pause)
						{
							tetrominoLocX = Random(16) + 2;
							tetrominoLocY = 1;
							colour = Random(5) + 1;
							CurrentState = NextPiece;
							NextPiece = Random(18);
							Score += CheckFullRow() * 5;
							NewTetromino = false;

							ArrayDebug();
							GotoXY(0, 0);
							khung();
							Refresh();

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

							//Statement increases level
							if (Score % 10 == 0 && Score > 0 && fullrow)
							{
								Level++;
								FallingSpeed -= 20;
							}

						}
		
						// Statement controls the dropping speed of tetrominoes
						// The bigger the value, the slower the tetrominoes will drop
						if (DelayTime == FallingSpeed && !Pause)
						{
							tetrominoLocY++;
							DelayTime = 0;
			
							Refresh();
						}
						else if (!Pause) DelayTime++;

						//Statement ends the current game
						for (int i = 1; i <= 20; i++) 
							if (tetris[i][2] != 0)
							{
								ArrayReset();
								PrintArray(1, 1);
								Score = 0;
								Level = 1;
								NextPiece = Random(18);
								NewTetromino = true;
							}

						GotoXY(13, 22); // Move console cursor to "Key pressed: " position
					}
					
					system("cls");
					khung();
					GotoXY(7,6);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
					cout << "New game";
					GotoXY(7,9);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
					cout << "Help";
					GotoXY(7,12);
					cout << "Credit";
					GotoXY(7,15);
					cout << "Exit";
					continue;
				}
				continue;
            }
            if(dem == 2)
            {
                khungmenu2(); //highlight chữ Help
                if(ASCIIValue == 13) help(); // nhảy vô giao diện help
         //       if(ASCIIValue == 27) disable == false; //thoát giao diện help
            }
            if(dem == 3)
            {
                khungmenu3(); //highlight chữ Credit
                if(ASCIIValue == 13) credit(); //nhảy vô giao diện credit
          //      if(ASCIIValue == 27) disable == false; //thoát giao diện credit
            }
            if(dem == 4)
            {
                khungmenu4(); //highlight chữ Exit
                if(ASCIIValue == 13) break; //thoát khỏi game
            }
        }
    }

	//cin.get();
}