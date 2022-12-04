 #pragma once

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

#include <stdio.h>
#include <string.h>

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

//ͨѶ¼�ṹ�������
struct PeoInfo
{
	char name[MAX_NAME];
	int age; 
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct contact
{
	struct PeoInfo data[MAX];
	int size;
};

//����������

void IniteContact(struct contact* ps);//��ʼ��ͨѶ¼
void AddContact(struct contact* ps);//���ӳ�Ա����Ϣ
void ShowContact(const struct contact* ps);//��ӡͨѶ¼����Ϣ
//ɾ����Ϣ
void DelContact(struct contact* ps);

//������Ϣ
void SearchContact(const struct contact* ps);

//�޸���Ϣ
void ModifyContact(struct contact* ps);