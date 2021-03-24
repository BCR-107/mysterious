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
//	assert(dest != NULL);//断言
//	assert(src != NULL);//断言
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}

//char* my_strcpy(char* dest, const char* src)
//{
//	char*ret = dest;
//	assert(dest != NULL);//断言
//	assert(src != NULL);//断言
//  //把src指向的字符串拷贝到dest
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
//	//const 放在指针变脸的左边时，修饰的是*p
//	//const 放在指针变脸的右边时，修饰的是p
//	*p = 10;//err  const 放在指针变脸的左边时，修饰的是*p
//	int * const p = &num;
//	*p - 10;
//	printf("%d\n", num);
//}

//my_strlen

//my_strlen(const char*str)
//{
//	int count = 0;
//	assert(str != NULL);//保证指针有效性
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