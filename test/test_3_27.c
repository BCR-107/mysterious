#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
//赛马问题 - house race
//A：B第二，我第三
//B：我第二，E第四
//C：我第一，D第二
//D：C最后，我第三
//E：我第四，A第一
//没人都说对一半，确定比赛名次

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if (a*b*c*d*e == 120)
//							printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//
//	}
//	return 0;
//}

//求1+2+3+...+n，要求不能使用乘除法
//for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
//int Sum_Solution(int n)
//{
//	int ret = n;
//	n &&( ret += Add(n - 1));
//
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Sum_Solution(n);
//	printf("%d\n", ret);
//
//	return 0;
//}

//左旋字符串中K个字符
//   1
//void ReverseChar(char arr[], int len)
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	char tmp = 0;
//	while (n > 0)
//	{
//		i = 0;
//		tmp = arr[i];
//		while (i < len - 1)
//		{
//			arr[i] = arr[i + 1];
//			i++;
//		}
//		arr[len - 1] = tmp;
//		n--;
//	}
//}
//void Print(char arr[], int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//}
//   2
//void Reverse(char *left, char *right)
//{
//	assert(left);
//	assert(right);
//	while (left<right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void ReverseChar(char *arr, int len)
//{
//	assert(arr);
//	int n = 0;
//	scanf("%d", &n);
//	assert(n <= len);
//	//revolve left
//	Reverse(arr, arr + n - 1);
//	//revolve right
//	Reverse(arr + n, arr + len - 1);
//	//revolve whole
//	Reverse(arr, arr + len - 1);
//}
//void Print(char arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//}
//int main()
//{
//	char arr[] = { "abcdef" };
//	int len = strlen(arr);
//
//	ReverseChar(arr, len);
//	Print(arr, len);
//
//	return 0;
//}
//   3
void Reverse(char *left, char *right)
{
	assert(left);
	assert(right);
	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
char* ReverseChar(char *arr, int len)
{
	assert(arr);
	strncat(arr, arr,len);
	int n = 0;
	scanf("%d", &n);
	assert(n <= len);
	*(arr + len + n ) = '\0';
	return arr + n;
}
void Print(char arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%c ", arr[i]);
	}
}
int main()
{
	char arr[30] = { "abcdef" };
	int len = strlen(arr);

	Print(ReverseChar(arr, len), len);

	return 0;
}

