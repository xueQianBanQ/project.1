#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//寻找通讯录的名字，查找成功返回下标， 没有返回-1
int  FindByName(const struct contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void ShowList(const struct contact* ps, int tag)
{
	printf("%-20s\t%-5s\t%-3d\t%-12s\t%-30s\n",
		ps->data[tag].name,
		ps->data[tag].sex,
		ps->data[tag].age,
		ps->data[tag].tele,
		ps->data[tag].addr);
}


void IniteContact(struct contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void AddContact(struct contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入电话:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->size].addr);
	}
	ps->size++;
}

void ShowContact(const struct contact* ps)
{
	printf("%-20s\t%-5s\t%-3s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		ShowList(ps, i);
	}
}

void DelContact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除的姓名:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("你要删除的人不存在\n");
	}
	else
	{
		int i = 0;
		for (i = pos; i < ps->size - 1; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
		ps->size--;
	}
}

void SearchContact(const struct contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要寻找的姓名:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("你要删除的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-3s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
		ShowList(ps, pos);
	}
}

void ModifyContact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改的姓名:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("你要修改的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-3s\t%-12s\t%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
		ShowList(ps, pos);
		printf("请修改:>\n");
		printf("请输入姓名:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[pos].addr);
	}


}