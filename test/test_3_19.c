#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

////«‡Õ‹Ã¯Ã®Ω◊£®µ›πÈ£©
//int FrogStep1(int N)
//{
//	if (N == 1)
//	{
//		return 1;
//	}
//	else if (N == 2)
//	{
//		return 2;
//	}
//	else
//	{
//		return FrogStep1(N - 1) + FrogStep1(N - 2);
//	}
//}
////—≠ª∑
//int FrogStep2(int N)
//{
//	int a = 1;
//	int b = 2;
//	if (N == 1)
//	{
//		return 1;
//	}
//	else if (N == 2)
//	{
//		return b;
//	}
//	else
//	{
//		int tmp = 0;
//		int i = 0;
//		for (i = 0; i < N - 2; i++)
//		{
//			tmp = b;
//			b = a + b;
//			a = tmp;
//		}
//		return b;
//	}
//
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret1 = 0;
//	int ret2 = 0;
//
//	ret1 = FrogStep1(n);
//	ret2 = FrogStep2(n);
//
//	printf("%d\n", ret1);
//	printf("%d\n", ret2);
//
//	return 0;
//}

////—Ó œæÿ’Û
//#include<assert.h>
//#include<string.h>
//char* Search(int(*ps)[4], int rows, int col)
//{
//	int n = 0;
//	scanf("%d", &n);
//	assert(ps != NULL);
//	int row = 0;
//	col = col - 1;
//	while (row < rows && col >= 0)
//	{
//		if (n == *(*(ps + row) + col))
//		{
//			return "ture";
//		}
//		else if (n < *(*(ps + row) + col))
//		{
//			col--;
//		}
//		else
//		{
//			row++;
//		}
//	}
//	return "false";
//}
//
//int main()
//{
//	int arr[4][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
//	const char* ps = Search(arr, 4, 4);
//	printf("%s\n", ps);
//
//	return 0;
//}

