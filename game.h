#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
//����
void blank_board(char board[ROW][COL], int row, int col);
void struct_board(char board[ROW][COL], int row, int col);
void Display_board(char board[ROW][COL], int row, int col);
void computer_board(char board[ROW][COL], int row, int col);
/*
����Ҫ���ִ�
���Ӯ��*��
����Ӯ��#��
ƽ�֡�@��
����������

*/
char iswin(char board[ROW][COL], int row, int col);