#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
int i, j;
void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}


void Display(char board[ROWS][COLS], int row, int col)
{
	for (i = 1; i <= row; i++)
	{
		if (1 == i)
		{
			printf("  ");
			for (j = 1; j <= col; j++)
			{
				printf("%d ", j);
			}
			printf("\n");
		}
		for(j = 1; j <= col; j++)
		{
			if (1 == j)
			{
				printf("%d ", i);
			}
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}



void Landmine(char board[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		i = rand() % row + 1;//1-9
		j = rand() % col + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			count--;
		}
	}
}
//玩家确定位置周围雷的个数 1 = '1' - '0';
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';

}

//空白的设置
void blank_board(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL && show[x][y] != ' ')
	{
		int count = get_mine_count(mine, x, y);
		show[x][y] = count + '0';
		if ('0' == show[x][y])
		{
			show[x][y] = ' ';
			blank_board(mine, show, x - 1, y);
			blank_board(mine, show, x + 1, y);
			blank_board(mine, show, x, y + 1);
			blank_board(mine, show, x, y - 1);
		}
	}
	
}

//判断是否赢
int Is_win(char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	if (count == COUNT)
		return 0;
	else
		return 1;
}


void Sweep(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	x = 0;
	y = 0;
	int win = 1;
	while (win)
	{
		printf("请输入，先行后列，中间用空格隔开:>");
		scanf("%d%d", &x, &y);//1-9
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '0')
			{
				//点到0，实现空白
				blank_board(mine, show, x, y);
				Display(show, ROW, COL);
				win = Is_win(show, ROW, COL);
			}
			else
			{
				printf("你扫到雷了，你输了。\n");
				Display(mine, ROW, COL);
				break;
			}
		}
		else
		{
			printf("输入的位置超出范围了。\n");
		}
	}
	if (0 == win)
	{
		printf("恭喜！你赢了。\n");
		Display(mine, ROW, COL);
	}
}