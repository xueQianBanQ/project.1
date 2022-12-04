#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu(void)
{
	printf("***************************\n");
	printf("*****1.add      2.del******\n");
	printf("*****3.search   4.modify***\n");
	printf("*****5.show     6.sort*****\n");
	printf("********  0.exit  *********\n");
	printf("***************************\n");
}
int main()
{
	int input = 0;
	struct contact con;//通讯录   里面有1000个位置和size
	//初始化通讯录
	IniteContact(&con);
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("退出\n");
			break;
		case ADD:
			//增加通讯录
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			//展现通讯录
			ShowContact(&con);
			break;
		case SORT:
			break;
		default:
			printf("输入错误\n");
		}
	} while (input);
	return 0;
}