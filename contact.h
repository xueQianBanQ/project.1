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

//通讯录结构体的设置
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

//函数的声明

void IniteContact(struct contact* ps);//初始化通讯录
void AddContact(struct contact* ps);//增加成员的信息
void ShowContact(const struct contact* ps);//打印通讯录的信息
//删除信息
void DelContact(struct contact* ps);

//查找信息
void SearchContact(const struct contact* ps);

//修改信息
void ModifyContact(struct contact* ps);