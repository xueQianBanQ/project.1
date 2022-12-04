#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//Ѱ��ͨѶ¼�����֣����ҳɹ������±꣬ û�з���-1
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
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ps->size].name);
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->size].sex);
		printf("����������:>");
		scanf("%d", &(ps->data[ps->size].age));
		printf("������绰:>");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[ps->size].addr);
	}
	ps->size++;
}

void ShowContact(const struct contact* ps)
{
	printf("%-20s\t%-5s\t%-3s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		ShowList(ps, i);
	}
}

void DelContact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ��������:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("��Ҫɾ�����˲�����\n");
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
	printf("������ҪѰ�ҵ�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("��Ҫɾ�����˲�����\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-3s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		ShowList(ps, pos);
	}
}

void ModifyContact(struct contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (-1 == pos)
	{
		printf("��Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-3s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		ShowList(ps, pos);
		printf("���޸�:>\n");
		printf("����������:>");
		scanf("%s", ps->data[pos].name);
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("����������:>");
		scanf("%d", &(ps->data[pos].age));
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[pos].addr);
	}


}