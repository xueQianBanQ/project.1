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
	struct contact con;//ͨѶ¼   ������1000��λ�ú�size
	//��ʼ��ͨѶ¼
	IniteContact(&con);
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("�˳�\n");
			break;
		case ADD:
			//����ͨѶ¼
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
			//չ��ͨѶ¼
			ShowContact(&con);
			break;
		case SORT:
			break;
		default:
			printf("�������\n");
		}
	} while (input);
	return 0;
}