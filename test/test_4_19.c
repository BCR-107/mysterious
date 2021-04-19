#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Bucketsort(int arr[], int n)
{
	//初始化桶
	int bucket[2][5] = { 0 };
	int min = arr[0];
	int max = arr[0];
	int i = 0;
	//找最大最小值
	for (; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	//入桶
	int index0 = 0, index1 = 0;
	for (i = 0; i < n; i++){
		if (arr[i] < min + (max - min + 1) / 2 * 1 && index0 < 5){
			bucket[0][index0] = arr[i];
			index0++;
		}
		else if (arr[i] < min + (max - min + 1) / 2 * 2 && index1 < 5 || index0 >= 5) {
			bucket[1][index1] = arr[i];
			index1++;
		}
	}
	//排序
	int j = 0, flag = 1, tmp = 0, k = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0, flag = 1; j < 4 && flag; j++)
		{
			flag = 0;
			for (k = 0; k < 4 - j; k++)
			{
				if (bucket[i][k]>bucket[i][k + 1])
				{
					tmp = bucket[i][k];
					bucket[i][k] = bucket[i][k + 1];
					bucket[i][k + 1] = tmp;
					flag = 1;
				}
			}
		}
	}
	//还原
	for (i = 0; i < 2; i++){
		for (j = 0; j < 5; j++){
			arr[i * 5 + j] = bucket[i][j];
		}
	}
}
Print(int arr[], int n)
{
	int i = 0;
	for (; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 2, 31, 31, 2, 42, 67, 81, 73, 66, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Bucketsort(arr, n);
	Print(arr, n);

	return 0;
}