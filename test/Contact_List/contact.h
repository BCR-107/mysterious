#define _CRT_SECURE_NO_WARNINGS 1

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <errno.h>

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};

typedef struct PeoInfo
{
	char name[MAX_NAME];//名字
	int  age;//年龄
	char sex[MAX_SEX];//性别
	char tele[MAX_TELE];//电话
	char addr[MAX_ADDR];//地址
}PeoInfo;
typedef struct Contact
{
	PeoInfo data;//数据域
	struct Contact * next;//指针域
}Contact;

//声明函数
//增加
void AddContact(Contact *head);
//打印
void ShowContact(Contact *head);
//删除
void DelContact(Contact* head);
//查找
void SearchContact(const Contact* head);
//修改
void ModifyContact(Contact* head);
//保存文件
void SaveContact(Contact* head);
//加载文件中的信息到通讯录
void LoadContact(Contact* ps);
//void DestroyContact(Contact* head);