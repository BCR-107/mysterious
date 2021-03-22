#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//指针数组 - 数组
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 2, 3, 4, 5, 6 };
//	int arr3[] = { 3, 4, 5, 6, 7 };
//
//	int* parr[] = { arr1, arr2, arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//数组指针 - 指针
//int main()
//{
//	//int arr[10] = {0};
//	//arr-首元素地址
//	//&arr[0]-首元素地址
//	//&arr-数组的地址
//	
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int(*p)[10] = &arr;//数组地址
//	//p是数组指针
//
//	return 0;
//}

//int main()
//{
//	//char* arr[5];
//	//char* (*pa)[5] = &arr;//
//	int arr[5];//
//	int *parr1[10];//指针数组,每个元素类型是int*
//	int (*parr2)[10];//数组指针,指向了一个数组,每个元素类型是int
//	int (*parr3[10])[5];//每个元素是一个数组指针,该数组指针指向的数组右5个元素,每个元素是int
//
//
//	return 0;
//}

//二维数组传参
//void test(int (*arr)[5])
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//}

//函数指针
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int x = 10;
//	int y = 20;
//	//printf("%d\n", Add(x, y));
//
//	int(*pa)(int, int) = Add;
//	printf("%d\n", pa(x, y));
//	return 0;
//}

//C陷阱和缺陷
//函数调用
//(*(void(*)())0)();//void(*)() - 函数指针类型  把0强制类型转换成void(*)()类型 0是函数地址 调用0地址处的该函数

//signal 是一个函数声明 
//有两个参数 第一个int，第二个是函数指针，函数指针指向的函数参数是int返回类型是void
//signal函数返回类型也是一个函数指针，该函数指针指向的函数参数是int返回类型是void

//void(*signal(int, void(*)(int)))(int);//函数声明

//简化
//typedef void(* pfun_t)(int) ;
//pfun_t signal( int, pfun_t );


////函数指针数组
//int ADD(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	//需要一个数组,可以存放4个函数地址
//	int(*pa)(int, int) = &ADD;//函数指针
//	int(*parr[4])(int, int) = { ADD, Sub, Mul, Div };//函数指针数组
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", parr[i](2, 3));
//	}
//	return 0;
//}

//char*my_strcpy(char*dest, const char*src);
//char*(*pf)(char*, const char*)
//char*(*pfArr[4])(char*, const char*)


//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Xor(int x, int y)
//{
//	return x ^ y;
//}
//
//void Calc(int(*pf)(int, int))
//{
//	//回调函数
//}
//
//void menu()
//{
//	printf("*********************************\n");
//	printf("***1,Add                2,Mul ***\n");
//	printf("***3,Mul                4,Div ***\n");
//	printf("***5,Xor                0,exit***\n");
//	printf("*********************************\n");
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0; 
//	int y = 0;
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数:>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("请输入两个操作数:>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("请输入两个操作数:>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	//函数指针数组
//	int(*pfarr[])(int, int) = { 0, Add, Sub, Mul, Div ,Xor};
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5)
//		{
//			printf("请输入两个操作数:>");
//			scanf("%d%d", &x, &y);
//			int ret = pfarr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//
//}


