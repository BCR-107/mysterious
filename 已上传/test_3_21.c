#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

//my_strcpy

//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;
//}

//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;//'\0'
//}

//void my_strcpy(char* dest, char* src)
//{
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//}

//void my_strcpy(char* dest, const char* src)
//{
//	if(dest != NULL && src != NULL)
//	{
//		while (*dest++ = *src++)
//		{
//			;
//		}
//	}
//}

//void my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);//����
//	assert(src != NULL);//����
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}

//char* my_strcpy(char* dest, const char* src)
//{
//	char*ret = dest;
//	assert(dest != NULL);//����
//	assert(src != NULL);//����
//  //��srcָ����ַ���������dest
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}

//int main()
//{
//	char arr1[] = { "################ "};
//	char arr2[] = { "nizhenshuai" };
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	//printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}

//int main()
//{
//	int num = 20;
//	const int *p = &num;
//	//const ����ָ����������ʱ�����ε���*p
//	//const ����ָ��������ұ�ʱ�����ε���p
//	*p = 10;//err  const ����ָ����������ʱ�����ε���*p
//	int * const p = &num;
//	*p - 10;
//	printf("%d\n", num);
//}

//my_strlen

//my_strlen(const char*str)
//{
//	int count = 0;
//	assert(str != NULL);//��ָ֤����Ч��
//
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//int main()
//{
//	char arr[] = { "abcdef" };
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//
//	return 0;
//}