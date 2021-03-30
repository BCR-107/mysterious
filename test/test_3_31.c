#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//ѭ������ - ��-ɾ-��-��

typedef int DataType;
typedef struct DNode
{
	DataType data;
	struct DNode *prior, *next;
}DLinkList;
DLinkList* AddDLinkList(DLinkList* head)
{
	assert(head != NULL);
	DLinkList* cur = (DLinkList*)malloc(sizeof(DLinkList));
	scanf("%d", &cur->data);
	cur->next = head->next;
	head->next = cur;
	cur->prior = head;
	cur->next->prior = cur;
	head = cur;
	return head;
}
DLinkList* FindLinkList(DLinkList* head, int x)//��
{
	assert(head != NULL);
	if (head->next == head)
	{
		printf("����Ϊ��\n");
		return 0;
	}
	DLinkList* p = head->next->next;
	while (p != head->next)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->next;
	}
	return 0;
}
DLinkList* DelDLinkList(DLinkList* head)//ɾ
{
	assert(head != NULL);
	printf("������ɾ��Ԫ��\n");
	DataType x = 0;
	scanf("%d", &x);
	DLinkList* p = FindLinkList(head, x);//��
	if (p == 0)
	{
		printf("ɾ��Ԫ�ز�����\n");
		return 0;
	}
	if (p == head)
	{
		head->prior->next = head->next;
		head->next->prior = head->prior;
		return head->prior;
	}
	else
	{
		p->next->prior = p->prior;
		p->prior->next = p->next;
		return head;
	}
	free(p);
}
void Modify(DLinkList* head)//�޸�
{
	assert(head != NULL);
	printf("�������޸�Ԫ��\n");
	DataType x = 0;
	scanf("%d", &x);
	DLinkList* p = FindLinkList(head, x);//��
	if (p == NULL)
	{
		printf("�޸�Ԫ�ز�����\n");
		return;
	}
	printf("������������\n");
	scanf("%d", &p->data);
}
void Print(DLinkList* head)
{
	assert(head != NULL);
	DLinkList* p = head->next->next;//ͷԪ��
	if (head->next == head)
	{
		printf("empty list");
	}
	while (p != head->next)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	putchar('\n');
}
void DestroyDLinkList(DLinkList* head)
{
	assert(head != NULL);
	if (head->next == head)
	{
		printf("empty list\n");
		return;
	}
	DLinkList* p = head->next->next;
	while (head->next != head)
	{
		if (p == head)
		{
			head = head->next;
			head->next = head;
			head->prior = head;
		}
		else
		{
			p->next->prior = p->prior;
			p->prior->next = p->next;
		}
		free(p);
		p = head->next->next;
	}
	if (head->next == head)
	{
		printf("free success\n");
	}
}
DLinkList* test0(DLinkList* head)
{
	head = AddDLinkList(head);
	head = AddDLinkList(head);
	head = AddDLinkList(head);
	head = AddDLinkList(head);
	Print(head);
	return head;
}
void test1(DLinkList* head)
{
	printf("���������Ԫ��\n");
	DataType x = 0;
	scanf("%d", &x);
	DLinkList* p = FindLinkList(head, x);//��
	if (p == NULL)
	{
		printf("����Ԫ�ز�����\n");
		return;
	}
	printf("�ҵ�%d\n", p->data);
}
DLinkList* test2(DLinkList* head)
{
	head = DelDLinkList(head);//ɾ
	Print(head);
	return head;
}
void test3(DLinkList* head)
{
	Modify(head);//�޸�
	Print(head);
}
int main()
{
	DLinkList* head = (DLinkList*)malloc(sizeof(DLinkList));
	head->prior = head;
	head->next = head;

	head = test0(head);//��
	test1(head);//��
	head = test2(head);//ɾ
	test3(head);//��
	DestroyDLinkList(head);//��������

	return 0;
}