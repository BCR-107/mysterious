#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>

//issupper - 判断是否是大写字母
//islower  - 是否是小写字母
//isalpha  - 是否是字母
//isalnum  - 是否是字母或数字

//tolower  - 大写转小写
//toupper  - 小写转大写

//内存函数
//memcpy  - 内存拷贝(无法处理内存重叠)   void *memcpy( void *dest, const void *src, size_t count );
//memmove - 处理内存重叠拷贝  (需看库函数实现方法)
//memcmp  - 内存比较
//memset  - 内存设置


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
//		//前 -> 后
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
//		//后 -> 前
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


//memcmp - 内存比较
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 1, 2, 5, 4, 3 };
//	int ret = memcmp(arr1, arr2,8);
//	printf("%d\n", ret);
//
//	return 0;
//}

//memset - 内存设置 - void *memset( void *dest, int c, size_t count );
//int main()
//{
//	char arr[10];
//	memset(arr, '0', 10);
//
//	return 0;
//}

//结构体内存对齐
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
////设置默认对齐数为4
//
//#pragma pack()
////取消设置的默认对齐数


#include<stddef.h>
struct S
{
	char c;//0
	int i;//4
	double d;//8
};
int main()
{
	//offsetof();//宏     计算结构体偏移量
	printf("%d\n", offsetof(struct S, c));
	printf("%d\n", offsetof(struct S, i));
	printf("%d\n", offsetof(struct S, d));

	return 0;
}


//位段 - 节省空间    位 - 二进制位
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


//枚举   看优点
//联合(共用体)

//大小端
//int check_sys()
//{
//	union un
//	{
//		char c;
//		int i;
//	}u;
//
//	u.i = 1;
//	//1 小端
//	//0 大端
//	return u.c;
//}
//int main()
//{
//	int ret = check_sys();
//
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	return 0;
//}



