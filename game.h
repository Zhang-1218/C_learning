#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define ROW 9
#define COL 9


#define ROWS (ROW+2)
#define COLS (COL+2)


#define EASY 10
#define HARD 80


void Init_Array(char Array[ROWS][COLS], int row, int col, char set);
void Display(char Array[ROWS][COLS], int row, int col);
void Set_Mine(char Array[ROWS][COLS], int MINE);
void Sweep_Mine(char Array[ROWS][COLS], char show[ROWS][COLS], int row, int col,int MINE);
void Move_mine(char Array[ROWS][COLS], int x, int y);
void Get_Mine_Count(char Array[ROWS][COLS], char show[ROWS][COLS], int x, int y);


#endif //__GAME_H__ 