#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
//���� A:������  B:��C  C: ��D  D:C��˵��   3����һ�˼�
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

//��������:��36ƥ��,6���ܵ�,û�м�ʱ��,������ȷ��36ƥ���е�ǰ����
//���ٱ�������   8

//��������:��һ������ʲ�����,ÿһ����ȼ����ǡ��һСʱ
//��2����ȷ��һ��15���ӵ�ʱ���
//��һ�����˶����ţ��ڶ�������һ�ˣ���һ�������ٵ�ڶ�����һ��

//��������ż��ǰ�����˳�򲻱� exchange odd number and even number
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

//��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��, 
//���û���򷵻� -1����Ҫ���ִ�Сд��.����0��ʼ������

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

