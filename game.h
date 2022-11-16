#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
//声明
void blank_board(char board[ROW][COL], int row, int col);
void struct_board(char board[ROW][COL], int row, int col);
void Display_board(char board[ROW][COL], int row, int col);
void computer_board(char board[ROW][COL], int row, int col);
/*
我想要四种答案
玩家赢‘*’
电脑赢‘#’
平局‘@’
继续‘！’

*/
char iswin(char board[ROW][COL], int row, int col);