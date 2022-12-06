// TECON GAME (Tetris clone) BY THUAN HAI CONG HO & TRANG KIEU HA
// Well's size (Matrix size) 20 x 20
// 100% ASCII interface

#pragma once

void khung(); // Draws the boxes
void xoakhungbenphai(); // Wipes the right box
void welcome(); // Draws welcome screen
void khungmenu(); // Draws menu
void khungmenu1(); // Draws menu with the word "NEW GAME" highlighted
void khungmenu2(); // Draws menu with the word "HELP" highlighted
void khungmenu3(); // Draws menu with the word "CREDIT" highlighted
void khungmenu4(); // Draws menu with the word "EXIT" highlighted
void help(); //hàm để chọn các trang help
void credit(); // hàm viết những người lập trình

// UNDEFINED AND UNUSED FUNCTIONS

/*
void gameover(); // Function that draws game over screen
void first_ui(int);
void second_ui(int);
void gameover(int);
*/