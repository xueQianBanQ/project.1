#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void game()
{
	char board[ROW][COL] = { 0 };
	blank_board(board, ROW, COL);//�������ķ����ÿո�
	struct_board(board, ROW, COL);//�������̿��
	//����
	while (1)
	{
		char ret = 0;
		//�������
		Display_board(board, ROW, COL);
		struct_board(board, ROW, COL);//�����½������̿��
		ret = iswin(board, ROW, COL);//�ж�����Ƿ�Ӯ
		//��������
		computer_board(board, ROW, COL);
		struct_board(board, ROW, COL);
		ret = iswin(board, ROW, COL);//�жϵ����Ƿ�Ӯ
		//�ж�
		if (ret == '*')
		{
			printf("��Ӯ�ˡ�\n");
			break;
		}
		else if (ret == '#')
		{
			printf("������˼�������ˣ�\n");
			break;
		}
		else if (ret == '@')
		{
			printf("ƽ�֡�\n");
			break;
		}
		else
			printf("��һ�غϡ�\n");
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("������������������롣\n");
			break;
		}
	} while (input);
}
int main()
{
	text();
	printf("�˳���Ϸ��\n");
	return 0;
}