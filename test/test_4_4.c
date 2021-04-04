#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//二叉树
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
		q->data[q->rear] = s;//入队
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
					q->data[q->front]->lchild = s;//左孩子
				}
				else
				{
					q->data[q->front]->rchild = s;//右孩子
				}
			}
			if (q->rear % 2 == 1)
			{
				q->front++;//双亲出队
			}
		}
		ch = getchar();
	}
	return root;
}
//void PreOrder(BiTree* T)//前序
//{
//	if (T)
//	{
//		printf("%c ", T->data);
//		PreOrder(T->lchild);
//		PreOrder(T->rchild);
//	}
//}
void InOrder(BiTree* T)//中序
{
	if (T)
	{
		InOrder(T->lchild);
		printf("%c ", T->data);
		InOrder(T->rchild);
	}
}
//void PostOrder(BiTree* T)//后序
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
	BiTree* T = createTree();//创建

	//PreOrder(T);//前序
	InOrder(T);//中序
	//PostOrder(T);//后序

	return 0;
}

