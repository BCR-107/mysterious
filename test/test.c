#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>

//issupper - �ж��Ƿ��Ǵ�д��ĸ
//islower  - �Ƿ���Сд��ĸ
//isalpha  - �Ƿ�����ĸ
//isalnum  - �Ƿ�����ĸ������

//tolower  - ��дתСд
//toupper  - Сдת��д

//�ڴ溯��
//memcpy  - �ڴ濽��(�޷������ڴ��ص�)   void *memcpy( void *dest, const void *src, size_t count );
//memmove - �����ڴ��ص�����  (�迴�⺯��ʵ�ַ���)
//memcmp  - �ڴ�Ƚ�
//memset  - �ڴ�����


//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}
//
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	if (dest < src)
//	{
//		//ǰ -> ��
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//		return ret;
//	}
//	else
//	{
//		//�� -> ǰ
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//		return ret;
//	}
//
//}
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int arr2[] = { 0 };
//	//my_memcpy(arr2, arr1, sizeof(arr1));
//	my_memmove(arr1 + 2, arr1, 20);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//
//	return 0;
//}


//memcmp - �ڴ�Ƚ�
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 1, 2, 5, 4, 3 };
//	int ret = memcmp(arr1, arr2,8);
//	printf("%d\n", ret);
//
//	return 0;
//}

//memset - �ڴ����� - void *memset( void *dest, int c, size_t count );
//int main()
//{
//	char arr[10];
//	memset(arr, '0', 10);
//
//	return 0;
//}

//�ṹ���ڴ����
//struct s1
//{
//	char c1;
//	int a;
//	char c2;
//
//};
//
//struct s2
//{
//	char c1;
//	char c2;
//	int a;
//};
//int main()
//{
//	struct s1 s1 = { 0 };
//	printf("%d\n", sizeof(s1));//
//	struct s2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));//
//
//	return 0;
//}


//#pragma pack(4)
////����Ĭ�϶�����Ϊ4
//
//#pragma pack()
////ȡ�����õ�Ĭ�϶�����


#include<stddef.h>
struct S
{
	char c;//0
	int i;//4
	double d;//8
};
int main()
{
	//offsetof();//��     ����ṹ��ƫ����
	printf("%d\n", offsetof(struct S, c));
	printf("%d\n", offsetof(struct S, i));
	printf("%d\n", offsetof(struct S, d));

	return 0;
}


//λ�� - ��ʡ�ռ�    λ - ������λ
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//int main()
//{
//	struct A a;
//	printf("%d\n", sizeof(a));//8
//	
//	return 0;
//}


//ö��   ���ŵ�
//����(������)

//��С��
//int check_sys()
//{
//	union un
//	{
//		char c;
//		int i;
//	}u;
//
//	u.i = 1;
//	//1 С��
//	//0 ���
//	return u.c;
//}
//int main()
//{
//	int ret = check_sys();
//
//	if (ret == 1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//
//	return 0;
//}



