#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
//We   Are   Happy.
//We%20Are%20Happy.
void ChTu(char* p)
{
	int s = 0;
	int n = 0;
	char* ps = p;
	while (*ps != '\0')
	{
		if (*ps++ == ' ')
		{
			s++;
		}
		n++;
	}
	int ns = n + s * 2;
	while (n >= 0 && ns > n)
	{
		if (p[n] != ' ')
		{
			p[ns--] = p[n--];
		}
		else
		{
			p[ns--] = '0';
			p[ns--] = '2';
			p[ns--] = '%';
			n--;
		}
	}
}
int main()
{
	char arr[30] = { " hello " };
	ChTu(arr);
	puts(arr);
	return 0;
}