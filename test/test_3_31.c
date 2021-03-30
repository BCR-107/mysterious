#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//循环链表 - 增-删-改-查

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
DLinkList* FindLinkList(DLinkList* head, int x)//查
{
	assert(head != NULL);
	if (head->next == head)
	{
		printf("链表为空\n");
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
DLinkList* DelDLinkList(DLinkList* head)//删
{
	assert(head != NULL);
	printf("请输入删除元素\n");
	DataType x = 0;
	scanf("%d", &x);
	DLinkList* p = FindLinkList(head, x);//查
	if (p == 0)
	{
		printf("删除元素不存在\n");
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
void Modify(DLinkList* head)//修改
{
	assert(head != NULL);
	printf("请输入修改元素\n");
	DataType x = 0;
	scanf("%d", &x);
	DLinkList* p = FindLinkList(head, x);//查
	if (p == NULL)
	{
		printf("修改元素不存在\n");
		return;
	}
	printf("请输入新数据\n");
	scanf("%d", &p->data);
}
void Print(DLinkList* head)
{
	assert(head != NULL);
	DLinkList* p = head->next->next;//头元素
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
	printf("请输入查找元素\n");
	DataType x = 0;
	scanf("%d", &x);
	DLinkList* p = FindLinkList(head, x);//查
	if (p == NULL)
	{
		printf("查找元素不存在\n");
		return;
	}
	printf("找到%d\n", p->data);
}
DLinkList* test2(DLinkList* head)
{
	head = DelDLinkList(head);//删
	Print(head);
	return head;
}
void test3(DLinkList* head)
{
	Modify(head);//修改
	Print(head);
}
int main()
{
	DLinkList* head = (DLinkList*)malloc(sizeof(DLinkList));
	head->prior = head;
	head->next = head;

	head = test0(head);//增
	test1(head);//查
	head = test2(head);//删
	test3(head);//改
	DestroyDLinkList(head);//销毁链表

	return 0;
}