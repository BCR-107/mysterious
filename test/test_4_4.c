#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//������
#define MAXSIZE 100
typedef char DataType;
typedef struct Node
{
	DataType data;
	struct Node *lchild, *rchild;
}BiTree;
typedef struct
{
	BiTree* data[MAXSIZE];
	int front, rear;
}SeQueue;
BiTree* createTree()
{
	SeQueue Q, *q = &Q;
	BiTree *root, *s;
	root = NULL;
	q->front = 1;
	q->rear = 0;
	char ch = 0;
	s = NULL;
	ch = getchar();
	while (ch != '@')
	{
		s = NULL;
		if (ch != '#')
		{
			s = (BiTree*)malloc(sizeof(BiTree));
			s->data = ch;
			s->lchild = NULL;
			s->rchild = NULL;
		}
		q->rear++;
		q->data[q->rear] = s;//���
		if (root == NULL)
		{
			root = s;
		}
		else
		{
			if (q->data[q->front] != NULL)
			{
				if (q->rear % 2 == 0)
				{
					q->data[q->front]->lchild = s;//����
				}
				else
				{
					q->data[q->front]->rchild = s;//�Һ���
				}
			}
			if (q->rear % 2 == 1)
			{
				q->front++;//˫�׳���
			}
		}
		ch = getchar();
	}
	return root;
}
//void PreOrder(BiTree* T)//ǰ��
//{
//	if (T)
//	{
//		printf("%c ", T->data);
//		PreOrder(T->lchild);
//		PreOrder(T->rchild);
//	}
//}
void InOrder(BiTree* T)//����
{
	if (T)
	{
		InOrder(T->lchild);
		printf("%c ", T->data);
		InOrder(T->rchild);
	}
}
//void PostOrder(BiTree* T)//����
//{
//	if (T)
//	{
//		PostOrder(T->lchild);
//		PostOrder(T->rchild);
//		printf("%c ", T->data);
//	}
//}
int main()
{
	BiTree* T = createTree();//����

	//PreOrder(T);//ǰ��
	InOrder(T);//����
	//PostOrder(T);//����

	return 0;
}

