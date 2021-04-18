#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>
#include<stdlib.h>

void Countingsort(int arr[], int n)
{
	int max = arr[0];
	int min = arr[0];
	int i = 0;
	for (; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i]>max)
			max = arr[i];
	}
	int len = max - min + 1;
	int *count = (int*)malloc(len*sizeof(int));
	memset(count, 0, len*sizeof(int));
	int j = 0;
	for (i = 0; i < n; i++)
	{
		count[arr[i] - min]++;
	}
	for (i = 0, j = 0; i < len; i++)
	{
		while (count[i]--)
		{
			arr[j++] = i + min;
		}
	}
	free(count);
	count = NULL;
}
void Print(int arr[], int n)
{
	int i = 0;
	for (; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 3, 4, 4, 6, 1, 1, 2, 2, 4, 8, 9, 1, 5, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Countingsort(arr, n);
	Print(arr, n);

	return 0;
}