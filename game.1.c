#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void game()
{
	char board[ROW][COL] = { 0 };
	blank_board(board, ROW, COL);//清空里面的符号用空格。
	struct_board(board, ROW, COL);//建构棋盘框架
	//下棋
	while (1)
	{
		char ret = 0;
		//玩家下棋
		Display_board(board, ROW, COL);
		struct_board(board, ROW, COL);//再重新建构棋盘框架
		ret = iswin(board, ROW, COL);//判断玩家是否赢
		//电脑下棋
		computer_board(board, ROW, COL);
		struct_board(board, ROW, COL);
		ret = iswin(board, ROW, COL);//判断电脑是否赢
		//判断
		if (ret == '*')
		{
			printf("你赢了。\n");
			break;
		}
		else if (ret == '#')
		{
			printf("不好意思，你输了！\n");
			break;
		}
		else if (ret == '@')
		{
			printf("平局。\n");
			break;
		}
		else
			printf("下一回合。\n");
	}
	
}
void menu()
{
	printf("***************************\n");
	printf("****  1.start  0.exit  ****\n");
	printf("***************************\n");
}
void text()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("您输入错误，请重新输入。\n");
			break;
		}
	} while (input);
}
int main()
{
	text();
	printf("退出游戏。\n");
	return 0;
}