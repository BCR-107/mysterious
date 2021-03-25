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
	char name[MAX_NAME];//����
	int  age;//����
	char sex[MAX_SEX];//�Ա�
	char tele[MAX_TELE];//�绰
	char addr[MAX_ADDR];//��ַ
}PeoInfo;
typedef struct Contact
{
	PeoInfo data;//������
	struct Contact * next;//ָ����
}Contact;

//��������
//����
void AddContact(Contact *head);
//��ӡ
void ShowContact(Contact *head);
//ɾ��
void DelContact(Contact* head);
//����
void SearchContact(const Contact* head);
//�޸�
void ModifyContact(Contact* head);
//�����ļ�
void SaveContact(Contact* head);
//�����ļ��е���Ϣ��ͨѶ¼
void LoadContact(Contact* ps);
//void DestroyContact(Contact* head);