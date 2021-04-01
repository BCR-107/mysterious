#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
//选择排序

//typedef int DataType;
//void Selsort(DataType arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	DataType t = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		tmp = i;
//		for (j = i + 1; j < sz; j++)
//		{
//			if (arr[j] < arr[tmp])
//			{
//				tmp = j;
//			}
//		}
//		if (tmp != i)
//		{
//			t = arr[i];
//			arr[i] = arr[tmp];
//			arr[tmp] = t;
//		}
//	}
//}
//void Print(DataType arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	DataType arr[10] = { 1, 4, 2, 6, 5, 3, 7, 9, 8, 10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	Selsort(arr, sz);
//	Print(arr, sz);
//	return 0;
//}

//堆排序

//#define N 10
//typedef int RecType;
//typedef struct
//{
//	int key;
//	DataType other;
//}RecType;
//void Print(RecType R[], int n);
//
//void helpSift(RecType R[], int i, int n)// i - 根节点  n - 待排序元素
//{
//	RecType rc = R[i];
//	int j = 2 * i;
//	while (j <= n)
//	{
//		if (j < n && R[j] < R[j + 1])//j为较大值
//		{
//			j = j + 1;
//		}
//		if (rc > R[j])
//		{
//			break;
//		}
//		R[i] = R[j];
//		i = j;
//		j = j * 2;
//	}
//	R[i] = rc;
//}
//Helpsort(RecType R[], int n)
//{
//	int i = 0;
//	RecType x = 0;
//	for (i = n / 2; i >= 1; i--)//建堆
//	{
//		helpSift(R, i, n);
//	}
//	for (i = n; i > 1; i--)//重构堆
//	{
//		x = R[i];
//		R[i] = R[1];
//		R[1] = x;
//		helpSift(R, 1, i - 1);
//	}
//}
//void Print(RecType R[], int n)
//{
//	int i = 1;
//	for (; i <= n; i++)
//	{
//		printf("%d ", R[i]);
//	}
//}
//int main()
//{
//	RecType R[9] = { 0, 49, 38, 65, 97, 76, 13, 27, 49 };
//
//	int n = sizeof(R) / sizeof(R[1]) - 1;
//
//	Helpsort(R, n);
//	Print(R, n);
//
//	return 0;
//}

