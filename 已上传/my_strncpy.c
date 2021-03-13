#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//my_strncpy
void my_strncpy(char*p1, const char*p2, int sz)
{
	while (sz && (*p1++ = *p2++))
	{
		sz--;
	}
	while (sz&&*p1)
	{
		*p1++ = '\0';
	}
	return p1;
}
int main()
{
	char arr1[10] = { "abcdefg" };
	char arr2[] = { "shuai" };
	my_strncpy(arr1, arr2, 2);
	printf("%s\n", arr1);

	return 0;
}
