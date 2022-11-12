#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void game()//开始游戏
{
	char mineboard[ROWS][COLS] = { 0 };
	char showboard[ROWS][COLS] = { 0 };
	//初始化模板
	Initboard(mineboard, ROWS, COLS, '0');
	Initboard(showboard, ROWS, COLS, '*');
	//打印模板
	Display(showboard, ROW, COL);
	//Display(mineboard, ROW, COL);
	//布雷
	Landmine(mineboard, ROW, COL);
	//Display(mineboard, ROW, COL);//答案
	//扫雷
	Sweep(mineboard, showboard, ROW, COL);
}
void menu()//菜单
{
	printf("*******************************\n");
	printf("*********  1.play    **********\n");
	printf("*********  0.exit  ************\n");
	printf("*******************************\n");
}
void test()//程序开始
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏.\n");
			break;
		default:
			printf("输入错误，请重新输入。\n");
			break;

		}
	} while (input);
}
int main()
{
	test();
	return 0;
}