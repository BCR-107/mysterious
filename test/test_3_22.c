#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//ָ������ - ����
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

//����ָ�� - ָ��
//int main()
//{
//	//int arr[10] = {0};
//	//arr-��Ԫ�ص�ַ
//	//&arr[0]-��Ԫ�ص�ַ
//	//&arr-����ĵ�ַ
//	
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int(*p)[10] = &arr;//�����ַ
//	//p������ָ��
//
//	return 0;
//}

//int main()
//{
//	//char* arr[5];
//	//char* (*pa)[5] = &arr;//
//	int arr[5];//
//	int *parr1[10];//ָ������,ÿ��Ԫ��������int*
//	int (*parr2)[10];//����ָ��,ָ����һ������,ÿ��Ԫ��������int
//	int (*parr3[10])[5];//ÿ��Ԫ����һ������ָ��,������ָ��ָ���������5��Ԫ��,ÿ��Ԫ����int
//
//
//	return 0;
//}

//��ά���鴫��
//void test(int (*arr)[5])
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//}

//����ָ��
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

//C�����ȱ��
//��������
//(*(void(*)())0)();//void(*)() - ����ָ������  ��0ǿ������ת����void(*)()���� 0�Ǻ�����ַ ����0��ַ���ĸú���

//signal ��һ���������� 
//���������� ��һ��int���ڶ����Ǻ���ָ�룬����ָ��ָ��ĺ���������int����������void
//signal������������Ҳ��һ������ָ�룬�ú���ָ��ָ��ĺ���������int����������void

//void(*signal(int, void(*)(int)))(int);//��������

//��
//typedef void(* pfun_t)(int) ;
//pfun_t signal( int, pfun_t );


////����ָ������
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
//	//��Ҫһ������,���Դ��4��������ַ
//	int(*pa)(int, int) = &ADD;//����ָ��
//	int(*parr[4])(int, int) = { ADD, Sub, Mul, Div };//����ָ������
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
//	//�ص�����
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
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			printf("����������������:>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("����������������:>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("����������������:>");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("�˳�\n");
//			break;
//		default:
//			printf("ѡ�����\n");
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
//	//����ָ������
//	int(*pfarr[])(int, int) = { 0, Add, Sub, Mul, Div ,Xor};
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 5)
//		{
//			printf("����������������:>");
//			scanf("%d%d", &x, &y);
//			int ret = pfarr[input](x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�\n");
//		}
//		else
//		{
//			printf("ѡ�����\n");
//		}
//	} while (input);
//
//}


