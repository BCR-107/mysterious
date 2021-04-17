#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#define NUM 10
typedef int DataType;

//mergesort
void merge(DataType R[], DataType A[], int u, int v, int t)
{
	int i = 0, j = 0, k = 0;

	for (i = u, j = v + 1, k = u; i <= v&&j <= t; k++)
	{
		if (R[i] < R[j])
		{
			A[k] = R[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
	while (i <= v)
	{
		A[k] = R[i];
		i++, k++;
	}
	while (j <= t)
	{
		A[k] = R[j];
		j++, k++;
	}
}
void mergePass(DataType R[], DataType A[], int len, int n)
{
	int i = 0;
	int p = 0;

	for (; p + 2 * len - 1 < n; p = p + 2 * len)
		merge(R, A, p, p + len - 1, p + 2 * len - 1);
	if (p + len - 1 < n)
		merge(R, A, p, p + len - 1, n - 1);
	else
	for (i = p; i < n; i++)
		A[i] = R[i];
}
void mergesort(DataType R[], int n)
{
	DataType A[NUM] = { 0 };
	int len = 1;

	while (len < NUM)
	{
		mergePass(R, A, len, n);
		len = 2 * len;
		mergePass(A, R, len, n);
		len = 2 * len;
	}
}
void Print(DataType R[])
{
	int i = 0;
	for (; i < NUM; i++)
		printf("%d ", R[i]);
}
int main()
{
	DataType R[NUM] = { 45, 53, 18, 36, 73, 45, 93, 15, 30, 48 };

	mergesort(R, NUM);
	Print(R);

	return 0;
}