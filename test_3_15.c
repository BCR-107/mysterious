#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

//strerror(errno) - ��ӡ������Ϣ

//realloc - ������̬�ռ��С
//reslloc - ���ں��淵��ԭ��ַ/�ؿ�һ���ռ䣬����ԭ���ݣ��ͷ�ԭ�ռ䲢�����µ�ַ
//��̬��������з���ֵ�ж�
//��̬���ٲ��ͷ� - �ᵼ���ڴ�й© - ��񿪱��ڴ�
//free �� ��ָ����Ϊ��


//�������� - C99 - �ṹ���У����һ��Ԫ�أ�����Ϊδ֪��С��Ա  arr[] / arr[0]
//struct S
//{
//	int n;
//	int arr[0];//δ֪��С - ���������Ա -��С�ɱ�
//};
//int  main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//
//	return 0;
//}

//malloc �õ�Խ�� �ڴ���Ƭ����Խ��
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

