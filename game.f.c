#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
int i = 0, j = 0;
void blank_board(char board[ROW][COL], int row, int col)
{
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


void struct_board(char board[ROW][COL], int row, int col)
{
	for (i = 0; i < row; i++)
	{
		if (i == 0)
			printf("  1   2   3 \n");
		for (j = 0; j < col; j++)
		{
			if (j == 0)
				printf("%d", i + 1);
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			    printf("|");
		}
		printf("\n");
		if (i < row - 1)
		for (j = 0; j < col; j++)
		{ 
			if (j == 0)
				printf(" ");
			printf("---");
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
	}
}
void Display_board(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("输入您想下的坐标,先行后列，中间需要空格隔开:");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("输入错误，此坐标已有棋子。请重新输入。\n");
		}
		else
			printf("您输入的坐标超出范围。\n");
		
	}
}
void computer_board(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("电脑开始下棋。\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	
}
int isFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}


char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//横三行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	//列三行
		else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			return board[0][i];
	}
		//斜着的判断
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		    return board[1][1];
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		    return board[0][2];
		if (1 == isFull(board, ROW, COL))
			return '@';
		return '!';
	}

	
	

