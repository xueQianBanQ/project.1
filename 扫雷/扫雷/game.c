#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void game()//��ʼ��Ϸ
{
	char mineboard[ROWS][COLS] = { 0 };
	char showboard[ROWS][COLS] = { 0 };
	//��ʼ��ģ��
	Initboard(mineboard, ROWS, COLS, '0');
	Initboard(showboard, ROWS, COLS, '*');
	//��ӡģ��
	Display(showboard, ROW, COL);
	//Display(mineboard, ROW, COL);
	//����
	Landmine(mineboard, ROW, COL);
	//Display(mineboard, ROW, COL);//��
	//ɨ��
	Sweep(mineboard, showboard, ROW, COL);
}
void menu()//�˵�
{
	printf("*******************************\n");
	printf("*********  1.play    **********\n");
	printf("*********  0.exit  ************\n");
	printf("*******************************\n");
}
void test()//����ʼ
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ.\n");
			break;
		default:
			printf("����������������롣\n");
			break;

		}
	} while (input);
}
int main()
{
	test();
	return 0;
}