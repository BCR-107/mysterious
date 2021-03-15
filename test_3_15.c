#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

//strerror(errno) - 打印错误信息

//realloc - 调整动态空间大小
//reslloc - 接在后面返回原地址/重开一个空间，拷贝原数据，释放原空间并返回新地址
//动态分配需进行返回值判断
//动态开辟不释放 - 会导致内存泄漏 - 疯狂开辟内存
//free 后 需指针置为空


//柔性数组 - C99 - 结构体中，最后一个元素，允许为未知大小成员  arr[] / arr[0]
//struct S
//{
//	int n;
//	int arr[0];//未知大小 - 柔性数组成员 -大小可变
//};
//int  main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//
//	return 0;
//}

//malloc 用的越多 内存碎片概率越高
//struct S
//{
//	int n;
//	int* arr;
//};
//int  main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	ps->arr = malloc(5 * sizeof(int));
//  
//	return 0;
//}

