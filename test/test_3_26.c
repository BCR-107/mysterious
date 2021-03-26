#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
//凶手 A:不是我  B:是C  C: 是D  D:C在说谎   3人真一人假
//int main()
//{
//	int killer = 0;
//	for (killer = 'a'; killer < 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//		{
//			printf("killer = %c\n", killer);
//		}
//	}
//	return 0;
//}

//赛马问题:有36匹马,6个跑道,没有计时器,请赛马确定36匹马中的前三名
//最少比赛几次   8

//烧香问题:有一种香材质不均匀,每一根香燃烧完恰好一小时
//给2根香确定一个15分钟的时间段
//第一根两端都点着，第二根点着一端，第一根烧完再点第二根另一端

//调奇数到偶数前且相对顺序不变 exchange odd number and even number
//void ExchangeNumber(int arr[],int sz)
//{
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			j = i + 1;
//			while (j < sz)
//			{
//				if (arr[j] % 2 != 0)
//				{
//					tmp = arr[i];
//					arr[i] = arr[j];
//					arr[j] = tmp;
//				}
//				j++;
//			}
//		}		
//	}
//}
//int* ExchangeNumber(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	int* p = (int*)malloc(sz*sizeof(int));
//	int*q = p;
//
//		for (i = 0; i < sz; i++)
//		{
//
//			if (arr[i] % 2 != 0)
//			{
//				*(p + j) = arr[i];
//				j++;
//			}
//		}
//		for (i = 0; i < sz; i++)
//		{
//
//			if (arr[i] % 2 == 0)
//			{
//				*(p + j) = arr[i];
//				j++;
//			}
//		}
//		return q;
//
//}
//void Print(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	Print(ExchangeNumber(arr, sz), sz);
//
//	return 0;
//}

//在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 
//如果没有则返回 -1（需要区分大小写）.（从0开始计数）

//int Fin(char arr[],int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz;i++)
//	{
//		int count = 0;
//		for (j = i + 1; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				count++;
//			}
//		}
//		if (count == 0)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//void Print(int t)
//{
//	printf("%d\n", t);
//}
//int main()
//{
//	char arr[] = { "abccdfdhgjdhasdbdhcbc" };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	Print(Fin(arr, sz));
//
//	return 0;
//}

