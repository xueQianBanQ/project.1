#pragma once
#define ROW 9//扫雷面积的行数
#define COL 9//扫雷面积的列数
#define ROWS ROW + 2
#define COLS COL + 2

#define COUNT 10//地雷个数

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Initboard(char board[ROWS][COLS], int rows, int cols, char set);
void Display(char board[ROWS][COLS], int row, int col);
void Landmine(char board[ROWS][COLS], int row, int col);
void Sweep(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col);
void blank_board(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
