#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//反转链表
typedef struct List
{
	int data;
	struct List* next;
}L;
void CreateList(L* head)
{
	int n = 0;
	printf("请输入链表长度>;");
	scanf("%d", &n);
	L* phead = head;
	while (n--)
	{
		L* cur = (L*)malloc(sizeof(L));
		cur->next = NULL;
		scanf("%d", &(cur->data));
		phead->next = cur;
		phead = cur;
	}
}
//void ReverseList(L* head)
//{
//	L* p1;
//	L* p2;
//	p1 = head->next;
//	head->next = NULL;
//	while (p1 != NULL)
//	{
//		p2 = p1->next;
//		p1->next = head->next;
//		head->next = p1;
//		p1 = p2;
//	}
//}
void ReverseList(L* head)
{
	L* p1;
	L* p2;
	p1 = head->next;
	head->next = NULL;
	while (p1 != NULL)
	{
		p2 = p1;
		p1 = p1->next;
		p2->next = head->next;
		head->next = p2;
	}
}
void PrintList(L* head)
{
	L* cur = head->next;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	L* head = (L*)malloc(sizeof(L));
	head->next = NULL;

	CreateList(head);
	PrintList(head);

	ReverseList(head);
	PrintList(head);

	return 0;
}