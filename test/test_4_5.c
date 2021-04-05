#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//¿®∫≈∆•≈‰
//#define MAXSIZE 1024
//typedef char DataType;
//typedef struct
//{
//	DataType data[MAXSIZE];
//	int top;
//}SeqStack;
//SeqStack* initStack()
//{
//	SeqStack* S = (SeqStack*)malloc(sizeof(SeqStack));
//	S->top = -1;
//	return S;
//}
//int push(SeqStack* S, DataType c)
//{
//	if (S->top == MAXSIZE - 1)
//	{
//		printf("overflow\n");
//		return 0;
//	}
//	S->top++;
//	S->data[S->top] = c;
//	return 1;
//}
//void pop(SeqStack* S)
//{
//	if (S->top == -1)
//	{
//		printf("empty stack\n");
//	}
//	S->top--;
//}
//DataType top(SeqStack* S)
//{
//	return S->data[S->top];
//}
//int empty(SeqStack* S)
//{
//	if (S->top == -1)
//		return 0;
//	else
//		return 1;
//}
//int main()
//{
//	SeqStack* S = initStack();
//	char c = 0;
//	int tmp = 0;
//	int n = 0;
//	scanf("%c", &c);
//	while (c != '#')
//	{
//		push(S, c);
//		if (S->data[S->top] != '(' && S->data[S->top] != ')')
//		{
//			S->data[S->top] = 0;
//		}
//		if (c == ')' && empty(S))
//		{
//			tmp = S->top;
//			S->top--;
//			while (empty(S))
//			{
//				if (S->data[S->top] == '(')
//				{
//					printf("%d %d\n", tmp + 1, S->top + 1);
//					S->data[S->top] = 0;
//					S->data[tmp] = 0;
//					S->top = tmp;
//					break;
//				}
//				S->top--;
//			}
//		}
//		if (!empty(S))
//		{
//			S->top = tmp;
//		}
//		scanf("%c", &c);
//	}
//	while (empty(S))
//	{
//		if (S->data[S->top] != 0)
//		{
//			printf("%d ", S->top + 1);
//			n = 1;
//		}
//		S->top--;
//	}
//	if (n)
//	{
//		printf("Œ¥∆•≈‰\n");
//	}
//	return 0;
//}