#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
//µ¥Á´±í
//typedef struct List
//{
//	int data;
//	struct List* next;
//}node;
//void AddLinkList(node* head)
//{
//	int n = 0;
//	scanf("%d", &n);
//	node* rear = head;
//	while (n > 0)
//	{
//		node* newnode = (node*)malloc(sizeof(node));
//		newnode->next = NULL;
//		scanf("%d", &newnode->data);
//		rear->next = newnode;
//		rear = newnode;
//		n--;
//	}
//}
//void DelLinkList(node* head)
//{
//	node* p = head->next;
//	while (p != NULL)
//	{
//		head->next = p->next;
//		free(p);
//		p = head->next;
//	}
//	if (p == NULL)
//	{
//		printf("free success");
//	}
//}
//void PrintList(node* head)
//{
//	node* p = head->next;
//	if (p == NULL)
//	{
//		printf("empty list");
//		return;
//	}
//	while (p != NULL)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//int main()
//{
//	node* head = (node*)malloc(sizeof(node));
//    head->next=NULL;
//
//	AddLinkList(head);
//	PrintList(head);
//	putchar('\n');
//	DelLinkList(head);
//
//	return 0;
//}

//Ë«Ñ­»·
//typedef int DataType;
//typedef struct DNode
//{
//	DataType data;
//	struct DNode *prior, *next;
//}DLinkList;
//void AddDLinkList(DLinkList* head)
//{
//	DLinkList* rear = head;
//	int n = 0;
//	scanf("%d", &n);
//	while (n > 0)
//	{
//		DLinkList* cur = (DLinkList*)malloc(sizeof(DLinkList));
//		scanf("%d", &cur->data);
//		rear->next = cur;
//		cur->prior = rear;
//
//		head->prior = cur;
//		cur->next = head;
//		rear = cur;
//
//		n--;
//	}
//}
//void Print(DLinkList* head)
//{
//	DLinkList* p = head->next;
//	if (p == head)
//	{
//		printf("empty list");
//	}
//	while (p != head)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//}
//void DestroyDLinkList(DLinkList* head)
//{
//	DLinkList* p = head->next;
//	if (p == head)
//	{
//		printf("empty list\n");
//		return;
//	}
//	while (p != head)
//	{
//		head->next = p->next;
//		free(p);
//		p = head->next;
//	}
//	if (p == head)
//	{
//		printf("free success\n");
//	}
//}
//int main()
//{
//	DLinkList* head = (DLinkList*)malloc(sizeof(DLinkList));
//	head->prior = head;
//	head->next = head;
//
//	AddDLinkList(head);
//	Print(head);
//	putchar('\n');
//	DestroyDLinkList(head);
//
//	return 0;
//}