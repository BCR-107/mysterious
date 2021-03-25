#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//Ë®ÏÉ»¨-daffodil
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10000; i++)
//	{
//		int n = 1;
//		int tmp = i;
//		int sum = 0;
//		while (tmp/=10)
//		{
//			n++;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum +=(int)(pow(tmp % 10, n));
//			tmp /= 10;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//ÆûË®-two empty bottle exchange one soda
//int main()
//{
//	int total = 0;
//	scanf("%d", &total);
//	int sum = total;
//	while (total >= 2)
//	{
//		sum += total / 2;
//		total = total % 2 + total / 2;
//	}
//	printf("%d", sum);
//}